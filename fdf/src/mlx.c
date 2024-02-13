/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:14:11 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/13 06:47:42 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bool	mlx_setup(t_fdf *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (error_msg("mlx_init: failed\n"));
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HIGTH, "fdf");
	if (data->win == NULL)
		return (error_msg("mlx_new_window: failed\n"));
	data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HIGTH);
	if (data->img == NULL)
		return (error_msg("mlx_new_image: failed\n"));
	return (SUCCESS);
}
