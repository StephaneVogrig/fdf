/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:18:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/14 17:19:40 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	render(t_fdf *fdf)
{
	// if (fdf->key_move_is_pressed)
	// 	map_move_keyboard(fdf, fdf->keycode);
	if (fdf->map.is_update)
	{
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
		fdf->map.is_update = FALSE;
	}
	return (0);
}
