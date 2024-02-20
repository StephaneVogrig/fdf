/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:18:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/20 03:55:00 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	mlx_string_put(fdf->mlx,fdf->win, 20,20,0xffffff, "Map :");
	char	*txt;
	txt = ft_itoa(fdf->map.nbr_col);
	mlx_string_put(fdf->mlx,fdf->win, 30,40,0xffffff, "width :");
	mlx_string_put(fdf->mlx,fdf->win, 100,40,0xffffff, txt);
	free(txt);
	txt = ft_itoa(fdf->map.nbr_line);
	mlx_string_put(fdf->mlx,fdf->win, 30,60,0xffffff, "hight :");
	mlx_string_put(fdf->mlx,fdf->win, 100,60,0xffffff, txt);
	free(txt);
	return (0);
}
