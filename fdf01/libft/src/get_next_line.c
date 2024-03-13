/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:50:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/05 00:20:30 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_join(char *line, char *buffer, size_t len)
{
	char	*new_line;
	size_t	i;

	i = 0;
	if (line)
		while (line[i])
			i++;
	new_line = malloc(i + len + 1);
	if (!new_line)
	{
		if (line)
			free(line);
		return (NULL);
	}
	new_line[i + len] = '\0';
	while (len--)
		new_line[i + len] = buffer[len];
	while (i--)
		new_line[i] = line[i];
	if (line)
		free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static t_gnl_buffer	buffer;
	static ssize_t		size_read = -1;
	ssize_t				start;
	char				*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (size_read)
	{
		start = buffer.i;
		while (buffer.i < size_read)
			if (buffer.data[buffer.i++] == '\n')
				return (gnl_join(line, buffer.data + start, buffer.i - start));
		if (size_read > -1 && start < buffer.i)
			line = gnl_join (line, buffer.data + start, buffer.i - start);
		size_read = read(fd, buffer.data, BUFFER_SIZE);
		buffer.i = 0;
		if (size_read == -1 && line)
			free(line);
		if (size_read == -1)
			return (NULL);
	}
	size_read = -1;
	return (line);
}
