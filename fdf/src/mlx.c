/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:14:11 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/17 20:26:44 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

t_bool	mlx_setup(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
		return (error_msg("mlx_init: failed\n"));
	fdf->win = mlx_new_window(fdf->mlx, WINDOW_WIDTH, WINDOW_HIGTH, "fdf");
	if (fdf->win == NULL)
		return (error_msg("mlx_new_window: failed\n"));
	fdf->img = mlx_new_image(fdf->mlx, WINDOW_WIDTH, WINDOW_HIGTH);
	if (fdf->img == NULL)
		return (error_msg("mlx_new_image: failed\n"));
		
	clock_t begin = clock();
	fdf->img2 = mlx_new_image(fdf->mlx, WINDOW_WIDTH, WINDOW_HIGTH);
	clock_t end = clock();
    printf( "%-15s in %10ld ticks | %6.3f ms |%6ld fps\n", "map_to_img", end - begin, 1000.0 * (end - begin) / CLOCKS_PER_SEC , CLOCKS_PER_SEC / (end - begin));

	if (fdf->img2 == NULL)
		return (error_msg("mlx_new_image: failed\n"));
	return (SUCCESS);
}
