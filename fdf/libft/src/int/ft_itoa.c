/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:01:11 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/14 17:17:26 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*my_strndup(const char *src, int size)
{
	char	*str;
	int		i;

	str = ft_calloc(size + 1, sizeof(char));
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

char	*ft_itoa(int n)
{
	char	num[11];
	int		i;

	if (n == INT_MIN)
		return (my_strndup("-2147483648", 11));
	num[0] = '+';
	if (n < 0)
	{
		num[0] = '-';
		n = -n;
	}
	i = 10;
	while (n > 9)
	{
		num[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	num[i] = n + '0';
	if (num[0] == '-' && i > 0)
	{
		i--;
		num[i] = num[0];
	}
	return (my_strndup(&num[i], 11 - i));
}
