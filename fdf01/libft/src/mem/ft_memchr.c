/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:03:37 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/14 18:46:48 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	uchar;

	ptr = (unsigned char *)s;
	uchar = (unsigned char)c;
	while (n)
	{
		if (*ptr == uchar)
			return (ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
