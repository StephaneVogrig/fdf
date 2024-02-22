/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:07:46 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/21 04:17:22 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_BONUS_H
# define PIXEL_BONUS_H

# include "libft.h"

typedef struct s_pixel{
	union {
		t_vec2i		vec;
		struct {
			t_si32	x;
			t_si32	y;
		};
	};
	t_color	color;
}	t_pixel;

t_pixel	pixel(int x, int y, t_color color);

#endif