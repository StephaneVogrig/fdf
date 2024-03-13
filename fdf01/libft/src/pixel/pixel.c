/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:47:57 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/22 03:32:29 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pixel.h"

t_pixel	pixel(int x, int y, t_color color)
{
	t_pixel	pix;

	pix.x = x;
	pix.y = y;
	pix.color = color;
	return (pix);
}
