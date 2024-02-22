/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:03:51 by stephane          #+#    #+#             */
/*   Updated: 2024/02/21 03:48:48 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "mlx_int.h"
# include "mlx.h"
# include "libft.h"
# include "color.h"
# include "pixel.h"

# define WINDOW_WIDTH 1600
# define WINDOW_HIGTH 900

# define DESTROY_NOTIFY 17

# define ON_KEY_PRESS 2

# define KEY_ESC 65307

# define ARGB_WHITE 0x00ffffff

typedef struct s_fdf_img{
	int		size_line;
	int		bpp;
	int		width;
	int		height;
	char	*data;
}	t_fdf_img;

typedef struct s_data{
	int		z;
	t_color	color;
}	t_data;

typedef struct s_map{
	int			nbr_line;
	int			nbr_col;
	t_data		**datas;
	t_pixel		*buffer;
	t_bool		is_update;
}	t_map;

typedef struct s_transform{
	t_vec2f	offset_map;
	float	scale;
	int		dx;
	int		dy;
}	t_transform;

typedef struct s_fdf{
	void		*mlx;
	void		*win;
	t_img		*img_mlx;
	t_fdf_img	img;
	t_map		map;
	t_transform	transform;
}	t_fdf;

typedef struct s_bounding{
	t_vec2f	min;
	t_vec2f	max;
}	t_bound;

typedef struct s_bresenham {
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_bresenham;

/* bresenham -----------------------------------------------------------------*/
void		bresenham(t_fdf_img *img, t_pixel a, t_pixel b, t_vec2i abs_d);

/* draw-line -----------------------------------------------------------------*/
void		draw_line(t_fdf_img *img, t_pixel a, t_pixel b);

/* event ---------------------------------------------------------------------*/
void		event_setup(t_fdf *fdf);

/* fdf -----------------------------------------------------------------------*/
void		fdf_init(t_fdf *fdf);
void		fdf_clean(t_fdf *fdf);
t_bool		mlx_setup(t_fdf *fdf);

/* image ---------------------------------------------------------------------*/
void		image_init(t_img *img_mlx, t_fdf_img *img);
void		img_set_pixel(t_fdf_img *img, int x, int y, t_color color);

/* map to img ----------------------------------------------------------------*/
void		map_to_img(t_map *map, t_fdf_img *img, t_transform *transform);

/* map_load ------------------------------------------------------------------*/
t_bool		map_load(char *path, t_map *map);

/* transform -----------------------------------------------------------------*/
t_vec2f		compute_point(float x, float y, t_data data, t_transform *t);
void		transform_init(t_transform *transform, t_map *map, t_fdf_img *img);

#endif