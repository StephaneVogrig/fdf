/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:23:17 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/22 05:47:10 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	image_init(t_img *img_mlx, t_fdf_img *img)
{
	img->size_line = img_mlx->size_line;
	img->bpp = img_mlx->bpp >> 3;
	img->width = img_mlx->width;
	img->height = img_mlx->height;
	img->data = img_mlx->data;
}

inline void	img_set_pixel(t_fdf_img *img, int x, int y, t_color color)
{
	if (0 <= x && x < img->width && 0 <= y && y < img->height)
		*(t_ui32 *)(img->data + y * img->size_line + x * (img->bpp)) = color.ui;
}
