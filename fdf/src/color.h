/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:04:41 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/14 12:49:50 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "fdf.h"

typedef union u_color{
	t_ui32	argb;
	struct{
		t_ui8	b;
		t_ui8	g;
		t_ui8	r;
		t_ui8	a;
	};
}	t_color;

typedef struct s_gradiant{
	t_vec3f	gradiant;
	t_vec3f	accu;
	t_color	start;
}	t_gradiant;

t_ui32		color(t_ui8 a, t_ui8 r, t_ui8 g, t_ui8 b);
t_gradiant	color_gradiant(t_ui32 start, t_ui32 end, t_vec2i d);
t_ui32		color_gradiant_add(t_gradiant *grad);

#endif
