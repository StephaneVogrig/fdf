/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:07:16 by stephane          #+#    #+#             */
/*   Updated: 2024/02/10 20:22:35 by svogrig          ###   ########.fr       */
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
	if (fdf->map.data_lines)
		ft_lstclear(&fdf->map.data_lines, &free);
}

void	transform_setup(t_fdf *data)
{
	
}

void	fdf_init(t_fdf *fdf_var)
{
	fdf_var->mlx = NULL;
	fdf_var->win = NULL;
	fdf_var->img = NULL;
	fdf_var->left_button_is_press = FALSE;
	fdf_var->map.nbr_line = 0;
	fdf_var->map.nbr_col = 0;
	fdf_var->map.data_lines = NULL;
	fdf_var->map.calc = NULL;
}

void	print_map_data(t_map map)
{
	int	i;
	t_list	*node;
	t_data	*data_line;

	node = map.data_lines;

	ft_putstr_fd("loaded\n", STDOUT);
	while (node)
	{
		i = 0;
		while (i < map.nbr_col)
		{
			data_line = node->content;
			if (i == 0)
				ft_printf("%i", data_line[i].z);
			else
				ft_printf("%3i", data_line[i].z);
			if (data_line[i].color)
				ft_printf(",%#x", data_line[i].color);
			i++;
		}
		ft_putchar_fd('\n', STDOUT);
		node = node->next;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	fdf_var;
	t_bool	success;

	if (argc != 2)
		return (0);
	fdf_init(&fdf_var);
	success = map_load(argv[1], &fdf_var.map);
	// print_map_data(fdf_var.map);
	
	if (success)
		success = mlx_setup(&fdf_var);
	if (success)
	{
		// transform_setup(&fdf);
		event_setup(&fdf_var);
		mlx_loop(fdf_var.mlx);
	}
		// ft_printf("img = size_line:%i, bpp:%i\n", fdf.img->size_line, fdf.img->bpp);
	fdf_clean(&fdf_var);
	return (0);
}
