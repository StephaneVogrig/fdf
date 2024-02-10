/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:00:04 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/09 15:49:44 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_split_free(char **split)
{
	int	i;

	if (split == NULL)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	*my_strndup(const char *src, int size)
{
	char	*str;
	int		i;

	if (src == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	fill_split(char **split, char const *s, char c)
{
	char	*start;
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			split[i] = my_strndup(start, s - start);
			if (split[i] == NULL)
				return (0);
			i++;
		}
	}
	return (1);
}

size_t	count_words(char const *str, char c)
{
	size_t	nbr_words;

	nbr_words = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			nbr_words++;
		while (*str && *str != c)
			str++;
	}
	return (nbr_words);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	nbr_words;

	if (s == NULL)
		return (NULL);
	nbr_words = count_words(s, c);
	split = ft_calloc(nbr_words + 1, sizeof(char *));
	if (split == NULL)
		return (NULL);
	if (fill_split(split, s, c) == 0)
	{
		ft_split_free(split);
		return (NULL);
	}
	split[nbr_words] = NULL;
	return (split);
}
