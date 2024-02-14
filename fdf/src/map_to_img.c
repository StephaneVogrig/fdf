/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:29:54 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/14 12:34:53 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	projection(int x, int y, t_data data, t_transform *t)
{
	t_pixel	pixel;

	pixel.x = t->dx + t->scale * (t->a1 * x + t->a2 * y + t->a3 * data.z);
	pixel.y = t->dy + t->scale * (t->b1 * x + t->b2 * y + t->b3 * data.z);
	pixel.color = data.color;
	return (pixel);
}

void	map_draw_img(t_img *img, t_map *map, t_transform *trans)
{
	t_pixel	current;
	t_pixel	next_col;
	int		x;
	int		y;

	y = 0; 
	while (y < map->nbr_line - 1)
	{
		x = 0;
		while (x < map->nbr_col - 1)
		{
			current = map->buffer[x];
			next_col = projection(x + 1, y, map->datas[y][x + 1], trans);
			map->buffer[x] = projection(x, y + 1, map->datas[y + 1][x], trans);
			img_set_pixel(img, current.x, current.y, current.color);
			draw_line(img, current, next_col);
			draw_line(img, current, map->buffer[x]);
			current = next_col;
			x++;
		}
		map->buffer[x] = projection(x, y + 1, map->datas[y + 1][x], trans);
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
		map->buffer[x] = projection(x, 0, map->datas[0][x], transform);
		x++;
	}
}

inline void	map_draw_buffer(t_img *img, t_pixel *buffer, int buffer_size)
{
	int	x;

	x = 0;
	while (x < buffer_size - 1)
	{
		img_set_pixel(img, buffer[x].x, buffer[x].y, buffer[x].color);
		draw_line(img, buffer[x], buffer[x + 1]);
		x++;
	}
	img_set_pixel(img, buffer[x].x, buffer[x].y, buffer[x].color);
}

void	map_to_img(t_map *map, t_img *img, t_transform *transform)
{
	clock_t begin = clock();

	buffer_init(map, transform);
	map_draw_img(img, map, transform);
	map_draw_buffer(img, map->buffer, map->nbr_col);
	map->is_update = TRUE;
	clock_t end = clock();
    // unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    // printf( "Finished in %ld ms\n", millis ); 
    printf( "Finished in %ld ticks | fps : %ld\n", end - begin, CLOCKS_PER_SEC / (end - begin));
    // printf( " %ld ticks\n", end - begin);

    // printf( "CLOCKS_PER_SEC =  %ld\n", CLOCKS_PER_SEC); 
}
