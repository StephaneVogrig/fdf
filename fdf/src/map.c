/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:46:08 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/13 07:01:12 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*file_line_to_data(char *str, int nbr_col)
{
	t_data	*new_data_line;
	int		col;
	int		sign;

	new_data_line = malloc(sizeof(t_data) * nbr_col);
	if (!new_data_line)
		return (NULL);
	col = 0;
	while (*str)
	{
		new_data_line[col].z = atoi_offset(&str);
		if (*str == ',')
		{
			str += 3;
			new_data_line[col].color = hexatoi_offset(&str);
		}
		else
			new_data_line[col].color = 0x00FFFFFF;
		if (*str == '\n')
			str++;
		col++;
	}
	return (new_data_line);
}

t_bool	file_line_to_node(char *line, int nbr_col, t_list **list)
{
	t_list	*new_node;
	t_data	*new_data_line;

	new_data_line = file_line_to_data(line, nbr_col);
	if (!new_data_line)
		return (error_perror("file_line_to_map:new_data_line"));
	new_node = ft_lstnew(new_data_line);
	if (!new_node)
	{
		free(new_data_line);
		return (error_perror("file_line_to_map:new_node"));
	}
	ft_lstadd_front(list, new_node);
	return (SUCCESS);
}

t_list	*map_file_to_list(int fd, t_map *map)
{
	char	*line;
	t_list	*list;
	t_bool	ok;

	list = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	map->nbr_col = count_words(line, ' ');
	while (line)
	{
		map->nbr_line++;
		ok = file_line_to_node(line, map->nbr_col, &list);
		free(line);
		if (!ok)
		{
			ft_lstclear(&list, &free);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	return (list);
}

t_data	**map_list_to_tab(t_list *list, int nbr_line)
{
	t_data	**tab;
	t_list	*temp;

	tab = malloc(sizeof(t_data *) * (nbr_line + 1));
	if (!tab)
		return (NULL);
	tab[nbr_line] = NULL;
	while (list)
	{
		tab[--nbr_line] = list->content;
		temp = list->next;
		free(list);
		list = temp;
	}
	return (tab);
}

t_bool	map_load(char *path, t_map *map)
{
	int		fd;
	t_bool	ok;
	t_list	*map_list;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error_perror("map_load:open"));
	map_list = map_file_to_list(fd, map);
	close(fd);
	if (!map_list)
		return (error_perror("map_load:map_file_to_list"));
	map->datas = map_list_to_tab(map_list, map->nbr_line);
	if (!map->datas)
		return (error_perror("map_load:map_list_to_tab"));
	map->buffer = malloc(sizeof(t_point2d) * map->nbr_col);
	if (!map->buffer)
		return (error_perror("map_load:malloc"));
	return (SUCCESS);
}
