/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:07:16 by stephane          #+#    #+#             */
/*   Updated: 2024/02/24 03:47:01 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	t_bool	ok;

	if (argc != 2)
	{
		ft_printf("usage: ./fdf <map_file>\n");
		return (0);
	}
	fdf_init(&fdf);
	ok = map_load(argv[1], &fdf.map);
	if (ok)
		ok = mlx_setup(&fdf);
	if (ok)
	{
		image_init(fdf.img_mlx, &fdf.img);
		transform_init(&fdf.transform, &fdf.map, &fdf.img);
		event_setup(&fdf);
		map_to_img(&fdf.map, &fdf.img, &fdf.transform);
		mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img_mlx, 0, 0);
		mlx_loop(fdf.mlx);
	}
	fdf_clean(&fdf);
	return (0);
}
