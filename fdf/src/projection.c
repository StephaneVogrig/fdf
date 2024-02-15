/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:54:34 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/15 12:20:00 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection_iso(t_transform *transform)
{
	transform->a1 = 0.71;
	transform->a2 = -0.71;
	transform->a3 = 0;
	transform->b1 = 0.41;
	transform->b2 = 0.41;
	transform->b3 = -0.82;
}

void	projection_plane(t_transform *transform)
{
	transform->a1 = 1;
	transform->a2 = 0;
	transform->a3 = 0;
	transform->b1 = 0;
	transform->b2 = 1;
	transform->b3 = 0;
}
