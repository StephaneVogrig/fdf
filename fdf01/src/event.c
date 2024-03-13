/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:07:35 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/21 03:49:40 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_close_window(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

int	on_key_press(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		mlx_loop_end(fdf->mlx);
	return (0);
}

void	event_setup(t_fdf *fdf)
{
	mlx_hook(fdf->win, DESTROY_NOTIFY, 0, &on_close_window, fdf->mlx);
	mlx_hook(fdf->win, ON_KEY_PRESS, 1L << 0, &on_key_press, fdf);
}
