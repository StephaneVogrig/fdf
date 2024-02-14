/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:43:41 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/14 13:31:08 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_float32	scale(float width_map, float high_map, int width_img, int high_img)
{
	float	scale_x;
	float	scale_y;

// ft_printf("width map:%i, img:%i - high map:%i, img:%i\n", width_map, width_img, high_map, high_img);
	scale_x = (float)width_img / (width_map);
	scale_y = (float)high_img / (high_map);
// ft_printf("scale x:%.20f, y:%.20f\n", scale_x, scale_y);
	if (scale_x < scale_y)
		return (scale_x);
	return (scale_y);
}

// ft_printf("bbmin x:%i, y:%i - bbmax x:%i, y:%i\n", bb.min.x, bb.min.y, bb.max.x, bb.max.y);

t_vec2f	projection_f(float x, float y, t_data data, t_transform *t)
{
	t_vec2f	point;

	point.x = t->dx + t->scale * (t->a1 * x + t->a2 * y + t->a3 * data.z);
	point.y = t->dy + t->scale * (t->b1 * x + t->b2 * y + t->b3 * data.z);
	return (point);
}


t_bound	bounding_box_projection(t_map *map, t_transform *transform)
{
	t_bound	bb;
	t_vec2f		current;
	t_vec2i		i;

	current = projection_f(0, 0, map->datas[0][0], transform);
// printf("current x:%i\n", current.x);
	bb.min = current;
	bb.max = bb.min;
	i.y = -1;
	while (++i.y < map->nbr_line)
	{
		i.x = -1;
		while (++i.x < map->nbr_col)
		{

// ft_printf("bbmin x:%i, y:%i - bbmax x:%i, y:%i\n", bb.min.x, bb.min.y, bb.max.x, bb.max.y);
			current = projection_f(i.x, i.y, map->datas[i.y][i.x], transform);
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
// ft_printf("bbmin x:%i, y:%i - bbmax x:%i, y:%i\n", bb.min.x, bb.min.y, bb.max.x, bb.max.y);
	return (bb);
}

t_transform	transform_init(t_map *map, t_img *img)
{
	t_transform	transform;
	t_bound	bb;
	t_vec2f		dim_bb;
	t_vec2f		dim_proj;
	t_vec2f		center_proj;

	transform.a1 = 0.71;
	transform.a2 = -0.71;
	transform.a3 = 0;
	transform.b1 = 0.41;
	transform.b2 = 0.41;
	transform.b3 = -0.82;

	transform.scale = 1;
	transform.dx = 0;
	transform.dy = 0;

	bb = bounding_box_projection(map, &transform);
ft_printf("bounding box min x:%i, y:%i - max x:%i, y:%i\n", bb.min.x, bb.min.y, bb.max.x, bb.max.y);
	dim_bb = vector2f_sub(bb.max, bb.min);	

ft_printf("dim x:%i, y:%i\n", dim_bb.x, dim_bb.y);

	transform.scale = scale(dim_bb.x, dim_bb.y, img->width, img->height) * 0.9;
ft_printf("scale:%f\n", transform.scale);

	// transform.dx = (dim_bb.x / 2) * transform.scale;
	// transform.dy = (dim_bb.y / 2) * transform.scale;
	// bb.min.x = round(bb.min.x * transform.scale);
	// bb.min.y = round(bb.min.y * transform.scale);
	bb.min.x *= transform.scale;
	bb.min.y *= transform.scale;
	bb.max.x *= transform.scale;
	bb.max.y *= transform.scale;
ft_printf("bb min x:%i, y:%i - max x:%i, y:%i\n", bb.min.x, bb.min.y, bb.max.x, bb.max.y);
// 	dim_bb.x *= transform.scale;
// 	dim_bb.y *= transform.scale;
// ft_printf("dim_bb x:%i, y:%i\n", dim_bb.x, dim_bb.y);
// 	center_proj.x = bb.min.x + (dim_bb.x / 2);
// 	center_proj.y = bb.min.y + (dim_bb.y / 2);
// ft_printf("center proj x:%f, y:%f\n", center_proj.x, center_proj.y);
	// center_proj.x *= transform.scale;
	// center_proj.y *= transform.scale;

	// transform.dx = WINDOW_WIDTH / 2 - center_proj.x;
	// transform.dy = WINDOW_HIGTH / 2 - center_proj.y;


	transform.dx = (WINDOW_WIDTH - bb.max.x - bb.min.x) / 2;
	transform.dy = (WINDOW_HIGTH - bb.max.y - bb.min.y) / 2;
ft_printf("dx:%i, dy:%i\n", transform.dx, transform.dy);

	return (transform);
}

