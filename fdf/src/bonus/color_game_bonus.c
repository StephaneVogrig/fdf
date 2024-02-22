/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:38:05 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/22 21:43:01 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	set_origin_color(t_map *map, t_data **datas)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->nbr_line)
	{
		j = 0;
		while (j < map->nbr_col)
		{
			datas[i][j].color.ui = datas[i][j].color_origin.ui;
			j++;
		}
		i++;
	}
}

void	set_earth_color(t_map *map, t_data **datas)
{
	t_multigrad	grad;
	t_vec2i		i;

	grad.a = grad_step(0x000050ff, 0x00000080, map->z_min);
	grad.b = grad_step(0x0032c800, 0x00c8c800, map->z_max * 0.2);
	grad.c = grad_step(0x00c8c800, 0x00640000, map->z_max * 0.6);
	i.y = 0;
	while (i.y < map->nbr_line)
	{
		i.x = 0;
		while (i.x < map->nbr_col)
		{
			datas[i.y][i.x].color = earth(grad, datas[i.y][i.x].z, map->z_max);
			i.x++;
		}
		i.y++;
	}
}

void	set_mars_color(t_map *map, t_data **datas)
{
	int		i;
	int		j;
	t_grad	grad;

	grad = grad_step(0x00401000, 0x00dc2800, map->z_max - map->z_min);
	i = 0;
	while (i < map->nbr_line)
	{
		j = 0;
		while (j < map->nbr_col)
		{
			datas[i][j].color = col_grad_step(grad, datas[i][j].z - map->z_min);
			j++;
		}
		i++;
	}
}

void	set_no_color(t_map *map, t_data **datas)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->nbr_line)
	{
		j = 0;
		while (j < map->nbr_col)
		{
			datas[i][j].color.ui = 0xffffff;
			j++;
		}
		i++;
	}
}

void	color_game(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_F1)
		set_origin_color(&fdf->map, fdf->map.datas);
	if (keycode == KEY_F2)
		set_earth_color(&fdf->map, fdf->map.datas);
	if (keycode == KEY_F3)
		set_mars_color(&fdf->map, fdf->map.datas);
	if (keycode == KEY_F4)
		set_no_color(&fdf->map, fdf->map.datas);
	render(fdf);
}
