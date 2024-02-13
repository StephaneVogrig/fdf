/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:14:41 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/13 09:34:33 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_hor(t_img *img, t_point2d a, t_point2d b)
{
	int	x;
	int	end;

	x = si32_min(a.x, b.x);
	end = si32_max(a.x, b.x);
	while (x <= end)
		img_set_pixel(img, x++, a.y, a.color);
}

void	draw_line_diag(t_img *img, t_point2d a, t_point2d b)
{
	int	dx;
	int	dy;

	if (a.x < b.x)
		dx = 1;
	else
		dx = -1;
	if (a.y < b.y)
		dy = 1;
	else
		dy = -1;
	while (a.x != b.x)
	{
		a.x += dx;
		a.y += dy;
		img_set_pixel(img, a.x, a.y, a.color);
	}
}

void	draw_line_vert(t_img *img, t_point2d a, t_point2d b)
{
	int	y;
	int	end;

	y = si32_min(a.y, b.y);
	end = si32_max(a.y, b.y);
	while (y <= end)
		img_set_pixel(img, a.x, y++, a.color);
}

void	draw_line_oblique(t_img *img, t_point2d a, t_point2d b, t_vec2i d)
{
	t_vec2i	abs_d;

	abs_d.x = abs(d.x);
	abs_d.y = abs(d.y);
	if (abs_d.x == abs_d.y)
		draw_line_diag(img, a, b);
	else if (abs_d.y < abs_d.x)
	{
		if (a.x < b.x)
			draw_line_bresenham_x(img, a, b, abs_d);
		else
			draw_line_bresenham_x(img, b, a, abs_d);
	}
	else
	{
		if (a.y < b.y)
			draw_line_bresenham_y(img, a, b, abs_d);
		else
			draw_line_bresenham_y(img, b, a, abs_d);
	}
}

void	draw_line(t_img *img, t_point2d a, t_point2d b)
{
	t_vec2i	d;

	if (a.x >= img->width && b.x >= img->width || a.x < 0 && b.x < 0)
		return ;
	if (a.y >= img->height && b.y >= img->height || a.y < 0 && b.y < 0)
		return ;
	// ft_printf("ax:%i, ay:%i, bx:%i, by:%i\n", a.x, a.y, b.x, b.y);
	if (a.x == b.x)
		draw_line_vert(img, a, b);
	else if (a.y == b.y)
		draw_line_hor(img, a, b);
	else
	{
		d.x = b.x - a.x;
		d.y = b.y - a.y;
		draw_line_oblique(img, a, b, d);
	}
}
