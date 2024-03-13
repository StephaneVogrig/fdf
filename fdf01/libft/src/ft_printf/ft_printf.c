/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:00:52 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/12 18:05:47 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_buffer	buffer;
	ssize_t		writed;
	int			spec_errors;

	spec_errors = 0;
	buffer.offset = 0;
	buffer.writed = 0;
	va_start(args, format);
	while (format && *format)
	{
		while (*format && *format != '%')
			buffer_add_char(&buffer, *format++, 1);
		if (*format == '%')
			format = parse_arg(format + 1, &buffer, args, &spec_errors);
	}
	va_end(args);
	writed = buffer_print(buffer);
	if (!format)
		return (-1);
	return (writed);
}
