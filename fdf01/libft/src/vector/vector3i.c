/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:24:33 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/11 21:32:52 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

inline t_vec3i	vector3i(t_si32 x, t_si32 y, t_si32 z)
{
	t_vec3i	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

inline t_vec3i	vector3i_sub(t_vec3i point_a, t_vec3i point_b)
{
	t_vec3i	vector;

	vector.x = point_a.x - point_b.x;
	vector.y = point_a.y - point_b.y;
	vector.x = point_a.z - point_b.z;
	return (vector);
}

inline t_vec3i	vector3i_add(t_vec3i point_a, t_vec3i point_b)
{
	t_vec3i	vector;

	vector.x = point_a.x + point_b.x;
	vector.y = point_a.y + point_b.y;
	vector.x = point_a.z + point_b.z;
	return (vector);
}
