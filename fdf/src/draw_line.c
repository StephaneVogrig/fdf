/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:14:41 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/14 12:03:00 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_hor(t_img *img, t_pixel a, t_pixel b)
{
	int	x;
	int	end;
	t_gradiant	gradiant;

	x = si32_min(a.x, b.x);
	end = si32_max(a.x, b.x);
	gradiant = color_gradiant(a.color, b.color, vector2i_sub(b.vec2i, a.vec2i));
	while (x <= end)
	{
		if (a.color != b.color)
			a.color = color_gradiant_add(&gradiant);
		img_set_pixel(img, x++, a.y, a.color);
	}
}

void	draw_line_diag(t_img *img, t_pixel a, t_pixel b)
{
	t_vec2i	d;
	t_gradiant	gradiant;

	if (a.x < b.x)
		d.x = 1;
	else
		d.x = -1;
	if (a.y < b.y)
		d.y = 1;
	else
		d.y = -1;
	gradiant = color_gradiant(a.color, b.color, vector2i_sub(b.vec2i, a.vec2i));
	while (a.x != b.x)
	{
		a.x += d.x;
		a.y += d.y;
		if (a.color != b.color)
			a.color = color_gradiant_add(&gradiant);
		img_set_pixel(img, a.x, a.y, a.color );
	}
}

void	draw_line_vert(t_img *img, t_pixel a, t_pixel b)
{
	int	y;
	int	end;
	t_gradiant	gradiant;

	gradiant = color_gradiant(a.color, b.color, vector2i_sub(b.vec2i, a.vec2i));
	y = si32_min(a.y, b.y);
	end = si32_max(a.y, b.y);
	while (y <= end)
	{
		if (a.color != b.color)
			a.color = color_gradiant_add(&gradiant);
		img_set_pixel(img, a.x, y++, a.color);
	}
}

void	draw_line_oblique(t_img *img, t_pixel a, t_pixel b, t_vec2i d)
{
	t_vec2i	abs_d;

	abs_d.x = ft_abs(d.x);
	abs_d.y = ft_abs(d.y);
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
	
	// else
	// 	bresenham(img, a, b, abs_d);
}

void	draw_line(t_img *img, t_pixel a, t_pixel b)
{
	t_vec2i	d;
	t_vec3f	g_color;

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
	d = vector2i_sub(b.vec2i, a.vec2i);
	// g_color = color_gradient(a.color, b.color, d);
		draw_line_oblique(img, a, b, d);
	}
}
