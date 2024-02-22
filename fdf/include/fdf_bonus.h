/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:03:51 by stephane          #+#    #+#             */
/*   Updated: 2024/02/22 22:11:47 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <time.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "color_gradient.h"
# include "map_bonus.h"
# include "fdf_img.h"

# define WINDOW_WIDTH 1600
# define WINDOW_HIGTH 900

# define MOVE_STEP 5

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
# define KEY_SPACE 32

# define KEY_F1 65470
# define KEY_F2 65471
# define KEY_F3 65472
# define KEY_F4 65473
# define KEY_F5 65474
# define KEY_F6 65475
# define KEY_F7 65476

# define NUMPAD_KEY_4 65430
# define NUMPAD_KEY_8 65431
# define NUMPAD_KEY_6 65432
# define NUMPAD_KEY_2 65433
# define NUMPAD_KEY_5 65437
# define NUMPAD_KEY_MORE 65451
# define NUMPAD_KEY_MINUS 65453
# define NUMPAD_KEY_ENTER 65421
# define NUMPAD_KEY_SLASH 65455

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

typedef struct s_multi_gradient{
	t_grad	a;
	t_grad	b;
	t_grad	c;
}	t_multigrad;

/* color game ----------------------------------------------------------------*/
void	color_game(t_fdf *fdf, int keycode);
void	set_origin_color(t_map *map, t_data **datas);
void	set_earth_color(t_map *map, t_data **datas);

/* color gradient ------------------------------------------------------------*/
t_color	col_grad_step(t_grad grad, int step);
t_grad	grad_step(t_ui32 start, t_ui32 end, int step);
t_color	earth(t_multigrad grad, int z, int z_max);

/* event ---------------------------------------------------------------------*/
int		on_key_press(int keycode, t_fdf *fdf);
void	event_setup(t_fdf *fdf);

/* event mouse ---------------------------------------------------------------*/
int		on_mouse_move(int x, int y, t_fdf *fdf);
int		on_mouse_press(int button, int x, int y, t_fdf	*data);
int		on_mouse_release(int button, int x, int y, t_fdf *fdf);

/* fdf -----------------------------------------------------------------------*/
void	fdf_init(t_fdf *fdf);
void	fdf_clean(t_fdf *fdf);
t_bool	mlx_setup(t_fdf *fdf);

/* image ---------------------------------------------------------------------*/
void	img_clear(t_fdf_img *img);

/* map earth -----------------------------------------------------------------*/
void	map_earth_size(t_fdf *fdf);

/* map to img ----------------------------------------------------------------*/
void	map_to_img(t_map *map, t_fdf_img *img, t_transform *transform);

/* map transform -------------------------------------------------------------*/
void	map_move_keyboard(t_fdf *fdf, int keycode);
void	map_rot_x_keyboard(t_fdf *fdf, int keycode);
void	map_rot_z_keyboard(t_fdf *fdf, int keycode);
void	map_scale_z(t_fdf *fdf, int keycode);
void	map_resize(t_fdf *fdf);

/* projection ----------------------------------------------------------------*/
void	projection(t_fdf *fdf, int keycode);
void	projection_iso(t_transform *transform);
void	projection_flat(t_transform *transform);
void	projection_gen(t_transform *transform, t_vec3f rot);

/* render --------------------------------------------------------------------*/
int		render(t_fdf *fdf);
void	update_screen(t_fdf *fdf, clock_t ticks);

/* transform -----------------------------------------------------------------*/
void	transform_init(t_transform *transform, t_map *map, t_fdf_img *img);
void	transform_resize(t_transform *t, t_map *map, t_fdf_img *img);
t_vec2f	compute_point(float x, float y, float z, t_transform *t);

/* z -------------------------------------------------------------------------*/
void	z_scale_10(t_fdf *fdf);
void	find_minmax_z(t_map *map, t_data **datas);

/* zoom ----------------------------------------------------------------------*/
void	zoom_increase(t_fdf *fdf);
void	zoom_decrease(t_fdf *fdf);

#endif