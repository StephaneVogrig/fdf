/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 04:54:23 by stephane          #+#    #+#             */
/*   Updated: 2024/01/12 20:23:18 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// if flag hash is present, the result always contain a decimal point,
// even if no digit follow.
void	field_compute_empty_float(t_spec *spec, int nbr_digit_int)
{
	if (spec->prefix)
		spec->width--;
	spec->width -= nbr_digit_int;
	if (spec->precision > 0 || spec->flag_hash)
		spec->width--;
	if (spec->precision > 0)
		spec->width -= spec->precision;
	if (spec->width < 0)
		spec->width = 0;
}

void	field_compute_empty_integer(t_spec *spec, int nbr_digit_int)
{
	spec->width -= nbr_digit_int + spec->precision;
	if (spec->prefix == 'x' || spec->prefix == 'X')
		spec->width -= 2;
	else if (spec->prefix != '\0')
		spec->width -= 1;
	if (spec->width < 0)
		spec->width = 0;
}

void	field_empty_before_to_buffer(t_spec *spec, t_buffer *buffer)
{
	if (spec->right_align && spec->width && !spec->flag_zero)
		buffer_add_char(buffer, ' ', spec->width);
	if (spec->prefix)
		prefixe_to_buffer(buffer, spec->prefix);
	if (spec->right_align && spec->width && spec->flag_zero)
		buffer_add_char(buffer, '0', spec->width);
}

void	field_empty_after_to_buffer(t_spec *spec, t_buffer *buffer)
{
	if (spec->left_align && spec->width)
		buffer_add_char(buffer, ' ', spec->width);
}
