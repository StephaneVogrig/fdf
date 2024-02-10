/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:14:41 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/10 20:20:37 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_hor(t_img *img, int y, int xa, int xb)
{
	int	x;
	int	end;

	x = si32_min(xa, xb);
	end = si32_max(xa, xb);
	while (x <= end)
		img_set_pixel(img, x++, y, 0x00FFFFFF);
}

void	draw_line_diag(t_img *img, t_point2d a, t_point2d b)
{
	int px;
	int py;

	if (b.x - a.x > 0 )
		px = 1;
	else
		px = -1;
	if (b.y - a.y > 0 )
		py = 1;
	else
		py = -1;

	while (a.x != b.x)
	{
		a.x += px;
		a.y += py;
		img_set_pixel(img, a.x, a.y, 0x00FF0000);
	}
}

void	draw_line_vert(t_img *img, int x, int ya, int yb)
{
	int	y;
	int	end;

	y = si32_min(ya, yb);
	end = si32_max(ya, yb);
	while (y <= end)
		img_set_pixel(img, x, y++, 0x00FFFFFF);
}

void	draw_line_oblique(t_img *img, t_point2d a, t_point2d b, t_vec2d d)
{
	t_vec2d	abs_d;

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
	t_vec2d	d;

	if (a.x == b.x)
		draw_line_vert(img, a.x, a.y, b.y);
	else if (a.y == b.y)
		draw_line_hor(img, a.y, a.x, b.x);
	else
	{
		d.x = b.x - a.x;
		d.y = b.y - a.y;
		draw_line_oblique(img, a, b, d);
	}
}
