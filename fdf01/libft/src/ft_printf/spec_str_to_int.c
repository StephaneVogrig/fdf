/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_str_to_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:55:21 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/14 04:18:54 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int	is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

static inline int	is_not_digit(char c)
{
	return (c < '0' || '9' < c);
}

inline char	*spec_str_to_int(char *format, int *nbr)
{
	if (is_not_digit(*format))
		return (format);
	*nbr = 0;
	while (is_digit(*format))
	{
		*nbr = *nbr * 10 + *format - '0';
		if (*nbr > INT_MAX)
			return (NULL);
		format++;
	}
	return (format);
}
