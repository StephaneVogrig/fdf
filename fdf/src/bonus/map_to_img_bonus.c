/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_img_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:29:54 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/22 00:21:30 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

inline t_pixel	compute_pixel(int x, int y, t_data data, t_transform *t)
{
	t_vec2f	point;
	t_pixel	pixel;

	point = compute_point(x, y, data.z, t);
	pixel.x = round(point.x);
	pixel.y = round(point.y);
	pixel.color.ui = data.color.ui;
// ft_printf("pixel x:%i y:%i color:%#x\n", pixel.x, pixel.y, pixel.color.ui);
	return (pixel);
}

void	map_draw_img(t_fdf_img *img, t_map *map, t_transform *trans)
{
	t_pixel	current;
	int		x;
	int		y;

	y = 0; 
	while (y < map->nbr_line - 1)
	{
		x = 0;
		current = map->buffer[0];
		while (x < map->nbr_col - 1)
		{
			img_set_pixel(img, current.x, current.y, current.color);
			draw_line(img, current, map->buffer[x + 1]);
			map->buffer[x] = compute_pixel(x, y + 1, map->datas[y + 1][x], trans);
			draw_line(img, current, map->buffer[x]);
			x++;
			current = map->buffer[x];
		}
		map->buffer[x] = compute_pixel(x, y + 1, map->datas[y + 1][x], trans);
		img_set_pixel(img, current.x, current.y, current.color);
		draw_line(img, current, map->buffer[x]);
		y++;
	}
}

inline void	buffer_init(t_map *map, t_transform *transform)
{
	int	x;

	x = 0;
	while (x < map->nbr_col)
	{
		map->buffer[x] = compute_pixel(x, 0, map->datas[0][x], transform);
		x++;
	}
}

inline void	map_draw_buffer(t_fdf_img *img, t_pixel *buffer, int buffer_size)
{
	int	x;

	x = 0;
	while (x < buffer_size - 1)
	{
		img_set_pixel(img, buffer[x].x, buffer[x].y, buffer[x].color);
// ft_printf("draw buffer x:%i, y:%i, col:%x\n", buffer[x].x, buffer[x].y, buffer[x].color);
		draw_line(img, buffer[x], buffer[x + 1]);
		x++;
	}
	img_set_pixel(img, buffer[x].x, buffer[x].y, buffer[x].color);
// ft_printf("draw buffer x:%i, y:%i, col:%x\n", buffer[x].x, buffer[x].y, buffer[x].color);
}

void	map_to_img(t_map *map, t_fdf_img *img, t_transform *transform)
{
	// clock_t begin = clock();
// ft_printf("enter map to img\n");
	buffer_init(map, transform);
	map_draw_img(img, map, transform);
	map_draw_buffer(img, map->buffer, map->nbr_col);
	map->is_update = TRUE;

// ft_printf("quit map to img\n");
	// clock_t end = clock();
    // printf( "%-15s in %10ld ticks | %6.3f ms |%6ld fps\n", "map_to_img", end - begin, 1000.0 * (end - begin) / CLOCKS_PER_SEC , CLOCKS_PER_SEC / (end - begin));
}
