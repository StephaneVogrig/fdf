/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 06:42:19 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/22 07:28:02 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

inline void	zoom_decrease(t_fdf *fdf)
{
	fdf->transform.scale *= 0.95;
	render(fdf);
}

inline void	zoom_increase(t_fdf *fdf)
{
	fdf->transform.scale *= 1.05;
	render(fdf);
}
