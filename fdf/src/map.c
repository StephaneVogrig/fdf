/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:46:08 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/10 21:06:26 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_to_data(char *str, t_data *data_line)
{
	int	col;
	int	sign;

	ft_putstr_fd(str, STDOUT);
	col = 0;
	while (*str)
	{
		data_line[col].z = atoi_offset(&str);
		if (*str == ',')
		{
			str++;
			data_line[col].color = hextoi_offset(&str);
		}
		else
			data_line[col].color = 0;			
		if (*str == '\n')
			str++;
		col++;
	}
}

t_bool	line_to_map(char *line, int nbr_col, t_map *map)
{
	t_data	*new_data_line;
	t_list	*new_node;

	new_data_line = malloc(sizeof(t_data) * nbr_col);
	if (!new_data_line)
		return (error_perror("line_to_map:new_data_line"));
	new_node = ft_lstnew(new_data_line);
	if (!new_node)
	{
		free(new_data_line);
		return (error_perror("line_to_map:new_node"));
	}
	ft_lstadd_back(&map->data_lines, new_node);
	line_to_data(line, new_data_line);
	return (SUCCESS);
}

t_bool	map_load(char *path,  t_map *map)
{
	int		fd;
	char	*line;
	t_bool	ok;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error_perror("map_load"));
	line = get_next_line(fd);
	if (line == NULL)
		return (error_msg("map_load: Empty_file"));
	map->nbr_col = count_words(line, ' ');
	// ft_printf("nbr col =  %i\n", map->nbr_col);
	while (line)
	{
		ok = line_to_map(line, map->nbr_col, map);
		free(line);
		if (!ok)
			return (ERROR);
		line = get_next_line(fd);
	}
	return (SUCCESS);
}
