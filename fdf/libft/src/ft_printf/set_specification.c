/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_specification.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:10:29 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/14 07:17:30 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// set prefix only based on flags '+' and '-'
inline void	set_prefix(t_spec *spec)
{
	if (spec->flag_plus)
		spec->prefix = '+';
	else if (spec->flag_space)
		spec->prefix = ' ';
	else
		spec->prefix = '\0';
}

const char	*set_flags(const char *format, t_spec *spec)
{
	spec->flags = FALSE;
	while (*format)
	{
		if (*format == '#')
			spec->flag_hash = TRUE;
		else if (*format == '0')
			spec->flag_zero = TRUE;
		else if (*format == '-')
			spec->flag_minus = TRUE;
		else if (*format == ' ')
			spec->flag_space = TRUE;
		else if (*format == '+')
			spec->flag_plus = TRUE;
		else
			break ;
		format++;
	}
	spec->left_align = (spec->flag_minus == 1);
	spec->right_align = (spec->flag_minus == 0);
	set_prefix(spec);
	return (format);
}

const char	*set_widthfield(const char *format, t_spec *spec, va_list args)
{
	spec->width = -1;
	if (*format == '*')
	{
		spec->width = va_arg(args, int);
		if (spec->width < 0)
		{
			spec->flag_minus = 1;
			spec->left_align = TRUE;
			spec->right_align = FALSE;
			spec->width = -spec->width;
		}
		return (++format);
	}
	return (spec_str_to_int((char *)format, &spec->width));
}

const char	*set_precision(const char *format, t_spec *spec, va_list args)
{
	spec->precision = -1;
	if (*format != '.')
		return (format);
	format++;
	if (*format == '*')
	{
		spec->precision = va_arg(args, int);
		if (spec->precision < 0)
			spec->precision = -1;
		return (++format);
	}
	spec->precision = 0;
	return (spec_str_to_int((char *)format, &spec->precision));
}

const char	*set_length(const char *format, t_spec *spec)
{
	spec->length[0] = 0;
	spec->length[1] = 0;
	if (*format == 'l')
	{
		spec->length[0] = *format++;
		if (*format == 'l')
			spec->length[1] = *format++;
	}
	else if (*format == 'h')
	{
		spec->length[0] = *format++;
		if (*format == 'h')
			spec->length[1] = *format++;
	}
	return (format);
}
