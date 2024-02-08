/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:07:16 by stephane          #+#    #+#             */
/*   Updated: 2024/02/08 03:23:51 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_sqare(t_img *img, int x, int y, int color)
{
	int	x_max;
	int	y_max;
	int	xx;

	if (x < 0 || y < 0 || x >= WINDOW_WIDTH || y > WINDOW_HIGTH)
		return ;
	x_max = x + 10;
	if (x_max >= WINDOW_WIDTH)
		x_max = WINDOW_WIDTH - 1;
	y_max = y + 10;
	if (y_max >= WINDOW_HIGTH)
		y_max = WINDOW_HIGTH - 1;
	while (y < y_max)
	{
		xx = x;
		while (xx < x_max)
		{
			img_set_pixel(img, xx, y, color);
			xx++;
		}
		y++;
	}
	// ft_printf("x: %i, y: %i\n", x, y);
}

t_bool	fdf_setup(t_fdf *data)
{
	data->win = NULL;
	data->img = NULL;
	data->left_button_is_press = FALSE;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_putstr_fd("mlx_init: failed\n", STDERR);
		return (ERROR);
	}
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HIGTH, "fdf");
	if (data->win == NULL)
	{
		ft_putstr_fd("mlx_new_window: failed\n", STDERR);
		return (ERROR);
	}
	data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HIGTH);
	if (data->img == NULL)
	{
		ft_putstr_fd("mlx_new_image: failed\n", STDERR);
		return (ERROR);
	}
	return (SUCCESS);
}

void	fdf_clean(t_fdf *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free (data->mlx);
}

t_bool	map_setup(int fd, t_fdf *data)
{
	return (SUCCESS);
}

void	transform_setup(t_fdf *data)
{
	
}

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	data;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		return (0);
	}
	if (fdf_setup(&data))
	{
		if (map_setup(fd, &data))
		{
			transform_setup(&data);
			event_setup(&data);
			mlx_loop(data.mlx);
		}
		ft_printf("img = size_line:%i, bpp:%i\n", data.img->size_line, data.img->bpp);
	}
	fdf_clean(&data);
	close(fd);
	return (0);
}
