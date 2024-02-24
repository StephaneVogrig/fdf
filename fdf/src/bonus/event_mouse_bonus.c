/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:23:41 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/24 04:36:24 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_sqare(t_fdf_img *img, int x, int y, t_color color)
{
	t_vec2i	max;
	int	xx;

	if (x < 0 || y < 0 || x >= WINDOW_WIDTH || y > WINDOW_HIGTH)
		return ;
	max.x = x + 10;
	if (max.x >= WINDOW_WIDTH)
		max.x = WINDOW_WIDTH - 1;
	max.y = y + 10;
	if (max.y >= WINDOW_HIGTH)
		max.y = WINDOW_HIGTH - 1;
	while (y < max.y)
	{
		xx = x;
		while (xx < max.x)
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
		zoom_decrease(fdf, x, y);
	if (button == MOUSE_ROLLDOWN)
		zoom_increase(fdf, x, y);
	return (0);
}
