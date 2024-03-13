/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:22:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/18 19:37:19 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline t_ui64	arg_to_ui64(va_list args, t_spec *spec)
{
	if (spec->length[0] == 'l')
	{
		if (spec->length[1] == 'l')
			return (va_arg(args, unsigned long long));
		return ((t_ui64)va_arg(args, unsigned long));
	}
	return ((t_ui64)va_arg(args, unsigned int));
}

static inline t_si64	arg_to_i64(va_list args, t_spec *spec)
{
	int	arg;

	if (spec->length[0] == 'l')
	{
		if (spec->length[1] == 'l')
			return (va_arg(args, long long int));
		return ((t_si64)va_arg(args, long int));
	}
	arg = va_arg(args, int);
	if (arg == INT_MIN)
		return (INT_MIN);
	if (arg < 0)
		return (-(t_si64)(-arg));
	return ((t_si64)arg);
}

static int	parse_conversion(char c, va_list args, t_spec *spec, \
			t_buffer *buffer)
{
	if (c == 'c')
		return (format_c(va_arg(args, int), spec, buffer));
	else if (c == 's')
		return (format_s(va_arg(args, char *), spec, buffer));
	else if (c == '%')
		return (format_purcent(buffer));
	else if (c == 'p')
		return (format_p(va_arg(args, void *), spec, buffer));
	else if (c == 'i' || c == 'd')
		return (format_i(arg_to_i64(args, spec), spec, buffer));
	else if (c == 'u')
		return (format_u(arg_to_ui64(args, spec), spec, buffer));
	else if (c == 'f')
		return (format_f(va_arg(args, t_float64), spec, buffer));
	else if (c == 'x')
		return (format_x(arg_to_ui64(args, spec), spec, buffer));
	else if (c == 'X')
		return (format_xupper(arg_to_ui64(args, spec), spec, buffer));
	return (0);
}

const char	*parse_arg(const char *format, t_buffer *buffer, va_list args, \
			int *spec_errors)
{
	t_spec	spec;

	format = set_flags(format, &spec);
	format = set_widthfield(format, &spec, args);
	if (!format)
		return (NULL);
	format = set_precision(format, &spec, args);
	if (!format)
		return (NULL);
	format = set_length(format, &spec);
	if ((*format == '\0') && (*spec_errors == 0))
		return (NULL);
	if (parse_conversion(*format, args, &spec, buffer))
		return (++format);
	*spec_errors += buffer_add_spec(buffer, &spec);
	return (format);
}
