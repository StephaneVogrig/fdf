/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 06:42:19 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/16 06:44:10 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_decrease(t_map *map, t_img *img, t_transform *t)
{
	t->scale *= 0.9;
	img_clear(map, img);
	map_to_img(map, img, t);
	map->is_update = TRUE;
}

void	zoom_increase(t_map *map, t_img *img, t_transform *t)
{
	t->scale *= 1.1;
	img_clear(map, img);
	map_to_img(map, img, t);
	map->is_update = TRUE;
}
