/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:07:35 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/21 03:35:04 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	on_key_press(int keycode, t_fdf *fdf)
{
	fdf->key_pressed = keycode;
	if (keycode == KEY_ESC)
		mlx_loop_end(fdf->mlx);
	else if (keycode == KEY_LEFT_ARROW || keycode == KEY_UP_ARROW)
		map_move_keyboard(fdf, keycode);
	else if (keycode == KEY_RIGHT_ARROW || keycode == KEY_DOWN_ARROW)
		map_move_keyboard(fdf, keycode);
	else if (keycode == NUMPAD_KEY_4 || keycode == NUMPAD_KEY_6)
		map_rot_z_keyboard(fdf, keycode);
	else if (keycode == NUMPAD_KEY_8 || keycode == NUMPAD_KEY_2)
		map_rot_x_keyboard(fdf, keycode);
	else if (keycode == KEY_PGUP || keycode == KEY_PGDOWN)
		map_scale_z(fdf, keycode);
// printf("key pressed: %d\n", keycode);
	return (0);
}

int	on_key_release(int keycode, t_fdf *fdf)
{
	fdf->key_pressed = 0;
	return (0);
}

int on_loop(t_fdf *fdf)
{
	if (fdf->key_pressed)
		on_key_press(fdf->key_pressed, fdf);
	return (0);
}

int	on_close_window(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

void	event_setup(t_fdf *fdf)
{
	mlx_hook(fdf->win, DESTROY_NOTIFY, 0, &on_close_window, fdf->mlx);
	mlx_hook(fdf->win, ON_KEY_PRESS, 1L << 0, &on_key_press, fdf);
	mlx_hook(fdf->win, ON_KEY_RELEASE, 1L << 1, &on_key_release, fdf);
	mlx_hook(fdf->win, MOUSE_BUTTON_PRESS, 1L << 2, &on_mouse_press, fdf);
	mlx_hook(fdf->win, MOUSE_BUTTON_RELEASE, 1L << 3, &on_mouse_release, fdf);
	mlx_hook(fdf->win, MOUSE_MOVE, 1L << 6, &on_mouse_move, fdf);
	mlx_loop_hook(fdf->mlx, &on_loop, fdf);
}
