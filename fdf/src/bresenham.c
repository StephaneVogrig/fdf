/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 07:21:44 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/14 01:04:35 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_bresenham_x(t_img *img, t_pixel a, t_pixel b, t_vec2i d)
{
	int	i;
	int	err;

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
		img_set_pixel(img, a.x, a.y, a.color);
	}
}

void	draw_line_bresenham_y(t_img *img, t_pixel a, t_pixel b, t_vec2i d)
{
	int	i;
	int	err;

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
		img_set_pixel(img, a.x, a.y, a.color);
	}
}

typedef struct s_bresenham {
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}	t_bresenham;

inline void	bresenham_2(t_img *img, t_pixel a, t_pixel b, t_bresenham var)
{
	int	err;
	int	e2;

	err = var.dx + var.dy;
	while (a.x != b.x || a.y != b.y)
	{
		e2 = err << 1;
		if (e2 >= var.dy)
		{
			err += var.dy;
			a.x += var.sx;
		}
		if (e2 <= var.dx)
		{
			err += var.dx;
			a.y += var.sy;
		}
		img_set_pixel(img, a.x, a.y, a.color);
	}
}

void	bresenham(t_img *img, t_pixel a, t_pixel b)
{
	t_bresenham	var;

	var.dx = ft_abs(b.x - a.x);
	var.dy = -ft_abs(b.y - a.y);
	if (a.x < b.x)
		var.sx = 1;
	else
		var.sx = -1;
	if (a.y < b.y)
		var.sy = 1;
	else
		var.sy = -1;
	bresenham_2(img, a, b, var);
}
