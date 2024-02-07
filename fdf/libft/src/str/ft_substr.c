/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:14:12 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/09 00:07:26 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	len_substr;
	size_t	i;
	char	*substr;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s || len == 0)
		return (ft_calloc(1, sizeof(char)));
	if (len_s - start > len)
		len_substr = len;
	else
		len_substr = len_s - start;
	substr = ft_calloc(len_substr + 1, sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len_substr)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
