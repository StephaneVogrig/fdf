/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_earth_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:59:34 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/22 22:16:37 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	map_earth_size(t_fdf *fdf)
{
	fdf->transform.scale_z = 0.1;
	set_earth_color(&fdf->map, fdf->map.datas);
	transform_resize(&fdf->transform, &fdf->map, &fdf->img);
	render(fdf);
}
