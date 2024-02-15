/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 05:15:59 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/14 16:22:02 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

	// ft_printf("x:%i, y:%i\n", x, y);

inline void	map_move_keyboard(t_fdf *fdf, int keycode)
{
	t_vec2i move;
	
	printf("map move: %d\n", keycode);

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
	img_clear(&fdf->map, fdf->img);
	map_to_img(&fdf->map, fdf->img, &fdf->transform);
	fdf->map.is_update = TRUE;
}
