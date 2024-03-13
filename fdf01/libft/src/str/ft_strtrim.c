/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:14:02 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/14 22:21:35 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		len_s1;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	if (len_s1 == 0)
		return (ft_calloc(1, sizeof(char)));
	start = 0;
	while (s1[start] != 0 && is_in_set(s1[start], set))
		start++;
	if (s1[start] == '\0')
		return (ft_calloc(1, sizeof(char)));
	end = len_s1 - 1;
	while (s1[end] && is_in_set(s1[end], set))
		end--;
	str = ft_calloc(end - start + 2, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s1[start], end - start + 2);
	return (str);
}
