/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:43:41 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/22 00:52:20 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_float32	scale(float width_map, float high_map, int width_img, int high_img)
{
	t_vec2f	scale;

	scale.x = (float)width_img / (width_map);
	scale.y = (float)high_img / (high_map);
	if (scale.x < scale.y)
		return (scale.x);
	return (scale.y);
}

t_vec2f	compute_point(float x, float y, t_data data, t_transform *t)
{
	t_vec2f	point;

	x += t->offset_map.x;
	y += t->offset_map.y;
	point.x = 0.70710678185 * x - 0.70710678185 * y;
	point.y = 0.408248290464 * x + 0.408248290464 * y - 0.816496580928 * data.z;
	return (point);
}

t_bound	bounding_box_projection(t_map *map, t_transform *transform)
{
	t_bound	bb;
	t_vec2f	current;
	t_vec2i	i;

	current = compute_point(0, 0, map->datas[0][0], transform);
	bb.min = current;
	bb.max = current;
	i.y = -1;
	while (++i.y < map->nbr_line)
	{
		i.x = -1;
		while (++i.x < map->nbr_col)
		{
			current = compute_point(i.x, i.y, map->datas[i.y][i.x], transform);
			if (current.x < bb.min.x)
				bb.min.x = current.x;
			if (current.y < bb.min.y)
				bb.min.y = current.y;
			if (current.x > bb.max.x)
				bb.max.x = current.x;
			if (current.y > bb.max.y)
				bb.max.y = current.y;
		}
	}
	return (bb);
}

/*
** compute the scale and the offset of the projection
**
** center bouding box =  min + (max - min)/2
** center bouding box =  2/2 min + 1/2 max - 1/2 min
** center bouding box =  1/2 min + 1/2 max
*/
void	transform_init(t_transform *transform, t_map *map, t_fdf_img *img)
{
	t_bound		bb;
	t_vec2f		dim_bb;
	t_vec2f		dim_proj;
	t_vec2f		center_proj;

	transform->offset_map.x = -map->nbr_col / 2;
	transform->offset_map.y = -map->nbr_line / 2;
	bb = bounding_box_projection(map, transform);
	dim_bb = vector2f_sub(bb.max, bb.min);
	transform->scale = scale(dim_bb.x, dim_bb.y, img->width, img->height) * 0.9;
	bb.min.x *= transform->scale;
	bb.min.y *= transform->scale;
	bb.max.x *= transform->scale;
	bb.max.y *= transform->scale;
	transform->dx = (WINDOW_WIDTH - bb.max.x - bb.min.x) / 2;
	transform->dy = (WINDOW_HIGTH - bb.max.y - bb.min.y) / 2;
}
