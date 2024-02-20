/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:18:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/20 18:18:59 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	update_screen(t_fdf *fdf, clock_t ticks)
{
	char	str_nbr[12];
	char	*txt;

	mlx_string_put(fdf->mlx,fdf->win, 20,20,0xffffff, "Map :");
	txt = ft_itoa(fdf->map.nbr_col);
	mlx_string_put(fdf->mlx,fdf->win, 30,40,0xffffff, "width :");
	mlx_string_put(fdf->mlx,fdf->win, 100,40,0xffffff, txt);
	free(txt);
	txt = ft_itoa(fdf->map.nbr_line);
	mlx_string_put(fdf->mlx,fdf->win, 30,60,0xffffff, "hight :");
	mlx_string_put(fdf->mlx,fdf->win, 100,60,0xffffff, txt);
	free(txt);
	txt = si32_to_decstr_offset(str_nbr, (ticks) );
	*txt = '\0';
	mlx_string_put(fdf->mlx,fdf->win, 20, 100,0xffffff, "time to compute :");
	mlx_string_put(fdf->mlx,fdf->win, 30, 120,0xffffff, "ms :");
	mlx_string_put(fdf->mlx,fdf->win, 100, 120,0xffffff, str_nbr);
	txt = si32_to_decstr_offset(str_nbr, CLOCKS_PER_SEC / (ticks));
	*txt = '\0';
	mlx_string_put(fdf->mlx,fdf->win, 30, 140,0xffffff, "fps :");
	mlx_string_put(fdf->mlx,fdf->win, 100, 140,0xffffff, str_nbr);
}

int	render(t_fdf *fdf)
{
	clock_t begin;
	clock_t end;

	begin = clock();
	mlx_do_sync(fdf->mlx);
	img_clear(&fdf->map, fdf->img);
	map_to_img(&fdf->map, fdf->img, &fdf->transform);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	end = clock();
	// update_screen(fdf, end - begin);
	return (0);
}
