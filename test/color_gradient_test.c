/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:47:29 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/14 12:51:55 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_gradient_test(t_img *img)
{
	t_pixel	start;
	t_pixel	end;
	t_pixel	current;
	t_vec2i		delta;

	start = pixel(100, 100, color(0,0,0,0));
	start.color = 
	delta = vector2i_sub(end.vec2i, start.vec2i);
	current.vec2i = start.vec2i;
	while (current.y <= end.y)
	{
		current.x = start.x;
		while (current.x <= end.x)
		{
			// current.color = color_gradient(start, end, 
			current.x++;
		}
		current.y++;
	}
}