/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:26:36 by stephane          #+#    #+#             */
/*   Updated: 2024/01/14 04:55:59 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline t_round	compute_round(t_float128 nbr, int precision)
{
	t_round	round;
	int		digit;
	int		i;

	round.nbr_digit = 0;
	round.intpart = nbr >= 0.5;
	round.decpart = 0;
	if (precision == 0)
		return (round);
	i = precision;
	while (i--)
	{
		nbr *= 10;
		digit = (int)nbr;
		nbr -= digit;
		if (digit < 9)
			round.nbr_digit = 0;
		else
			round.nbr_digit++;
	}
	round.decpart = nbr >= 0.5;
	round.intpart = round.decpart && round.nbr_digit == precision;
	if (round.decpart == 0)
		round.nbr_digit = 0;
	return (round);
}

static inline t_float64	integer_to_buffer(t_float128 nbr, int power10, \
						t_buffer *buffer)
{
	int			digit;
	t_float128	mul;

	mul = vs_10pow(power10);
	while (power10--)
	{
		digit = (int)(nbr / mul);
		buffer_add_char(buffer, digit + '0', 1);
		nbr -= (digit * mul);
		if (power10 == 21)
			mul = 10e21L;
		mul /= 10;
	}
	digit = nbr;
	buffer_add_char(buffer, digit + '0', 1);
	nbr -= digit;
	return (nbr);
}

static inline void	decimal_to_buffer(t_float128 nbr, int precision, \
					t_round round, t_buffer *buffer)
{
	int	digit;

	precision -= round.nbr_digit;
	while (precision--)
	{
		nbr *= 10;
		digit = (int)nbr;
		nbr -= digit;
		if (precision == 0)
			buffer_add_char(buffer, digit + (nbr >= 0.5) + '0', 1);
		else
			buffer_add_char(buffer, digit + '0', 1);
	}
	if (round.nbr_digit)
		buffer_add_char(buffer, '0', round.nbr_digit);
}

static inline void	double_to_buffer(t_float64 nbr, t_spec *spec, \
					t_buffer *buffer)
{
	t_ui16		nbr_digit_int;
	t_round		round;
	t_float64	decimal;

	nbr_digit_int = nbr_digit_float64_integer_part(nbr);
	decimal = float64_get_decimal_part(nbr);
	round = compute_round(decimal, spec->precision);
	field_compute_empty_float(spec, nbr_digit_int);
	field_empty_before_to_buffer(spec, buffer);
	integer_to_buffer(nbr + round.intpart, nbr_digit_int - 1, buffer);
	if (spec->precision > 0 || spec->flag_hash)
		buffer_add_char(buffer, '.', 1);
	decimal_to_buffer(decimal, spec->precision, round, buffer);
	field_empty_after_to_buffer(spec, buffer);
}

int	format_f(t_float64 nbr, t_spec *spec, t_buffer *buffer)
{
	if (float64_get_sign(nbr) == NEGATIVE)
	{
		spec->prefix = '-';
		nbr *= -1.0;
	}
	if (float64_get_exponent(nbr) == FLOAT_MAX_EXPONENT)
	{
		if (float64_get_mantissa(nbr))
			return (format_s_float("nan", spec, buffer));
		return (format_s_float("inf", spec, buffer));
	}
	if (spec->precision == -1)
		spec->precision = 6;
	double_to_buffer(nbr, spec, buffer);
	return (1);
}
