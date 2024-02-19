/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:07:16 by stephane          #+#    #+#             */
/*   Updated: 2024/02/17 19:53:20 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	fdf;
	t_bool	ok;

	if (argc != 2)
		return (0);
	fdf_init(&fdf);
// ft_printf("scale z:%f\n", fdf.transform.scale_z);
	ok = map_load(argv[1], &fdf.map);
	if (ok)
		ok = mlx_setup(&fdf);
	if (ok) 
	{
		// mlx_do_key_autorepeaton(fdf.mlx);
		transform_init(&fdf.transform, &fdf.map, fdf.img);
// ft_printf("scale z:%f\n", fdf.transform.scale_z);
		event_setup(&fdf);
		render(&fdf);
		// map_to_img(&fdf.map, fdf.img, &fdf.transform);
		mlx_loop(fdf.mlx);
	}
	fdf_clean(&fdf);
	return (0);
}
