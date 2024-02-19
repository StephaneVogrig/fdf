/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:29:54 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/18 16:54:20 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

t_pixel	projection(int x, int y, t_data data, t_transform *t)
{
	t_pixel	pixel;
	float	z;
	float	pixel_z;

	x += t->offset_map.x;
	y += t->offset_map.y;
	z = data.z * t->scale_z;
	// z = data.z * 0.5;
	
	// z = data.z;
	

	
	pixel.x = t->scale * (t->a1 * x + t->a2 * y + t->a3 * z);
	pixel.y = t->scale * (t->b1 * x + t->b2 * y + t->b3 * z);
	pixel_z	= t->scale * (t->c1 * x + t->c2 * y + t->c3 * z);
	
	pixel.x += t->dx;
	pixel.y += t->dy;
	// pixel_z = 100 - pixel_z;
	
	// float	p_z = 1 - pixel_z / 500;
	// pixel.x *= p_z;
	// pixel.y *= p_z;

// ft_printf("x:%i y:%i z:%i | c1:%f c2:%f c3:%f\n", x, y, data.z, t->c1, t->c2, t->c3);
// ft_printf("scale:%f scale z:%f z:%f\n", t->scale, t->scale_z, z);
// ft_printf("pixel x:%i y:%i z:%f\n", pixel.x, pixel.y, pixel_z);
// ft_printf("c1:%i\n", pixel.x);
// printf("z map:%i z proj:%f z pixel:%e\n",data.z, z, pixel_z);
// printf("z map:%i z proj:%f z pixel:%f\n", data.z, z, );
	// if (pixel_z > 0)
	// {
	// pixel.x = pixel.x / (1 + pixel_z);
	// pixel.y = pixel.y / (1 + pixel_z);
	// }
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
    printf( "%-15s in %10ld ticks | %6.3f ms |%6ld fps\n", "map_to_img", end - begin, 1000.0 * (end - begin) / CLOCKS_PER_SEC , CLOCKS_PER_SEC / (end - begin));
}
