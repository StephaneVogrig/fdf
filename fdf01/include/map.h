/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 04:09:09 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/22 04:31:08 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include "libft.h"

typedef struct s_data{
	int		z;
	t_color	color;
}	t_data;

typedef struct s_map{
	int			nbr_line;
	int			nbr_col;
	t_data		**datas;
	t_pixel		*buffer;
}	t_map;

t_bool	map_load(char *path, t_map *map);

#endif