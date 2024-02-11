/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:24:20 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/11 21:42:04 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

inline t_vec2i	vector2i(t_si32 x, t_si32 y)
{
	t_vec2i	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

inline t_vec2i	vector2i_sub(t_vec2i point_a, t_vec2i point_b)
{
	t_vec2i	vector_a_to_b;

	vector_a_to_b.x = point_b.x - point_a.x;
	vector_a_to_b.y = point_b.y - point_a.y;
	return (vector_a_to_b);
}

inline t_vec2i	vector2i_add(t_vec2i point_a, t_vec2i point_b)
{
	t_vec2i	vector;

	vector.x = point_a.x + point_b.x;
	vector.y = point_a.y + point_b.y;
	return (vector);
}
