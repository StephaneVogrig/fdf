/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:04:03 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/22 10:16:38 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	z_scale_10(t_fdf *fdf)
{
	fdf->transform.scale_z = 0.1;
	render(fdf);
}

void	find_minmax_z(t_map *map, t_data **datas)
{
	int	i;
	int	j;

	map->z_min = datas[0][0].z;
	map->z_max = map->z_min;
	i = 0;
	while (i < map->nbr_line)
	{
		j = 0;
		while (j < map->nbr_col)
		{
			if (datas[i][j].z > map->z_max)
				map->z_max = datas[i][j].z;
			if (datas[i][j].z < map->z_min)
				map->z_min = datas[i][j].z;
			j++;
		}
		i++;
	}
}
