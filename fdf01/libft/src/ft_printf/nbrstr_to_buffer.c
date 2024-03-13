/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrstr_to_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:16:42 by stephane          #+#    #+#             */
/*   Updated: 2024/01/12 19:39:10 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prefixe_to_buffer(t_buffer *buffer, char prefixe)
{
	if (prefixe == 'x')
		buffer_add_str(buffer, "0x", 2);
	else if (prefixe == 'X')
		buffer_add_str(buffer, "0X", 2);
	else if (prefixe)
		buffer_add_char(buffer, prefixe, 1);
}

static void	precision_compute(t_spec *spec, int nbr_digit_int)
{
	if (spec->precision > nbr_digit_int)
		spec->precision -= nbr_digit_int;
	else
		spec->precision = 0;
}

void	nbrstr_to_buffer(t_buffer *buffer, t_spec *spec, t_nbrstr *nbrstr)
{
	if (spec->precision > -1)
		spec->flag_zero = 0;
	if (nbrstr->is_zero && spec->precision == 0)
		nbrstr->nbr_digit = 0;
	precision_compute(spec, nbrstr->nbr_digit);
	field_compute_empty_integer(spec, nbrstr->nbr_digit);
	field_empty_before_to_buffer(spec, buffer);
	if (spec->precision)
		buffer_add_char(buffer, '0', spec->precision);
	buffer_add_str(buffer, nbrstr->str, nbrstr->nbr_digit);
	field_empty_after_to_buffer(spec, buffer);
}
