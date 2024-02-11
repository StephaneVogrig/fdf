/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:24:59 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/11 20:45:36 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "vs_type.h"

typedef struct s_vec2d_int{
	t_si32	x;
	t_si32	y;
}	t_vec2d;

typedef struct s_vec3d_int{
	t_si32	x;
	t_si32	y;
	t_si32	z;
}	t_vec3d;

t_vec2d	vector2d(t_vec2d point_a, t_vec2d point_b);
t_vec3d	vector3d(t_vec3d point_a, t_vec3d point_b);

#endif