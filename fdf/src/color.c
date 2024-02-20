/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:31:11 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/20 17:46:41 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

inline t_ui32	color(t_ui8 a, t_ui8 r, t_ui8 g, t_ui8 b)
{
	t_color	color;

	color.a = a;
	color.r = r;
	color.g = g;
	color.b = b;
	return (color.argb);
}

inline t_gradiant	color_gradiant(t_ui32 start, t_ui32 end, t_vec2i d)
{
	t_gradiant	grad;
	t_color		color_end;
	t_color		color_start;
	t_float32	ratio;

	grad.gradiant = vector3f(0.0, 0.0, 0.0);
	color_start.argb = start;
	grad.start = color_start;
	grad.accu = vector3f(0.0, 0.0, 0.0);
	if (start == end || (!d.x && !d.y))
		return (grad);
	color_end.argb = end;
	d.x = ft_abs(d.x);
	d.y = ft_abs(d.y);
	ratio = 1.0 / si32_max(d.x, d.y);
	grad.accu.x = color_start.r;
	grad.accu.y = color_start.g;
	grad.accu.z = color_start.b;
	grad.gradiant.x = (color_end.r - color_start.r) * ratio;
	grad.gradiant.y = (color_end.g - color_start.g) * ratio;
	grad.gradiant.z = (color_end.b - color_start.b) * ratio;
	return (grad);
}

t_ui32 color_gradiant_add(t_gradiant *grad)
{
	t_color	result;

	grad->accu.x += grad->gradiant.x;
	grad->accu.y += grad->gradiant.y;
	grad->accu.z += grad->gradiant.z;
	result.r = round(grad->accu.x);
	result.g = round(grad->accu.y);
	result.b = round(grad->accu.z);

	return (result.argb);
}
