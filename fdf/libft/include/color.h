/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:04:41 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/22 04:24:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "vs_type.h"

# define ARGB_WHITE 0x00ffffff
# define ARGB_RED 0x00ff0000
# define ARGB_BLUE 0x0000ff00
# define ARGB_GREEN 0x000000ff

typedef union u_color{
	t_ui32	ui;
	struct{
		t_ui8	b;
		t_ui8	g;
		t_ui8	r;
		t_ui8	a;
	};
}	t_color;

t_color		color(t_ui8 a, t_ui8 r, t_ui8 g, t_ui8 b);

#endif
