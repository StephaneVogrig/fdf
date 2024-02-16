/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:15:40 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/16 01:33:15 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init(t_fdf *fdf_var)
{
	ft_bzero(fdf_var, sizeof(*fdf_var));
ft_printf("sizeof fdf_var:%i\n", sizeof(*fdf_var));
	// fdf_var->mlx = NULL;
	// fdf_var->win = NULL;
	// fdf_var->img = NULL;
	// fdf_var->left_button_is_press = 0;
	// fdf_var->right_button_is_press = 0;
	// fdf_var->last_mouse_pos = vector2i(0, 0);
	// fdf_var->map.nbr_line = 0;
	// fdf_var->map.nbr_col = 0;
	// fdf_var->map.datas = NULL;
	// fdf_var->map.buffer = NULL;
	// fdf_var->map.is_update = FALSE;
	// fdf_var->transform.offset_map.x = 0.0;
	// fdf_var->transform.offset_map.y = 0.0;
	// fdf_var->transform.scale = 0.0;
	// fdf_var->transform.dx = 0;
	// fdf_var->transform.dy = 0;
	// fdf_var->transform.a1 = 0.0;
	// fdf_var->transform.a2 = 0.0;
	// fdf_var->transform.a3 = 0.0;
	// fdf_var->transform.b1 = 0.0;
	// fdf_var->transform.b2 = 0.0;
	// fdf_var->transform.b3 = 0.0;
	// fdf_var->transform.c1 = 0.0;
	// fdf_var->transform.c2 = 0.0;
	// fdf_var->transform.c3 = 0.0;
	// fdf_var->transform.scale_z = 1.0;
}

void	fdf_clean(t_fdf *fdf)
{
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
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
