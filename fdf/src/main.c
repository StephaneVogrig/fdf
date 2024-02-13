/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:07:16 by stephane          #+#    #+#             */
/*   Updated: 2024/02/13 07:00:26 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	fdf_var;
	t_bool	ok;

	if (argc != 2)
		return (0);
	fdf_init(&fdf_var);
	ok = map_load(argv[1], &fdf_var.map);
	if (ok)
		ok = mlx_setup(&fdf_var);
	if (ok)
	{
		fdf_var.transform = transform_init(&fdf_var.map, fdf_var.img);
		event_setup(&fdf_var);
		map_to_img(&fdf_var.map, fdf_var.img, &fdf_var.transform);
		mlx_loop(fdf_var.mlx);
	}
	fdf_clean(&fdf_var);
	return (0);
}
