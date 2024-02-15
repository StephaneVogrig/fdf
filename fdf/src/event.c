/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:07:35 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/14 17:12:24 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_key_press(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
		mlx_loop_end(fdf->mlx);
	else if (keycode == 111)
	{
		draw_line(fdf->img, pixel(100, 100, 0x00FFFF00), pixel(300, 100, 0x000000FF));
		draw_line(fdf->img, pixel(100, 100, 0x00FFFF00), pixel(100, 300, 0x000000FF));
		draw_line(fdf->img, pixel(100, 100, 0x00FFFF00), pixel(300, 300, 0x000000FF));
		fdf->map.is_update = TRUE;
	}
	else if (keycode == KEY_LEFT_ARROW || keycode == KEY_UP_ARROW)
		map_move_keyboard(fdf, keycode);
	else if (keycode == KEY_RIGHT_ARROW || keycode == KEY_DOWN_ARROW)
		map_move_keyboard(fdf, keycode);
	printf("key pressed: %d\n", keycode);
	return (0);
}

int	on_mouse_move(int x, int y, t_fdf *fdf)
{
	if (fdf->left_button_is_press)
	{
		draw_sqare(fdf->img, x, y, 0x00FF0000);
		fdf->map.is_update = TRUE;
	}
	if (fdf->right_button_is_press)
	{
		draw_sqare(fdf->img, x, y, 0x00FF0000);
		fdf->map.is_update = TRUE;
	}
	return (0);
}

int	on_mouse_press(int button, int x, int y, t_fdf	*fdf)
{
	if (button == MOUSE_LEFT)
		fdf->left_button_is_press = TRUE;
	if (button == MOUSE_RIGHT)
		fdf->right_button_is_press = TRUE;
		// draw_sqare(fdf->img, x, y, 0x000000FF);
	return (0);
}

int	on_mouse_release(int button, int x, int y, t_fdf *fdf)
{
	if ( button == MOUSE_RIGHT)
		fdf->right_button_is_press = FALSE;
	if (button == MOUSE_LEFT)
		fdf->left_button_is_press = FALSE;
	if (button == MOUSE_MIDLE)
		img_clean(&fdf->map, fdf->img, &fdf->transform);
	if (button == MOUSE_ROLLUP)
		zoom_decrease(&fdf->map, fdf->img, &fdf->transform);
	if (button == MOUSE_ROLLDOWN)
		zoom_increase(&fdf->map, fdf->img, &fdf->transform);
	return (0);
}

void	event_setup(t_fdf *fdf)
{
	mlx_key_hook(fdf->win, &on_key_press, fdf);
	mlx_hook(fdf->win, DESTROY_NOTIFY, 0, &window_close, fdf->mlx);
	mlx_hook(fdf->win, MOUSE_BUTTON_PRESS, 1L << 2, &on_mouse_press, fdf);
	mlx_hook(fdf->win, MOUSE_BUTTON_PRESS, 1L << 2, &on_mouse_press, fdf);
	mlx_hook(fdf->win, MOUSE_BUTTON_PRESS, 1L << 2, &on_mouse_press, fdf);
	mlx_hook(fdf->win, MOUSE_BUTTON_RELEASE, 1L << 3, &on_mouse_release, fdf);
	mlx_hook(fdf->win, MOUSE_MOVE, 1L << 6, &on_mouse_move, fdf);
	mlx_loop_hook(fdf->mlx, &render, fdf);
}
