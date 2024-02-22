/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:52:24 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/13 07:06:13 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "fdf.h"
# include <stdio.h>

void	print_map_data(t_map map);
void	draw_sqare(t_img *img, int x, int y, int color);

#endif