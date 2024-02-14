/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 05:15:59 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/14 05:16:16 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.c"

inline void	map_move(int x, int y, t_fdf *fdf)
{
	ft_printf("x:%i, y:%i\n", x, y);
	// fdf->transform.dx += x - fdf->last_mouse_pos.x;
	// fdf->transform.dy += y - fdf->last_mouse_pos.y;
	// map_to_img(&fdf->map, fdf->img, &fdf->transform);
	fdf->last_mouse_pos = vector2i(x, y);
	
	// fdf->map.is_update = TRUE;
}
