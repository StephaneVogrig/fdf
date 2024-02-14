/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:31:11 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/14 10:39:59 by svogrig          ###   ########.fr       */
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

t_gradiant	color_gradiant(t_ui32 start, t_ui32 end, t_vec2i d)
{
	t_gradiant	grad;
	t_color		color_end;
	t_color		color_start;
	t_float32	ratio;

	if (start == end || (!d.x && !d.y))
		return (grad);
	grad.gradiant = vector3f(0.0, 0.0, 0.0);
	grad.accu = vector3f(0.0, 0.0, 0.0);
	color_start.argb = start;
	grad.start = color_start;
	color_end.argb = end;
	if (ft_abs(d.x) > ft_abs(d.y))
		ratio = 1.0 / d.x;
	else
		ratio = 1.0 / d.y;
	grad.gradiant.x = (color_end.r - color_start.r) * ratio;
	grad.gradiant.y = (color_end.g - color_start.g) * ratio;
	grad.gradiant.z = (color_end.b - color_start.b) * ratio;
	return (grad);
}

t_ui32 color_gradiant_add(t_gradiant *grad)
{
	t_color	result;
	t_color	start;

	result.r = grad->start.r + round(grad->accu.x);
	result.g = grad->start.g + round(grad->accu.y);
	result.b = grad->start.b + round(grad->accu.z);
	grad->accu.x += grad->gradiant.x;
	grad->accu.y += grad->gradiant.y;
	grad->accu.z += grad->gradiant.z;
	return (result.argb);
}







t_vec3f	color_gradient(t_ui32 start, t_ui32 end, t_vec2i d)
{
	t_vec3f		g_color;
	t_float32	ratio;
	t_color		color_end;
	t_color		color_start;

	if (start == end)
		return (vector3f(0.0, 0.0, 0.0));
	if (!d.x && !d.y)
		return (vector3f(0.0, 0.0, 0.0));
	color_start.argb = start;
	color_end.argb = end;
	if (ft_abs(d.x) > ft_abs(d.y))
		ratio = 1.0 / d.x;
	else
		ratio = 1.0 / d.y;
	g_color.x = (color_end.r - color_start.r) * ratio;
	g_color.y = (color_end.g - color_start.g) * ratio;
	g_color.z = (color_end.b - color_start.b) * ratio;
	return (g_color);
}

t_ui32 color_gradient_add(t_ui32 color, t_vec3f color_grad, t_vec3f *add)
{
	t_color	result;
	t_color	start;

	start.argb = color;
	result.r = start.r + round(add->x);
	result.g = start.g + round(add->y);
	result.b = start.b + round(add->z);
	add->x += color_grad.x;
	add->y += color_grad.y;
	add->z += color_grad.z;
	return (result.argb);
}
