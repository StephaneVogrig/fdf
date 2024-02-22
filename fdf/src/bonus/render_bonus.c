/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:18:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/22 07:07:10 by svogrig          ###   ########.fr       */
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

void	update_screen(t_fdf *fdf, clock_t ticks)
{
	char	str_nbr[12];
	char	*txt;
	clock_t	delay;

	delay = clock() - ticks;
	mlx_string_put(fdf->mlx, fdf->win, 20, 20, 0xffffff, "Map :");
	mlx_string_put(fdf->mlx, fdf->win, 30, 40, 0xffffff, "width :");
	put_nbr_on_img(fdf->map.nbr_col, fdf, 100, 40);
	mlx_string_put(fdf->mlx, fdf->win, 30, 60, 0xffffff, "height :");
	put_nbr_on_img(fdf->map.nbr_line, fdf, 100, 60);
	mlx_string_put(fdf->mlx, fdf->win, 20, 100, 0xffffff, "time to compute :");
	mlx_string_put(fdf->mlx, fdf->win, 30, 120, 0xffffff, "ticks :");
	put_nbr_on_img(delay, fdf, 100, 120);
	mlx_string_put(fdf->mlx, fdf->win, 30, 140, 0xffffff, "ms :");
	put_nbr_on_img((delay + 500) / 1000, fdf, 100, 140);
	mlx_string_put(fdf->mlx, fdf->win, 30, 160, 0xffffff, "fps :");
	if (delay > 0)
		put_nbr_on_img(CLOCKS_PER_SEC / delay, fdf, 100, 160);
	else
		mlx_string_put(fdf->mlx, fdf->win, 100, 160, 0xffffff, "-");
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
