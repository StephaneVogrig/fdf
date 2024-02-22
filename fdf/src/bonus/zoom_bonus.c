/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 06:42:19 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/21 03:19:16 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

inline void	zoom_decrease(t_fdf *fdf)
{
	fdf->transform.scale *= 0.95;
	render(fdf);
	// map->is_update = TRUE;
}

inline void	zoom_increase(t_fdf *fdf, int x, int y)
{
	// fdf->transform.dx += 1.05 * (fdf->transform.dx - x);
	fdf->transform.scale *= 1.05;
	render(fdf);
	// img_clear(map, img);
	// map_to_img(map, img, t);

		// mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	// map->is_update = TRUE;
}
