/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:50:49 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/21 19:12:36 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

inline t_vec4f	vector4f(t_float32 x, t_float32 y, t_float32 z, t_float32 w)
{
	t_vec4f	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = w;
	return (vector);
}

inline t_vec4f	vector4f_sub(t_vec4f point_a, t_vec4f point_b)
{
	t_vec4f	vector;

	vector.x = point_a.x - point_b.x;
	vector.y = point_a.y - point_b.y;
	vector.x = point_a.z - point_b.z;
	vector.w = point_a.w - point_b.w;
	return (vector);
}

inline t_vec4f	vector4f_add(t_vec4f point_a, t_vec4f point_b)
{
	t_vec4f	vector;

	vector.x = point_a.x + point_b.x;
	vector.y = point_a.y + point_b.y;
	vector.x = point_a.z + point_b.z;
	vector.w = point_a.w + point_b.w;
	return (vector);
}
