/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 07:21:44 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/25 02:07:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_img.h"

void	bresenloop(t_fdf_img *img, t_pixel a, t_pixel b, t_bresenham bres)
{
	int		err;
	int		e2;
	t_grad	gradiant;

	gradiant = color_gradiant(a.color, b.color, vector2i_sub(b.vec, a.vec));
	err = bres.dx + bres.dy;
	while (a.x != b.x || a.y != b.y)
	{
		e2 = err << 1;
		if (e2 >= bres.dy)
		{
			err += bres.dy;
			a.x += bres.sx;
		}
		else if (e2 <= bres.dx)
		{
			err += bres.dx;
			a.y += bres.sy;
		}
		if (a.color.ui != b.color.ui)
			a.color = color_gradiant_add(&gradiant);
		img_set_pixel(img, a.x, a.y, a.color);
	}
}

inline void	bresenham(t_fdf_img *img, t_pixel a, t_pixel b, t_vec2i abs_d)
{
	t_bresenham	bres;

	bres.dx = abs_d.x;
	bres.dy = -abs_d.y;
	if (a.x < b.x)
		bres.sx = 1;
	else
		bres.sx = -1;
	if (a.y < b.y)
		bres.sy = 1;
	else
		bres.sy = -1;
	bresenloop(img, a, b, bres);
}
