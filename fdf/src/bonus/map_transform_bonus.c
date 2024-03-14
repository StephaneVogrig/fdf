/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_transform_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 05:15:59 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/27 02:00:39 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fdf_bonus.h"

inline void	map_move_keyboard(t_fdf *fdf, int keycode)
{
	t_vec2i	move;

	if (keycode == KEY_LEFT_ARROW)
		move = vector2i(-MOVE_STEP, 0);
	else if (keycode == KEY_UP_ARROW)
		move = vector2i(0, -MOVE_STEP);
	else if (keycode == KEY_RIGHT_ARROW)
		move = vector2i(MOVE_STEP, 0);
	else if (keycode == KEY_DOWN_ARROW)
		move = vector2i(0, MOVE_STEP);
	fdf->transform.dx += move.x;
	fdf->transform.dy += move.y;
	render(fdf);
}

void	map_rot_z_keyboard(t_fdf *fdf, int keycode)
{
	if (keycode == NUMPAD_KEY_4)
		fdf->transform.rot.z += 0.5;
	else if (keycode == NUMPAD_KEY_6)
		fdf->transform.rot.z -= 0.5;
	projection_gen(&fdf->transform, fdf->transform.rot);
	render(fdf);
}

void	map_rot_x_keyboard(t_fdf *fdf, int keycode)
{
	if (keycode == NUMPAD_KEY_8)
		fdf->transform.rot.x += 1;
	else if (keycode == NUMPAD_KEY_2)
		fdf->transform.rot.x -= 1;
	projection_gen(&fdf->transform, fdf->transform.rot);
	render(fdf);
}

void	map_scale_z(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_PGUP)
		fdf->transform.scale_z += 0.005;
	if (keycode == KEY_PGDOWN)
		fdf->transform.scale_z -= 0.005;
	transform_resize(&fdf->transform, &fdf->map, &fdf->img);
	render(fdf);
}

void	map_resize(t_fdf *fdf)
{
	transform_resize(&fdf->transform, &fdf->map, &fdf->img);
	render(fdf);
}
