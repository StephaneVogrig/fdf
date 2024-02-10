/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:03:51 by stephane          #+#    #+#             */
/*   Updated: 2024/02/10 17:52:44 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "mlx_int.h"
# include "mlx.h"
# include "libft.h"

# define FDF_BUFFER_SIZE 8192
# define WINDOW_WIDTH 800
# define WINDOW_HIGTH 450

# define DESTROY_NOTIFY 17
# define MOUSE_RIGHT 3
# define MOUSE_LEFT 1
# define MOUSE_MIDLE 2
# define MOUSE_ROLLUP 5
# define MOUSE_ROLLDOWN 4
# define MOUSE_BUTTON_PRESS 4
# define MOUSE_BUTTON_RELEASE 5
# define MOUSE_MOVE 6

typedef	struct s_vec2d{
	int	x;
	int y;
}	t_vec2d;

typedef struct s_data{
	int	z;
	int	color;
}	t_data;

typedef struct s_calc{
	int	x;
	int	y;
	int	z;
}	t_calc;

typedef struct s_map{
	int		nbr_line;
	int		nbr_col;
	t_list	*data_lines;
	t_calc	*calc;
} t_map;

typedef struct s_fdf{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_bool	left_button_is_press;
	t_map	map;
} t_fdf;

typedef struct s_point2d{
	union {
		t_ui64	vec;
		struct {
			t_ui32	x;
			t_ui32	y;
		};
	};
	t_ui32	color;
} t_point2d;

void		exit_on_error(char *msg, t_fdf *data);
void		exit_fdf(t_fdf *data);
t_point2d	point2d(int x, int y, int color);

int			render(t_fdf *data);

void		draw_line(t_img *img, t_point2d a, t_point2d b);

int			window_close(void *mlx);

int			on_key_press(int keycode, t_fdf *data);
int			on_mouse_move(int x, int y, t_fdf *data);
int			on_mouse_press(int button, int x, int y, t_fdf	*data);
int			on_mouse_release(int button, int x, int y, t_fdf *data);
void		event_setup(t_fdf *data);

void		draw_line_bresenham_y(t_img *img, t_point2d a, t_point2d b, t_vec2d d);
void		draw_line_bresenham_x(t_img *img, t_point2d a, t_point2d b, t_vec2d d);

t_bool		map_load(char *path,  t_map *map);
t_bool		map_setup(char	*path, t_fdf *data);

void		img_clean(t_img *img);
void		img_set_pixel(t_img *img, int x, int y, int color);

// a enlever

void	draw_sqare(t_img *img, int x, int y, int color);

#endif