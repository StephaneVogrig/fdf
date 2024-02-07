/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:07:16 by stephane          #+#    #+#             */
/*   Updated: 2024/02/07 22:39:17 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	window_close(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

int	handle_keyevent(int keycode, t_fdf *data)
{
	if (keycode == 65307)
	{
		mlx_loop_end(data->mlx);
	}
	
	printf("key pressed: %d\n", keycode);
	return (0);	
}

void	img_set_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(int *)pixel = color;
}

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

void	img_clean(t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
			img_set_pixel(img, x++, y, 0);
		y++;
	}
}

int	handle_mouse_event(int button, int x, int y, t_fdf *data)
{
	if (button == MOUSE_LEFT)
		draw_sqare(data->img, x, y, 0x00FF0000);
	if (button == MOUSE_MIDLE)
		img_clean(data->img);
	printf("key pressed: %d\n", button);
	return (0);

}

int	render(t_fdf *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
int	on_mouse_move(int x, int y, t_fdf *data)
{
	if (data->left_button_is_press)
		draw_sqare(data->img, x, y, 0x00FF0000);
		// img_clean(data->img);
	ft_printf("move x:%i, y:%i, left_button: %d\n", x, y, data->left_button_is_press);
	return (0);
}

int	on_mouse_press(int button, int x, int y, t_fdf	*data)
{
	if (button == MOUSE_LEFT)
		data->left_button_is_press = TRUE;
	if (button == MOUSE_RIGHT)
		draw_sqare(data->img, x, y, 0x000000FF);
	ft_printf("press x:%i, y:%i, left_button: %d\n", x, y, data->left_button_is_press);
	return (0);
}

int	on_mouse_release(int button, int x, int y, t_fdf *data)
{
	if (button == MOUSE_LEFT)
		data->left_button_is_press = FALSE;
	if (button == MOUSE_MIDLE)
		img_clean(data->img);
	ft_printf("release x:%i, y:%i, left_button: %d\n", x, y, data->left_button_is_press);
	return (0);
}

void	event_setup(t_fdf *data)
{
	mlx_key_hook(data->win, &handle_keyevent, data);
	mlx_mouse_hook(data->win, &handle_mouse_event, data);
	mlx_hook(data->win, DESTROY_NOTIFY, 0, &window_close, data->mlx);
	mlx_hook(data->win, MOUSE_BUTTON_PRESS, 1L<<2, &on_mouse_press, data);
	mlx_hook(data->win, MOUSE_BUTTON_RELEASE, 1L<<3, &on_mouse_release, data);
	mlx_hook(data->win, MOUSE_MOVE, 1L<<6, &on_mouse_move, data);
	mlx_loop_hook(data->mlx, &render, data);
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
			event_setup(&data);
			mlx_loop(data.mlx);
		}
		ft_printf("img = size_line:%i, bpp:%i\n", data.img->size_line, data.img->bpp);
	}
	fdf_clean(&data);
	close(fd);
	return (0);
}
