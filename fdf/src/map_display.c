/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:29:54 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/13 07:11:51 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_triple(t_img *img, t_point2d a, t_point2d b, t_point2d c)
{
	img_set_pixel(img, a.x, a.y, a.color);
	draw_line(img, a, b);
	draw_line(img, a, c);
}

t_point2d	projection(int x, int y, t_data data, t_transform *t)
{
	t_point2d	point;

	point.x = t->dx + t->scale * (t->a1 * x + t->a2 * y + t->a3 * data.z);
	point.y = t->dy + t->scale * (t->b1 * x + t->b2 * y + t->b3 * data.z);
	point.color = data.color;
	return (point);
}

void	map_data_to_img(t_img *img, t_map *map, t_transform *transform)
{
	t_point2d	p_current;
	t_point2d	p_next_col;
	int 		x;
	int			y;

	y = 0;
	while (y < map->nbr_line - 1)
	{
		x = 0;
		while (x < map->nbr_col - 1)
		{
			p_current = map->buffer[x];
			p_next_col = projection(x + 1, y, map->datas[y][x + 1], transform);
			map->buffer[x] = projection(x, y + 1, map->datas[y + 1][x], transform);
			draw_triple(img, p_current, p_next_col, map->buffer[x]);
			p_current = p_next_col;
			x++;
		}
		map->buffer[x] = projection(x, y + 1, map->datas[y + 1][x], transform);
		img_set_pixel(img, p_current.x, p_current.y, p_current.color);
		draw_line(img, p_current, map->buffer[x]);
		y++;
	}
}

inline void	draw_point(t_img *img, t_point2d p)
{
	img_set_pixel(img, p.x, p.y, p.color);
}

void	map_to_img(t_map *map, t_img *img, t_transform *transform)
{
	int	x;

	x = 0;
	while (x < map->nbr_col)
	{
		map->buffer[x] = projection(x, 0, map->datas[0][x], transform);
		x++;
	}
	map_data_to_img(img, map, transform);
	x = 0;
	while (x < map->nbr_col - 1)
	{
		draw_point(img, map->buffer[x]);
		draw_line(img, map->buffer[x], map->buffer[x + 1]);
		x++;
	}
	draw_point(img, map->buffer[x]);
	map->is_update = TRUE;
}
