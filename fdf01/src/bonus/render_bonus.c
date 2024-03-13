/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:18:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/22 22:36:57 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	put_nbr_on_img(int nbr, t_fdf *fdf, int x, int y)
{
	char	str_nbr[16];
	char	*txt;

	ft_bzero(str_nbr, 16);
	txt = si32_to_decstr_offset(str_nbr, nbr);
	mlx_string_put(fdf->mlx, fdf->win, x, y, 0xffffff, str_nbr);
}

void	update_controls(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 20, 560, 0xffffff, "Controls ---------");
	mlx_string_put(fdf->mlx, fdf->win, 30, 580, 0xffffff, "F1    origin color");
	mlx_string_put(fdf->mlx, fdf->win, 30, 600, 0xffffff, "F2     earth color");
	mlx_string_put(fdf->mlx, fdf->win, 30, 620, 0xffffff, "F3      mars color");
	mlx_string_put(fdf->mlx, fdf->win, 30, 640, 0xffffff, "F4      none color");
	mlx_string_put(fdf->mlx, fdf->win, 30, 660, 0xffffff, "F5        isometic");
	mlx_string_put(fdf->mlx, fdf->win, 30, 680, 0xffffff, "F6            flat");
	mlx_string_put(fdf->mlx, fdf->win, 30, 700, 0xffffff, "F7        paralell");
	mlx_string_put(fdf->mlx, fdf->win, 30, 720, 0xffffff, "5	       center");
	mlx_string_put(fdf->mlx, fdf->win, 30, 740, 0xffffff, "2,4,6,8     rotate");
	mlx_string_put(fdf->mlx, fdf->win, 30, 760, 0xffffff, "<-,->    translate");
	mlx_string_put(fdf->mlx, fdf->win, 30, 780, 0xffffff, "+,-           zoom");
	mlx_string_put(fdf->mlx, fdf->win, 30, 800, 0xffffff, "enter        earth");
	mlx_string_put(fdf->mlx, fdf->win, 30, 820, 0xffffff, "PgUp,PgDn  scale z");
	mlx_string_put(fdf->mlx, fdf->win, 30, 840, 0xffffff, "/           z / 10");
}

void	update_screen(t_fdf *fdf, clock_t ticks)
{
	clock_t	delay;

	delay = clock() - ticks;
	mlx_string_put(fdf->mlx, fdf->win, 20, 20, 0xffffff, "Map --------------");
	mlx_string_put(fdf->mlx, fdf->win, 30, 40, 0xffffff, "width :");
	put_nbr_on_img(fdf->map.nbr_col, fdf, 90, 40);
	mlx_string_put(fdf->mlx, fdf->win, 30, 60, 0xffffff, "height :");
	put_nbr_on_img(fdf->map.nbr_line, fdf, 90, 60);
	mlx_string_put(fdf->mlx, fdf->win, 30, 80, 0xffffff, "z max :");
	put_nbr_on_img(fdf->map.z_max, fdf, 90, 80);
	mlx_string_put(fdf->mlx, fdf->win, 30, 100, 0xffffff, "z min :");
	put_nbr_on_img(fdf->map.z_min, fdf, 90, 100);
	mlx_string_put(fdf->mlx, fdf->win, 20, 140, 0xffffff, "Time to compute -");
	mlx_string_put(fdf->mlx, fdf->win, 30, 160, 0xffffff, "ticks :");
	put_nbr_on_img(delay, fdf, 90, 160);
	mlx_string_put(fdf->mlx, fdf->win, 30, 180, 0xffffff, "ms :");
	put_nbr_on_img((delay + 500) / 1000, fdf, 90, 180);
	mlx_string_put(fdf->mlx, fdf->win, 30, 200, 0xffffff, "fps :");
	if (delay > 0)
		put_nbr_on_img(CLOCKS_PER_SEC / delay, fdf, 90, 200);
	else
		mlx_string_put(fdf->mlx, fdf->win, 90, 200, 0xffffff, "-");
	update_controls(fdf);
}

inline void	img_clear(t_fdf_img *img)
{
	ft_bzero(img->data, img->size_line * img->height);
}

int	render(t_fdf *fdf)
{
	clock_t	begin;

	begin = clock();
	mlx_do_sync(fdf->mlx);
	img_clear(&fdf->img);
	map_to_img(&fdf->map, &fdf->img, &fdf->transform);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img_mlx, 0, 0);
	update_screen(fdf, begin);
	return (0);
}
