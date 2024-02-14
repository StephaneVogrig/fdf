/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:07:35 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/14 05:17:33 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_key_press(int keycode, t_fdf *data)
{
	if (keycode == 65307)
		mlx_loop_end(data->mlx);
	else if (keycode == 111)
		draw_line(data->img, pixel(100, 100, 0x00ff0000), pixel(110, 300, 0x00ff0000));

	printf("key pressed: %d\n", keycode);
	return (0);
}

int	on_mouse_move(int x, int y, t_fdf *data)
{
	if (data->left_button_is_press)
	{
		draw_sqare(data->img, x, y, 0x00FF0000);
		data->map.is_update = TRUE;
	}
	return (0);
}

int	on_mouse_press(int button, int x, int y, t_fdf	*data)
{
	if (button == MOUSE_LEFT)
		data->left_button_is_press = TRUE;
	if (button == MOUSE_RIGHT)
		draw_sqare(data->img, x, y, 0x000000FF);
	return (0);
}

int	on_mouse_release(int button, int x, int y, t_fdf *data)
{
	if ( button == MOUSE_RIGHT)
		data->right_button_is_press = FALSE;
	if (button == MOUSE_LEFT)
		data->left_button_is_press = FALSE;
	if (button == MOUSE_MIDLE)
		img_clean(&data->map, data->img, &data->transform);
	if (button == MOUSE_ROLLUP)
		zoom_decrease(&data->map, data->img, &data->transform);
	if (button == MOUSE_ROLLDOWN)
		zoom_increase(&data->map, data->img, &data->transform);
	return (0);
}

void	event_setup(t_fdf *data)
{
	mlx_key_hook(data->win, &on_key_press, data);
	mlx_hook(data->win, DESTROY_NOTIFY, 0, &window_close, data->mlx);
	mlx_hook(data->win, MOUSE_BUTTON_PRESS, 1L << 2, &on_mouse_press, data);
	mlx_hook(data->win, MOUSE_BUTTON_RELEASE, 1L << 3, &on_mouse_release, data);
	mlx_hook(data->win, MOUSE_MOVE, 1L << 6, &on_mouse_move, data);
	mlx_loop_hook(data->mlx, &render, data);
}
