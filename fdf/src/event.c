/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:07:35 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/08 03:19:53 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_key_press(int keycode, t_fdf *data)
{
	if (keycode == 65307)
	{
		mlx_loop_end(data->mlx);
	}
	// printf("key pressed: %d\n", keycode);
	return (0);	
}

int	on_mouse_move(int x, int y, t_fdf *data)
{
	if (data->left_button_is_press)
		draw_sqare(data->img, x, y, 0x00FF0000);
		// img_clean(data->img);
	// ft_printf("move x:%i, y:%i, left_button: %d\n", x, y, data->left_button_is_press);
	return (0);
}

int	on_mouse_press(int button, int x, int y, t_fdf	*data)
{
	if (button == MOUSE_LEFT)
		data->left_button_is_press = TRUE;
	if (button == MOUSE_RIGHT)
		draw_sqare(data->img, x, y, 0x000000FF);
	// ft_printf("press x:%i, y:%i, left_button: %d\n", x, y, data->left_button_is_press);
	return (0);
}

int	on_mouse_release(int button, int x, int y, t_fdf *data)
{
	if ( button == MOUSE_RIGHT)
		draw_line(data->img, point2d(200, 200), point2d(400, 400));
	if (button == MOUSE_LEFT)
		data->left_button_is_press = FALSE;
	if (button == MOUSE_MIDLE)
		img_clean(data->img);
	if (button == MOUSE_ROLLUP)
		draw_line(data->img, point2d(10, 100), point2d(10, 200));
	if (button == MOUSE_ROLLDOWN)
		draw_line(data->img, point2d(200, 200), point2d(800, 200));
	// ft_printf("release x:%i, y:%i, left_button: %d\n", x, y, data->left_button_is_press);
	return (0);
}

void	event_setup(t_fdf *data)
{
	mlx_key_hook(data->win, &on_key_press, data);
	mlx_hook(data->win, DESTROY_NOTIFY, 0, &window_close, data->mlx);
	mlx_hook(data->win, MOUSE_BUTTON_PRESS, 1L<<2, &on_mouse_press, data);
	mlx_hook(data->win, MOUSE_BUTTON_RELEASE, 1L<<3, &on_mouse_release, data);
	mlx_hook(data->win, MOUSE_MOVE, 1L<<6, &on_mouse_move, data);
	mlx_loop_hook(data->mlx, &render, data);
}
