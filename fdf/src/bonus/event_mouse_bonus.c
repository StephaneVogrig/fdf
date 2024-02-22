/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:23:41 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/22 06:20:45 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_sqare(t_fdf_img *img, int x, int y, t_color color)
{
	int	x_max;
	int	y_max;
	int	xx;

	if (x < 0 || y < 0 || x >= WINDOW_WIDTH || y > WINDOW_HIGTH)
		return ;
	x_max = x + 10;
	if (x_max >= WINDOW_WIDTH)
		x_max = WINDOW_WIDTH - 1;
	y_max = y + 10;
	if (y_max >= WINDOW_HIGTH)
		y_max = WINDOW_HIGTH - 1;
	while (y < y_max)
	{
		xx = x;
		while (xx < x_max)
		{
			img_set_pixel(img, xx, y, color);
			xx++;
		}
		y++;
	}
}

int	on_mouse_move(int x, int y, t_fdf *fdf)
{
	int		dx;
	int		dy;
	clock_t	begin;

	begin = clock();
	if (fdf->left_button_is_press)
	{
		dx = x - fdf->mouse_origin.x;
		dy = y - fdf->mouse_origin.y;
		mlx_clear_window(fdf->mlx, fdf->win);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img_mlx, dx, dy);
		update_screen(fdf, begin);
	}
	if (fdf->right_button_is_press)
	{
		draw_sqare(&fdf->img, x, y, color(0, 255, 0, 0));
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img_mlx, 0, 0);
	}
	return (0);
}

int	on_mouse_press(int button, int x, int y, t_fdf	*fdf)
{
	if (button == MOUSE_LEFT)
	{
		fdf->mouse_origin = vector2i(x, y);
		fdf->left_button_is_press = TRUE;
	}
	if (button == MOUSE_RIGHT)
		fdf->right_button_is_press = TRUE;
	return (0);
}

int	on_mouse_release(int button, int x, int y, t_fdf *fdf)
{
	if (button == MOUSE_RIGHT)
		fdf->right_button_is_press = FALSE;
	if (button == MOUSE_LEFT)
	{
		fdf->transform.dx += x - fdf->mouse_origin.x;
		fdf->transform.dy += y - fdf->mouse_origin.y;
		render(fdf);
		fdf->left_button_is_press = FALSE;
	}
	if (button == MOUSE_MIDLE)
		render(fdf);
	if (button == MOUSE_ROLLUP)
		zoom_decrease(fdf);
	if (button == MOUSE_ROLLDOWN)
		zoom_increase(fdf, x, y);
	return (0);
}
