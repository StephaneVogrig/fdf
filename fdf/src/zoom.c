/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 06:42:19 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/18 20:55:19 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

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
