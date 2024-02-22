/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 07:21:44 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/21 22:06:44 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

inline void	draw_line_bresenham_x(t_fdf_img *img, t_pixel a, t_pixel b, t_vec2i d)
{
	int			i;
	int			err;
	t_gradiant	gradiant;
// ft_printf("    enter draw bres x\n");

	gradiant = color_gradiant(a.color, b.color, d);
	if (a.y > b.y)
		i = -1;
	else
		i = 1;
	d.y <<= 1;
	err = d.y - d.x;
	d.x <<= 1;
	while (a.x < b.x)
	{
		a.x++;
		err += d.y;
		if (err > 0)
		{
			a.y += i;
			err -= d.x;
		}
		if (a.color.ui != b.color.ui)
			a.color = color_gradiant_add(&gradiant);
		img_set_pixel(img, a.x, a.y, a.color);
		// img_set_pixel(img, a.x, a.y, color(0, 255, 0, 0));
	}
}

inline void	draw_line_bresenham_y(t_fdf_img *img, t_pixel a, t_pixel b, t_vec2i d)
{
	int	i;
	int	err;
	t_gradiant	gradiant;
// ft_printf("    enter draw bres y\n");

	gradiant = color_gradiant(a.color, b.color, d);
	if (a.x > b.x)
		i = -1;
	else
		i = 1;
	d.x <<= 1;
	err = d.x - d.y;
	d.y <<= 1;
		
	while (a.y < b.y)
	{
		a.y++;
		err += d.x;
		if (err > 0)
		{
			a.x += i;
			err -= d.y;
		}
		if (a.color.ui != b.color.ui)
			a.color = color_gradiant_add(&gradiant);
		img_set_pixel(img, a.x, a.y, a.color);
		// img_set_pixel(img, a.x, a.y, color(0, 255, 0, 0));
	}
}
