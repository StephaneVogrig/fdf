/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_move_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 05:15:59 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/21 03:18:49 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

	// ft_printf("x:%i, y:%i\n", x, y);

inline void	map_move_keyboard(t_fdf *fdf, int keycode)
{
	t_vec2i move;
	
	// printf("map move: %d\n", keycode);

	if (keycode == KEY_LEFT_ARROW)
		move = vector2i(-MOVE_STEP, 0);
	else if (keycode == KEY_UP_ARROW)
		move = vector2i(0, -MOVE_STEP);
	else if (keycode == KEY_RIGHT_ARROW)
		move = vector2i(MOVE_STEP, 0);
	else if (keycode == KEY_DOWN_ARROW)
		move = vector2i(0, MOVE_STEP);
	// fdf->transform.dx += x - fdf->last_mouse_pos.x;
	// fdf->transform.dy += y - fdf->last_mouse_pos.y;
	// map_to_img(&fdf->map, fdf->img, &fdf->transform);
	// fdf->last_mouse_pos = vector2i(x, y);
	
	fdf->transform.dx += move.x;
	fdf->transform.dy += move.y;
	// img_clear(&fdf->map, fdf->img);
	// map_to_img(&fdf->map, fdf->img, &fdf->transform);
	render(fdf);
	fdf->map.is_update = TRUE;
}

void	map_rot_z_keyboard(t_fdf *fdf, int keycode)
{
// ft_printf("avant rot z:%f\n", fdf->transform.rot.z);
	if (keycode == NUMPAD_KEY_4)
		fdf->transform.rot.z += 0.5;
	else if (keycode == NUMPAD_KEY_6)
		fdf->transform.rot.z -= 0.5;
	projection_gen(&fdf->transform, fdf->transform.rot);
	// img_clear(&fdf->map, fdf->img);
	// map_to_img(&fdf->map, fdf->img, &fdf->transform);
	render(fdf);
// ft_printf("apres rot z:%f\n", fdf->transform.rot.z);
	fdf->map.is_update = TRUE;
	// mlx_flush_event(fdf->mlx);

}

void	map_rot_x_keyboard(t_fdf *fdf, int keycode)
{
// ft_printf("avant rot z:%f\n", fdf->transform.rot.z);
	if (keycode == NUMPAD_KEY_8)
		fdf->transform.rot.x += 1;
	else if (keycode == NUMPAD_KEY_2)
		fdf->transform.rot.x -= 1;
	projection_gen(&fdf->transform, fdf->transform.rot);
	// img_clear(&fdf->map, fdf->img);
	// map_to_img(&fdf->map, fdf->img, &fdf->transform);
	render(fdf);
// ft_printf("apres rot z:%f\n", fdf->transform.rot.z);
	fdf->map.is_update = TRUE;

}

void	map_scale_z(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_PGUP)
		fdf->transform.scale_z += 0.005;
	if (keycode == KEY_PGDOWN)
		fdf->transform.scale_z -= 0.005;
	render(fdf);
	
}