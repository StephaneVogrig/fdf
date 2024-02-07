/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:20:44 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/12 19:24:15 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_p_nil(t_spec *spec, t_buffer *buffer)
{
	if (spec->width > LEN_NIL && !spec->flag_minus)
		buffer_add_char(buffer, ' ', spec->width - LEN_NIL);
	buffer_add_str(buffer, "(nil)", LEN_NIL);
	if (spec->width > LEN_NIL && spec->flag_minus)
		buffer_add_char(buffer, ' ', spec->width - LEN_NIL);
	return (1);
}

int	format_p(void *p, t_spec *spec, t_buffer *buffer)
{
	if (!p)
		return (format_p_nil(spec, buffer));
	spec->flag_hash = TRUE;
	return (format_x((t_ui64)p, spec, buffer));
}
