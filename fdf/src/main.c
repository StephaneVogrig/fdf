/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:07:16 by stephane          #+#    #+#             */
/*   Updated: 2024/02/14 17:23:37 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
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
		// mlx_do_key_autorepeaton(fdf.mlx);
		fdf.transform = transform_init(&fdf.map, fdf.img);
		event_setup(&fdf);
		map_to_img(&fdf.map, fdf.img, &fdf.transform);
		mlx_loop(fdf.mlx);
	}
	fdf_clean(&fdf);
	return (0);
}
