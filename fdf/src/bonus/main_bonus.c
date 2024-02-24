/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:10:44 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/24 04:21:11 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	t_bool	ok;

	if (argc != 2)
		return (0);
	fdf_init(&fdf);
	ok = map_load(argv[1], &fdf.map);
	if (ok)
		ok = mlx_setup(&fdf);
	if (ok)
	{
		find_minmax_z(&fdf.map, fdf.map.datas);
		set_origin_color(&fdf.map, fdf.map.datas);
		image_init(fdf.img_mlx, &fdf.img);
		transform_init(&fdf.transform, &fdf.map, &fdf.img);
		event_setup(&fdf);
		render(&fdf);
		mlx_loop(fdf.mlx);
	}
	fdf_clean(&fdf);
	return (0);
}
