/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:43:41 by svogrig           #+#    #+#             */
/*   Updated: 2024/03/05 14:28:37 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_float32	scale(float width_map, float high_map, int width_img, int high_img)
{
	t_vec2f	scale;

	scale.x = (float)width_img / (width_map);
	scale.y = (float)high_img / (high_map);
	if (scale.x < scale.y)
		return (scale.x);
	return (scale.y);
}

inline t_vec2f	compute_point(float x, float y, float z, t_transform *t)
{
	t_vec2f	point;

	x += t->offset_map.x;
	y += t->offset_map.y;
	z *= t->scale_z;
	point.x = t->dx + t->scale * (t->a1 * x + t->a2 * y + t->a3 * z);
	point.y = t->dy + t->scale * (t->b1 * x + t->b2 * y + t->b3 * z);
	return (point);
}

t_bound	bounding_box_projection(t_map *map, t_transform *t)
{
	t_bound	bb;
	t_vec2f	current;
	t_vec2i	i;

	current = compute_point(0, 0, map->datas[0][0].z, t);
	bb.min = current;
	bb.max = bb.min;
	i.y = -1;
	while (++i.y < map->nbr_line)
	{
		i.x = -1;
		while (++i.x < map->nbr_col)
		{
			current = compute_point(i.x, i.y, map->datas[i.y][i.x].z, t);
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
** center bouding box = min + (max - min)/2
** center bouding box = 2/2 min + 1/2 max - 1/2 min
** center bouding box = 1/2 min + 1/2 max
*/
void	transform_resize(t_transform *t, t_map *map, t_fdf_img *img)
{
	t_bound		bb;
	t_vec2f		dim_bb;

	t->scale = 1;
	t->dx = 0;
	t->dy = 0;
	bb = bounding_box_projection(map, t);
	dim_bb = vector2f_sub(bb.max, bb.min);
	if (dim_bb.x != 0 || dim_bb.y != 0)
		t->scale = scale(dim_bb.x, dim_bb.y, img->width, img->height) * 0.9;
	bb.min.x *= t->scale;
	bb.min.y *= t->scale;
	bb.max.x *= t->scale;
	bb.max.y *= t->scale;
	t->dx = (WINDOW_WIDTH - bb.max.x - bb.min.x) / 2;
	t->dy = (WINDOW_HIGTH - bb.max.y - bb.min.y) / 2;
}

void	transform_init(t_transform *t, t_map *map, t_fdf_img *img)
{
	t->offset_map.x = -(float)(map->nbr_col - 1) / 2;
	t->offset_map.y = -(float)(map->nbr_line - 1) / 2;
	projection_iso(t);
	t->rot = vector3f(90 - 35.26, 0.0, 45.0);
	t->scale_z = 1;
	transform_resize(t, map, img);
}
