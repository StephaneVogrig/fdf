/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 06:42:19 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/24 03:39:39 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	compute_transform(t_transform *t, float f_scale, int x, int y)
{
	t->dx = x - (x - t->dx) * f_scale;
	t->dy = y - (y - t->dy) * f_scale;
	t->scale *= f_scale;
}

inline void	zoom_decrease(t_fdf *fdf, int x, int y)
{
	compute_transform(&fdf->transform, 0.95, x, y);
	render(fdf);
}

inline void	zoom_increase(t_fdf *fdf, int x, int y)
{
	compute_transform(&fdf->transform, 1.05, x, y);
	render(fdf);
}
