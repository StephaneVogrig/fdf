/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:15:40 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/17 19:54:01 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

void	fdf_init(t_fdf *fdf)
{
	ft_bzero(fdf, sizeof(*fdf));
// ft_printf("sizeof fdf:%i\n", sizeof(*fdf));
	// fdf->mlx = NULL;
	// fdf->win = NULL;
	// fdf->img = NULL;
	// fdf->left_button_is_press = 0;
	// fdf->right_button_is_press = 0;
	// fdf->last_mouse_pos = vector2i(0, 0);
	// fdf->map.nbr_line = 0;
	// fdf->map.nbr_col = 0;
	// fdf->map.datas = NULL;
	// fdf->map.buffer = NULL;
	// fdf->map.is_update = FALSE;
	// fdf->transform.offset_map.x = 0.0;
	// fdf->transform.offset_map.y = 0.0;
	// fdf->transform.scale = 0.0;
	// fdf->transform.dx = 0;
	// fdf->transform.dy = 0;
	// fdf->transform.a1 = 0.0;
	// fdf->transform.a2 = 0.0;
	// fdf->transform.a3 = 0.0;
	// fdf->transform.b1 = 0.0;
	// fdf->transform.b2 = 0.0;
	// fdf->transform.b3 = 0.0;
	// fdf->transform.c1 = 0.0;
	// fdf->transform.c2 = 0.0;
	// fdf->transform.c3 = 0.0;
	// fdf->transform.scale_z = 1.0;
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
