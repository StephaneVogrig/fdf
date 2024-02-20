/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:14:41 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/20 16:28:44 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

inline void	draw_line_hor(t_img *img, t_pixel a, t_pixel b)
{
	int			dx;
	t_gradiant	gradiant;

	if (a.x < b.x)
		dx = 1;
	else
		dx = -1;
	a.x += dx;
	gradiant = color_gradiant(a.color, b.color, vector2i_sub(b.vec2i, a.vec2i));
	while (a.x != b.x)
	{
		if (a.color != b.color)
			a.color = color_gradiant_add(&gradiant);
		img_set_pixel(img, a.x, a.y, a.color);
		a.x += dx;
	}
}

inline void	draw_line_diag(t_img *img, t_pixel a, t_pixel b)
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
	a.x += d.x;
	a.y += d.y;
	while (a.x != b.x)
	{
		if (a.color != b.color)
			a.color = color_gradiant_add(&gradiant);
		img_set_pixel(img, a.x, a.y, a.color );
		a.x += d.x;
		a.y += d.y;
	}
}

inline void	draw_line_vert(t_img *img, t_pixel a, t_pixel b)
{
	int			dy;
	t_gradiant	gradiant;

	if (a.y == b.y)
		return ;		
	if (a.y < b.y)
		dy = 1;
	else
		dy = -1;
	a.y += dy;
	gradiant = color_gradiant(a.color, b.color, vector2i_sub(b.vec2i, a.vec2i));
	while (a.y != b.y)
	{
		if (a.color != b.color)
			a.color = color_gradiant_add(&gradiant);
		img_set_pixel(img, a.x, a.y, a.color);
		a.y += dy;
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
}


void	draw_line(t_img *img, t_pixel a, t_pixel b)
{
	t_vec2i	d;
	t_vec3f	g_color;

	if (a.x >= img->width && b.x >= img->width || a.x < 0 && b.x < 0)
		return ;
	if (a.y >= img->height && b.y >= img->height || a.y < 0 && b.y < 0)
		return ;
	if (a.x == b.x)
		draw_line_vert(img, a, b);
	else if (a.y == b.y)
		draw_line_hor(img, a, b);
	else
	{
		d = vector2i_sub(b.vec2i, a.vec2i);
		draw_line_oblique(img, a, b, d);
	}
}
