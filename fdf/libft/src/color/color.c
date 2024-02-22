/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 03:03:57 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/22 19:24:54 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

inline	t_color	color(t_ui8 a, t_ui8 r, t_ui8 g, t_ui8 b)
{
	t_color	color;

	color.a = a;
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}
