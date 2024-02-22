/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:03:51 by stephane          #+#    #+#             */
/*   Updated: 2024/02/22 00:11:37 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <time.h>
# include <math.h>
# include "mlx_int.h"
# include "mlx.h"
# include "libft.h"
# include "color_bonus.h"
# include "pixel_bonus.h"

# define WINDOW_WIDTH 1600
# define WINDOW_HIGTH 900

# define DESTROY_NOTIFY 17

# define MOUSE_BUTTON_PRESS 4
# define MOUSE_BUTTON_RELEASE 5
# define MOUSE_MOVE 6

# define MOUSE_RIGHT 3
# define MOUSE_LEFT 1
# define MOUSE_MIDLE 2
# define MOUSE_ROLLUP 5
# define MOUSE_ROLLDOWN 4

# define ON_KEY_PRESS 2
# define ON_KEY_RELEASE 3

# define KEY_ESC 65307
# define KEY_LEFT_ARROW 65361
# define KEY_UP_ARROW 65362
# define KEY_RIGHT_ARROW 65363
# define KEY_DOWN_ARROW 65364
# define KEY_PGUP 65365
# define KEY_PGDOWN 65366

# define NUMPAD_KEY_4 65430
# define NUMPAD_KEY_8 65431
# define NUMPAD_KEY_6 65432
# define NUMPAD_KEY_2 65433

# define MOVE_STEP 5
# define ARGB_WHITE 0x00ffffff
# define ARGB_RED 0x00ff0000
# define ARGB_BLUE 0x0000ff00
# define ARGB_GREEN 0x000000ff

typedef struct s_bresenham {
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}	t_bresenham;

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
	t_vec3f	rot;
	float	scale;
	float	dx;
	float	dy;
	float	a1;
	float	a2;
	float	a3;
	float	b1;
	float	b2;
	float	b3;
	float	c1;
	float	c2;
	float	c3;
	float	scale_z;
}	t_transform;

typedef struct s_fdf{
	void		*mlx;
	void		*win;
	t_img		*img_mlx;
	t_fdf_img	img;
	t_map		map;
	t_transform	transform;
	struct{
		t_ui8	left_button_is_press : 1;
		t_ui8	right_button_is_press : 1;
	};
	t_ui64		key_pressed;
	t_vec2i		mouse_origin;
}	t_fdf;

typedef struct s_bounding{
	t_vec2f	min;
	t_vec2f	max;
}	t_bound;

t_bound		bounding_box_2d(t_map *map, t_transform *transform);

/* draw-line ----------------------------------------------------------------*/
void		draw_line(t_fdf_img *img, t_pixel a, t_pixel b);

/* bresenham -----------------------------------------------------------------*/
void		draw_line_bresenham_y(t_fdf_img *img, t_pixel a, t_pixel b, t_vec2i d);
void		draw_line_bresenham_x(t_fdf_img *img, t_pixel a, t_pixel b, t_vec2i d);
void		bresenham(t_fdf_img *img, t_pixel a, t_pixel b, t_vec2i abs_d);

/* event ---------------------------------------------------------------------*/
int			on_key_press(int keycode, t_fdf *fdf);
int			on_mouse_move(int x, int y, t_fdf *fdf);
int			on_mouse_press(int button, int x, int y, t_fdf	*data);
int			on_mouse_release(int button, int x, int y, t_fdf *fdf);
void		event_setup(t_fdf *fdf);

/* exit ----------------------*-----------------------------------------------*/
void		exit_on_error(char *msg, t_fdf *fdf);
void		exit_fdf(t_fdf *fdf);

/* fdf -----------------------------------------------------------------------*/
void		fdf_init(t_fdf *fdf);
void		fdf_clean(t_fdf *fdf);

/* image ---------------------------------------------------------------------*/
void		image_init(t_img *img_mlx, t_fdf_img *img);
void		img_clean(t_map *map, t_fdf_img *img, t_transform *transform);
void		img_clear(t_map *map, t_fdf_img *img);
void		img_set_pixel(t_fdf_img *img, int x, int y, t_color color);

/* map to img ----------------------------------------------------------------*/
void		map_to_img(t_map *map, t_fdf_img *img, t_transform *transform);
t_pixel		projection(int x, int y, t_data data, t_transform *t);

/* map -----------------------------------------------------------------------*/
t_bool		map_load(char *path, t_map *map);
void		map_move_keyboard(t_fdf *fdf, int keycode);
void		map_move_mouse(t_fdf *fdf, int keycode);
void		map_rot_x_keyboard(t_fdf *fdf, int keycode);
void		map_rot_z_keyboard(t_fdf *fdf, int keycode);
void		map_scale_z(t_fdf *fdf, int keycode);

/* mlx -----------------------------------------------------------------------*/
t_bool		mlx_setup(t_fdf *fdf);

/* point2d -------------------------------------------------------------------*/
t_pixel		pixel(int x, int y, t_color color);

/* projection ----------------------------------------------------------------*/
void		projection_iso(t_transform *transform);
void		projection_plane(t_transform *transform);
void		projection_gen(t_transform *transform, t_vec3f rot);

/* render --------------------------------------------------------------------*/
int			render(t_fdf *fdf);
void		update_screen(t_fdf *fdf, clock_t ticks);

/* transform -----------------------------------------------------------------*/
void		transform_init(t_transform *transform, t_map *map, t_fdf_img *img);
t_vec2f		compute_point(float x, float y, float z, t_transform *t);
// t_vec2f		compute_point(int x, int y, int z, t_transform *t);
/* zoom ----------------------------------------------------------------------*/
void		zoom_increase(t_fdf *fdf, int x, int y);
void		zoom_decrease(t_fdf *fdf);

#endif