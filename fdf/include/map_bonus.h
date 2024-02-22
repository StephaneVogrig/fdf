/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:17:18 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/22 19:20:51 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

# include <fcntl.h>
# include "libft.h"

typedef struct s_data{
	int		z;
	t_color	color;
	t_color	color_origin;
}	t_data;

typedef struct s_map{
	int			nbr_line;
	int			nbr_col;
	int			z_min;
	int			z_max;
	t_data		**datas;
	t_pixel		*buffer;
}	t_map;

t_bool	map_load(char *path, t_map *map);

#endif
