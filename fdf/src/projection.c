/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:54:34 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/18 21:38:46 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

void	projection_gen(t_transform *transform, t_vec3f rot)
{
	t_vec3f	c;
	t_vec3f	s;
	float	cx_sy;
	float	sx_sy;

	rot.x *= M_PI / 180;
	rot.y *= M_PI / 180;
	rot.z *= M_PI / 180;
	c.x = cos(rot.x);
	s.x = sin(rot.x);
	c.y = cos(rot.y);
	s.y = sin(rot.y);
	c.z = cos(rot.z);
	s.z = sin(rot.z);
	cx_sy = c.x * s.y;
	sx_sy = s.x * s.y;


	transform->a1 = c.y * c.z;
	transform->a2 = -c.y * s.z;
	transform->a3 = s.y;

	transform->b1 = c.x * s.z + c.z * sx_sy;
	transform->b2 = c.x * c.z - sx_sy * s.z;
	transform->b3 = -c.y * s.x;

	transform->c1 = s.x * s.z - cx_sy * c.z;
	transform->c2 = c.z * s.x + cx_sy * s.z;
	transform->c3 = c.x * c.y;
}

void	projection_iso(t_transform *transform)
{
	transform->a1 = 0.71;
	transform->a2 = -0.71;
	transform->a3 = 0;
	transform->b1 = 0.41;
	transform->b2 = 0.41;
	transform->b3 = -0.82;
	transform->c1 = 0;
	transform->c2 = 0;
	transform->c3 = 0;
}

void	projection_plane(t_transform *transform)
{
	transform->a1 = 1;
	transform->a2 = 0;
	transform->a3 = 0;
	transform->b1 = 0;
	transform->b2 = 1;
	transform->b3 = 0;
	transform->c1 = 0;
	transform->c2 = 0;
	transform->c3 = 1;
}
