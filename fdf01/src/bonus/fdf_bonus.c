/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:15:40 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/21 04:41:13 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

inline void	fdf_init(t_fdf *fdf)
{
	ft_bzero(fdf, sizeof(*fdf));
}

void	fdf_clean(t_fdf *fdf)
{
	if (fdf->img_mlx)
		mlx_destroy_image(fdf->mlx, fdf->img_mlx);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		free (fdf->mlx);
	}
	if (fdf->map.datas)
	{
		while (fdf->map.nbr_line--)
			free(fdf->map.datas[fdf->map.nbr_line]);
		free(fdf->map.datas);
	}
	if (fdf->map.buffer)
		free(fdf->map.buffer);
}

t_bool	mlx_setup(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
		return (error_msg("mlx_init: failed\n"));
	fdf->win = mlx_new_window(fdf->mlx, WINDOW_WIDTH, WINDOW_HIGTH, "fdf");
	if (fdf->win == NULL)
		return (error_msg("mlx_new_window: failed\n"));
	fdf->img_mlx = mlx_new_image(fdf->mlx, WINDOW_WIDTH, WINDOW_HIGTH);
	if (fdf->img_mlx == NULL)
		return (error_msg("mlx_new_image: failed\n"));
	return (SUCCESS);
}
