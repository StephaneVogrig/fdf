/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:12:00 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/22 21:27:25 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_color	col_grad_step(t_grad grad, int step)
{
	t_color	color;

	color.r = round(grad.accu.x + grad.gradiant.x * step);
	color.g = round(grad.accu.y + grad.gradiant.y * step);
	color.b = round(grad.accu.z + grad.gradiant.z * step);
	return (color);
}

t_grad	grad_step(t_ui32 start, t_ui32 end, int step)
{
	t_grad		grad;
	t_float32	ratio;
	t_color		color;

	if (step == 0)
		step = 1;
	color.ui = start;
	grad.accu.x = color.r;
	grad.accu.y = color.g;
	grad.accu.z = color.b;
	step = ft_abs(step);
	color.ui = end;
	grad.gradiant.x = (color.r - grad.accu.x) / step;
	grad.gradiant.y = (color.g - grad.accu.y) / step;
	grad.gradiant.z = (color.b - grad.accu.z) / step;
	return (grad);
}

t_color	earth(t_multigrad grad, int z, int z_max)
{
	t_color	color;

	if (z < 0)
		color = col_grad_step(grad.a, -z);
	else if (z == 0)
		color = col_grad_step(grad.a, 1);
	else if (z <= (z_max * 0.2))
		color = col_grad_step(grad.b, z);
	else if (z <= (z_max * 0.59))
		color = col_grad_step(grad.c, z);
	else
		color.ui = 0xffffff;
	return (color);
}
