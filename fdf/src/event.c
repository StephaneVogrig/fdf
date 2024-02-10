/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:07:35 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/10 15:59:54 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_key_press(int keycode, t_fdf *data)
{
	if (keycode == 65307)
		mlx_loop_end(data->mlx);
	else if (keycode == 111) //o
		draw_line(data->img, point2d(100, 100, 0x0000ff00), point2d(110, 300, 0x0000ff00));

	printf("key pressed: %d\n", keycode);
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

void	test_line_bresenham(t_img	*img)
{
		// bresenham_x
		draw_line(img, point2d(400, 200, 0x0000ff00), point2d(400 + 100, 200 + 50, 0x0000ff00));
		draw_line(img, point2d(400, 200, 0x0000ff00), point2d(400 + 100, 200 - 50, 0x0000ff00));

		draw_line(img, point2d(400, 200, 0x0000ff00), point2d(400 - 100, 200 + 50, 0x0000ff00));
		draw_line(img, point2d(400, 200, 0x0000ff00), point2d(400 - 100, 200 - 50, 0x0000ff00));

		// bresenham_y
		draw_line(img, point2d(400, 200, 0x000000ff), point2d(400 + 50, 200 - 100, 0x000000ff));
		draw_line(img, point2d(400, 200, 0x000000ff), point2d(400 - 50, 200 - 100, 0x000000ff));

		draw_line(img, point2d(400, 200, 0x000000ff), point2d(400 + 50, 200 + 100, 0x000000ff));
		draw_line(img, point2d(400, 200, 0x000000ff), point2d(400 - 50, 200 + 100, 0x000000ff));
}

void	test_line_simple(t_img	*img)
{
		//ligne droite
		draw_line(img, point2d(400, 200, 0x0000ff00), point2d(400, 200 + 100, 0x0000ff00));
		draw_line(img, point2d(400, 200, 0x0000ff00), point2d(400, 200 - 100, 0x0000ff00));
		draw_line(img, point2d(400, 200, 0x0000ff00), point2d(400 + 100, 200, 0x0000ff00));
		draw_line(img, point2d(400, 200, 0x0000ff00), point2d(400 - 100, 200, 0x0000ff00));

		//ligne diagonale
		draw_line(img, point2d(400, 200, 0x0000ff00), point2d(400 + 100, 200 - 100, 0x0000ff00));
		draw_line(img, point2d(400, 200, 0x0000ff00), point2d(400 + 100, 200 + 100, 0x0000ff00));
		draw_line(img, point2d(400, 200, 0x0000ff00), point2d(400 - 100, 200 + 100, 0x0000ff00));
		draw_line(img, point2d(400, 200, 0x0000ff00), point2d(400 - 100, 200 - 100, 0x0000ff00));
}

int	on_mouse_release(int button, int x, int y, t_fdf *data)
{
	if ( button == MOUSE_RIGHT)
		draw_line(data->img, point2d(200, 200, 0x0000ff00), point2d(400, 400, 0x0000ff00));
	if (button == MOUSE_LEFT)
		data->left_button_is_press = FALSE;
	if (button == MOUSE_MIDLE)
		img_clean(data->img);
	if (button == MOUSE_ROLLUP)
		test_line_simple(data->img);
	if (button == MOUSE_ROLLDOWN)
		test_line_bresenham(data->img);
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
