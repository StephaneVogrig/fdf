/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:31:11 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/21 04:01:35 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

inline t_color	color(t_ui8 a, t_ui8 r, t_ui8 g, t_ui8 b)
{
	t_color	color;

	color.a = a;
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

inline t_gradiant	color_gradiant(t_color start, t_color end, t_vec2i d)
{
	t_gradiant	grad;
	t_float32	ratio;

	grad.accu.x = start.r;
	grad.accu.y = start.g;
	grad.accu.z = start.b;
	grad.gradiant = vector3f(0.0, 0.0, 0.0);
	if (start.ui == end.ui || (!d.x && !d.y))
		return (grad);
	d.x = ft_abs(d.x);
	d.y = ft_abs(d.y);
	ratio = 1.0 / si32_max(d.x, d.y);
	grad.gradiant.x = (end.r - start.r) * ratio;
	grad.gradiant.y = (end.g - start.g) * ratio;
	grad.gradiant.z = (end.b - start.b) * ratio;
	return (grad);
}
inline t_color	color_gradiant_add(t_gradiant *grad)
{
	t_color	result;

	grad->accu.x += grad->gradiant.x;
	grad->accu.y += grad->gradiant.y;
	grad->accu.z += grad->gradiant.z;
	result.r = round(grad->accu.x);
	result.g = round(grad->accu.y);
	result.b = round(grad->accu.z);
	return (result);
}