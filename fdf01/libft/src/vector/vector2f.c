/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:21:02 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/11 21:43:58 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

inline t_vec2f	vector2f(t_float32 x, t_float32 y)
{
	t_vec2f	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

inline t_vec2f	vector2f_sub(t_vec2f point_a, t_vec2f point_b)
{
	t_vec2f	vector;

	vector.x = point_a.x - point_b.x;
	vector.y = point_a.y - point_b.y;
	return (vector);
}

inline t_vec2f	vector2f_add(t_vec2f point_a, t_vec2f point_b)
{
	t_vec2f	vector;

	vector.x = point_a.x + point_b.x;
	vector.y = point_a.y + point_b.y;
	return (vector);
}
