/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:07:16 by stephane          #+#    #+#             */
/*   Updated: 2024/02/04 22:47:47 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

int	handle_keyevent(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_loop_end(data->mlx);
	}
	
	printf("key pressed: %d\n", keycode);
	return (0);	
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (0);
	// printf("data.mlx: %p\n", data.mlx);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGTH, "fdf");
	if (data.win == NULL)
		return (0);
	data.img = mlx_new_img(data.mlx, WINDOW_WIDTH, WINDOW_HEIGTH);
	if (data.img = NULL)
		
		// printf("data.win: %p\n", data.win);
	mlx_key_hook(data.win, &handle_keyevent, &data);
	mlx_loop(data.mlx);
	if (data.win)
		mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free (data.mlx);
	return (0);
}
