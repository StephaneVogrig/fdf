/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:03:51 by stephane          #+#    #+#             */
/*   Updated: 2024/02/07 22:30:14 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include "mlx_int.h"
# include "mlx.h"
# include "libft.h"

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

typedef struct s_fdf{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_bool	left_button_is_press;
} t_fdf;

void	exit_on_error(char *msg, t_fdf *data);
void	exit_fdf(t_fdf *data);

#endif