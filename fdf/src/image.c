/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:23:17 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/17 18:57:12 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

void	img_clear(t_map *map, t_img *img)
{
	clock_t begin = clock();
	
	ft_bzero(img->data, img->size_line * img->height);

	map->is_update = TRUE;

	clock_t end = clock();
    printf( "%-15s in %10ld ticks | %6.3f ms |%6ld fps\n","img_clear", end - begin, 1000.0 * (end - begin) / CLOCKS_PER_SEC , CLOCKS_PER_SEC / (end - begin));
}

void	img_clean(t_map *map, t_img *img, t_transform *transform)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			img_set_pixel(img, x++, y, color(0,0,0,0));
		}
		y++;
	}
	map_to_img(map, img, transform);
	map->is_update = TRUE;
}

inline void	 img_set_pixel(t_img *img, int x, int y, t_ui32 color)
{
	// char	*pixel;

	if (0 <= x && x < img->width && 0 <= y && y < img->height)
	{
		// pixel = img->data + (y * img->size_line + x * (img->bpp >> 3));
		// *(unsigned int *)pixel = color;
		*(t_ui32 *)(img->data + y * img->size_line + x * (img->bpp >> 3)) = color;
	}
}
