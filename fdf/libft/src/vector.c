/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:24:20 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/11 20:38:29 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2d	vector2d(t_vec2d point_a, t_vec2d point_b)
{
	t_vec2d	vector_a_to_b;

	vector_a_to_b.x = point_b.x - point_a.x;
	vector_a_to_b.y = point_b.y - point_a.y;
	return (vector_a_to_b);
}

t_vec3d	vector3d(t_vec3d point_a, t_vec3d point_b)
{
	t_vec3d	vector_a_to_b;

	vector_a_to_b.x = point_b.x - point_a.x;
	vector_a_to_b.y = point_b.y - point_a.y;
	vector_a_to_b.x = point_b.z - point_a.z;
	return (vector_a_to_b);
}