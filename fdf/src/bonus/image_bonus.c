/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:23:17 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/21 18:52:24 by svogrig          ###   ########.fr       */
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
// ft_printf("mlx sizeline:%i bpp:%i width:%i heigth:%i\n", img_mlx->size_line, img_mlx->bpp, img_mlx->width, img_mlx->height);
// ft_printf("img sizeline:%i bpp:%i width:%i heigth:%i\n", img->size_line, img->bpp, img->width, img->height);
}

inline void	img_set_pixel(t_fdf_img *img, int x, int y, t_color color)
{
	if (0 <= x && x < img->width && 0 <= y && y < img->height)
		*(t_ui32 *)(img->data + y * img->size_line + x * (img->bpp)) = color.ui;
}

void	img_clear(t_map *map, t_fdf_img *img)
{
	ft_bzero(img->data, img->size_line * img->height);
}
