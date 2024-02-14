/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:03:51 by stephane          #+#    #+#             */
/*   Updated: 2024/02/14 13:14:02 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "mlx_int.h"
# include "mlx.h"
# include "libft.h"
# include "pixel.h"
# include "color.h"

// test
# include <time.h>

# define FDF_BUFFER_SIZE 10
# define WINDOW_WIDTH 1600
# define WINDOW_HIGTH 900

# define DESTROY_NOTIFY 17
# define MOUSE_RIGHT 3
# define MOUSE_LEFT 1
# define MOUSE_MIDLE 2
# define MOUSE_ROLLUP 5
# define MOUSE_ROLLDOWN 4
# define MOUSE_BUTTON_PRESS 4
# define MOUSE_BUTTON_RELEASE 5
# define MOUSE_MOVE 6

# define ARGB_WHITE 0x00ffffff
# define ARGB_RED 0x00ff0000
# define ARGB_BLUE 0x0000ff00
# define ARGB_GREEN 0x000000ff

typedef struct s_data{
	int		z;
	t_ui32	color;
}	t_data;

typedef struct s_map{
	int			nbr_line;
	int			nbr_col;
	t_data		**datas;
	t_pixel		*buffer;
	t_bool		is_update;
}	t_map;

typedef struct s_transform{
	t_float64	scale;
	int			dx;
	int			dy;
	float		a1;
	float		a2;
	float		a3;
	float		b1;
	float		b2;
	float		b3;
}	t_transform;

typedef struct s_fdf{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_map		map;
	t_transform	transform;
	struct{
		t_ui8	left_button_is_press : 1;
		t_ui8	right_button_is_press : 1;
	};
	t_vec2i		last_mouse_pos;
}	t_fdf;

typedef struct s_bounding{
	t_vec2f	min;
	t_vec2f	max;
}	t_bound;

t_bound	bounding_box_2d(t_map *map, t_transform *transform);

/* draw-line ----------------------------------------------------------------*/
void		draw_line(t_img *img, t_pixel a, t_pixel b);

/* bresenham -----------------------------------------------------------------*/
void		draw_line_bresenham_y(t_img *img, t_pixel a, t_pixel b, t_vec2i d);
void		draw_line_bresenham_x(t_img *img, t_pixel a, t_pixel b, t_vec2i d);
void		bresenham(t_img *img, t_pixel a, t_pixel b, t_vec2i abs_d);

/* event ---------------------------------------------------------------------*/
int			on_key_press(int keycode, t_fdf *data);
int			on_mouse_move(int x, int y, t_fdf *data);
int			on_mouse_press(int button, int x, int y, t_fdf	*data);
int			on_mouse_release(int button, int x, int y, t_fdf *data);
void		event_setup(t_fdf *data);

/* exit ----------------------*-----------------------------------------------*/
void		exit_on_error(char *msg, t_fdf *data);
void		exit_fdf(t_fdf *data);

/* fdf -----------------------------------------------------------------------*/
void		fdf_init(t_fdf *fdf_var);
void		fdf_clean(t_fdf *fdf);

/* image ---------------------------------------------------------------------*/
void		img_clean(t_map *map, t_img *img, t_transform *transform);
void		img_clear(t_map *map, t_img *img, t_transform *transform);
void		img_set_pixel(t_img *img, int x, int y, t_ui32 color);

/* map to img ----------------------------------------------------------------*/
void		map_to_img(t_map *map, t_img *img, t_transform *transform);
t_pixel		projection(int x, int y, t_data data, t_transform *t);

/* map -----------------------------------------------------------------------*/
t_bool		map_load(char *path, t_map *map);

/* mlx -----------------------------------------------------------------------*/
t_bool		mlx_setup(t_fdf *data);

/* point2d -------------------------------------------------------------------*/
t_pixel		pixel(int x, int y, t_ui32 color);

/* render --------------------------------------------------------------------*/
int			render(t_fdf *data);

/* transform -----------------------------------------------------------------*/
t_transform	transform_init(t_map *map, t_img *img);

/* window --------------------------------------------------------------------*/
int			window_close(void *mlx);

/* window --------------------------------------------------------------------*/
void		zoom_increase(t_map *map, t_img *img, t_transform *transform);
void		zoom_decrease(t_map *map, t_img *img, t_transform *transform);

# include "debug.h"

#endif