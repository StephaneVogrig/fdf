/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:24:29 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/11 21:32:31 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

inline t_vec3f	vector3f(t_float32 x, t_float32 y, t_float32 z)
{
	t_vec3f	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

inline t_vec3f	vector3f_sub(t_vec3f point_a, t_vec3f point_b)
{
	t_vec3f	vector;

	vector.x = point_a.x - point_b.x;
	vector.y = point_a.y - point_b.y;
	vector.x = point_a.z - point_b.z;
	return (vector);
}

inline t_vec3f	vector3f_add(t_vec3f point_a, t_vec3f point_b)
{
	t_vec3f	vector;

	vector.x = point_a.x + point_b.x;
	vector.y = point_a.y + point_b.y;
	vector.x = point_a.z + point_b.z;
	return (vector);
}
