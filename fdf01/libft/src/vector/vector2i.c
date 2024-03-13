/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:24:20 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/13 00:41:56 by svogrig          ###   ########.fr       */
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
	t_vec2i	vector;

	vector.x = point_a.x - point_b.x;
	vector.y = point_a.y - point_b.y;
	return (vector);
}

inline t_vec2i	vector2i_add(t_vec2i point_a, t_vec2i point_b)
{
	t_vec2i	vector;

	vector.x = point_a.x + point_b.x;
	vector.y = point_a.y + point_b.y;
	return (vector);
}
