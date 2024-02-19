/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:18:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/18 20:04:39 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

int	render(t_fdf *fdf)
{
	// if (fdf->key_move_is_pressed)
	// 	map_move_keyboard(fdf, fdf->keycode);
	// if (fdf->map.is_update)
	// {
	// 	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	// 	fdf->map.is_update = FALSE;
	// }
	mlx_do_sync(fdf->mlx);
	img_clear(&fdf->map, fdf->img);
	map_to_img(&fdf->map, fdf->img, &fdf->transform);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	return (0);
}
