/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:03:51 by stephane          #+#    #+#             */
/*   Updated: 2024/02/22 22:13:15 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "color_gradient.h"
# include "map.h"
# include "fdf_img.h"

# define WINDOW_WIDTH 1600
# define WINDOW_HIGTH 900

# define DESTROY_NOTIFY 17

# define ON_KEY_PRESS 2

# define KEY_ESC 65307

typedef struct s_transform{
	t_vec2f	offset_map;
	float	scale;
	float	dx;
	float	dy;
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

/* event ---------------------------------------------------------------------*/
void		event_setup(t_fdf *fdf);

/* fdf -----------------------------------------------------------------------*/
void		fdf_init(t_fdf *fdf);
void		fdf_clean(t_fdf *fdf);
t_bool		mlx_setup(t_fdf *fdf);

/* image ---------------------------------------------------------------------*/

/* map to img ----------------------------------------------------------------*/
void		map_to_img(t_map *map, t_fdf_img *img, t_transform *transform);

/* transform -----------------------------------------------------------------*/
t_vec2f		compute_point(float x, float y, float z, t_transform *t);
void		transform_init(t_transform *transform, t_map *map, t_fdf_img *img);

#endif