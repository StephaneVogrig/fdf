/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:51:07 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/13 19:38:00 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_map_data(t_map map)
{
	int		x;
	int		y;
	t_data	**datas;

	datas = map.datas;
	y = 0;
	ft_putstr_fd("loaded\n", STDOUT);
	while (y < map.nbr_line)
	{
		x = 0;
		while (x < map.nbr_col)
		{
			if (x == 0)
				ft_printf("%i", map.datas[y][x].z);
			else
				ft_printf("%3i", map.datas[y][x].z);
			if (map.datas[y][x].color)
				ft_printf(",%#x", map.datas[y][x].color);
			x++;
		}
		ft_putchar_fd('\n', STDOUT);
		y++;
	}
}

void	draw_sqare(t_img *img, int x, int y, int color)
{
	int	x_max;
	int	y_max;
	int	xx;

	if (x < 0 || y < 0 || x >= WINDOW_WIDTH || y > WINDOW_HIGTH)
		return ;
	x_max = x + 10;
	if (x_max >= WINDOW_WIDTH)
		x_max = WINDOW_WIDTH - 1;
	y_max = y + 10;
	if (y_max >= WINDOW_HIGTH)
		y_max = WINDOW_HIGTH - 1;
	while (y < y_max)
	{
		xx = x;
		while (xx < x_max)
		{
			img_set_pixel(img, xx, y, color);
			xx++;
		}
		y++;
	}
}

void	test_line_bresenham(t_img	*img)
{
		// bresenham_x
		draw_line(img, pixel(400, 200, 0x0000ff00), pixel(400 + 100, 200 + 50, 0x0000ff00));
		draw_line(img, pixel(400, 200, 0x0000ff00), pixel(400 + 100, 200 - 50, 0x0000ff00));

		draw_line(img, pixel(400, 200, 0x0000ff00), pixel(400 - 100, 200 + 50, 0x0000ff00));
		draw_line(img, pixel(400, 200, 0x0000ff00), pixel(400 - 100, 200 - 50, 0x0000ff00));

		// bresenham_y
		draw_line(img, pixel(400, 200, 0x000000ff), pixel(400 + 50, 200 - 100, 0x000000ff));
		draw_line(img, pixel(400, 200, 0x000000ff), pixel(400 - 50, 200 - 100, 0x000000ff));

		draw_line(img, pixel(400, 200, 0x000000ff), pixel(400 + 50, 200 + 100, 0x000000ff));
		draw_line(img, pixel(400, 200, 0x000000ff), pixel(400 - 50, 200 + 100, 0x000000ff));
}

void	test_line_simple(t_img	*img)
{
		//ligne droite
		draw_line(img, pixel(400, 200, 0x0000ff00), pixel(400, 200 + 100, 0x0000ff00));
		draw_line(img, pixel(400, 200, 0x0000ff00), pixel(400, 200 - 100, 0x0000ff00));
		draw_line(img, pixel(400, 200, 0x0000ff00), pixel(400 + 100, 200, 0x0000ff00));
		draw_line(img, pixel(400, 200, 0x0000ff00), pixel(400 - 100, 200, 0x0000ff00));

		//ligne diagonale
		draw_line(img, pixel(400, 200, 0x0000ff00), pixel(400 + 100, 200 - 100, 0x0000ff00));
		draw_line(img, pixel(400, 200, 0x0000ff00), pixel(400 + 100, 200 + 100, 0x0000ff00));
		draw_line(img, pixel(400, 200, 0x0000ff00), pixel(400 - 100, 200 + 100, 0x0000ff00));
		draw_line(img, pixel(400, 200, 0x0000ff00), pixel(400 - 100, 200 - 100, 0x0000ff00));
}
