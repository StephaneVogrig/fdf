/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:24:59 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/21 20:07:51 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "vs_type.h"

typedef struct s_vec2d_int32{
	t_si32	x;
	t_si32	y;
}	t_vec2i;

t_vec2i	vector2i(t_si32 x, t_si32 y);
t_vec2i	vector2i_sub(t_vec2i point_a, t_vec2i point_b);
t_vec2i	vector2i_add(t_vec2i point_a, t_vec2i point_b);

typedef struct s_vec3d_int32{
	t_si32	x;
	t_si32	y;
	t_si32	z;
}	t_vec3i;

t_vec3i	vector3i(t_si32 x, t_si32 y, t_si32 z);
t_vec3i	vector3i_sub(t_vec3i point_a, t_vec3i point_b);
t_vec3i	vector3i_add(t_vec3i point_a, t_vec3i point_b);

typedef struct s_vec2_float32{
	t_float32	x;
	t_float32	y;
}	t_vec2f;

t_vec2f	vector2f(t_float32 x, t_float32 y);
t_vec2f	vector2f_sub(t_vec2f point_a, t_vec2f point_b);
t_vec2f	vector2f_add(t_vec2f point_a, t_vec2f point_b);

typedef struct s_vec3_float32{
	t_float32	x;
	t_float32	y;
	t_float32	z;
}	t_vec3f;

t_vec3f	vector3f(t_float32 x, t_float32 y, t_float32 z);
t_vec3f	vector3f_sub(t_vec3f point_a, t_vec3f point_b);
t_vec3f	vector3f_add(t_vec3f point_a, t_vec3f point_b);

typedef struct s_vec4_i32{
	t_si32	w;
	t_si32	x;
	t_si32	y;
	t_si32	z;
}	t_vec4i;

t_vec4i	vector4i(t_si32 w, t_si32 x, t_si32 y, t_si32 z);
t_vec4i	vector4i_sub(t_vec4i point_a, t_vec4i point_b);
t_vec4i	vector4i_add(t_vec4i point_a, t_vec4i point_b);

typedef struct s_vec4_float32{
	t_float32	w;
	t_float32	x;
	t_float32	y;
	t_float32	z;
}	t_vec4f;

t_vec4f	vector4f(t_float32 x, t_float32 y, t_float32 z, t_float32 w);
t_vec4f	vector4f_sub(t_vec4f point_a, t_vec4f point_b);
t_vec4f	vector4f_add(t_vec4f point_a, t_vec4f point_b);

#endif
