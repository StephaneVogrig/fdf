/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:58:22 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/14 13:46:11 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;

	len_dst = 0;
	if (dst)
		len_dst = ft_strlen(dst);
	if (size < len_dst)
		return (size + ft_strlen(src));
	dst += len_dst;
	size -= len_dst;
	return (len_dst + ft_strlcpy(dst, src, size));
}
