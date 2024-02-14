/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:04:41 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/14 01:50:36 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "libft.h"

typedef union u_color{
	t_ui32	argb;
	struct{
		t_ui32	a : 8;
		t_ui32	r : 8;
		t_ui32	g : 8;
		t_ui32	b : 8;
	};
}	t_color;

t_ui32	color(t_ui8 a, t_ui8 r, t_ui8 g, t_ui8 b);

#endif
