/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:23:17 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/08 03:23:54 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_clean(t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
			img_set_pixel(img, x++, y, 0);
		y++;
	}
}

void	img_set_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(int *)pixel = color;
}