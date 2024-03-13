/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 05:24:11 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/22 22:13:31 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_IMG_H
# define FDF_IMG_H

# include "mlx_int.h"
# include "libft.h"
# include "color_gradient.h"

typedef struct s_fdf_img{
	int		size_line;
	int		bpp;
	int		width;
	int		height;
	char	*data;
}	t_fdf_img;

typedef struct s_bresenham {
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}	t_bresenham;

/* image ---------------------------------------------------------------------*/
void		image_init(t_img *img_mlx, t_fdf_img *img);
void		img_set_pixel(t_fdf_img *img, int x, int y, t_color color);

/* bresenham -----------------------------------------------------------------*/
void		bresenham(t_fdf_img *img, t_pixel a, t_pixel b, t_vec2i abs_d);

/* draw-line -----------------------------------------------------------------*/
void		draw_line(t_fdf_img *img, t_pixel a, t_pixel b);

#endif