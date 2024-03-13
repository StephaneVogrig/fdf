/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:37:29 by svogrig           #+#    #+#             */
/*   Updated: 2023/12/21 13:42:13 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_c(char c, t_spec *spec, t_buffer *buffer)
{
	if (spec->width > 1 && !spec->flag_minus)
		buffer_add_char(buffer, ' ', spec->width - 1);
	buffer_add_char(buffer, c, 1);
	if (spec->width > 1 && spec->flag_minus)
		buffer_add_char(buffer, ' ', spec->width - 1);
	return (1);
}
