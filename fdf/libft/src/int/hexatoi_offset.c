/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexatoi_offset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:03:29 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/21 17:02:12 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hexatoi_offset(char **str)
{
	int	nbr;

	if (**str == '0' && (*(*str + 1) == 'x' || *(*str + 1) == 'X'))
		*str += 2;
	nbr = 0;
	while (is_hexagit(**str))
	{
		if ('0' <= **str && **str <= '9')
			nbr = nbr * 16 + **str - '0';
		else if ('a' <= **str && **str <= 'f')
			nbr = nbr * 16 + 10 + **str - 'a';
		else if ('A' <= **str && **str <= 'F')
			nbr = nbr * 16 + 10 + **str - 'A';
		(*str)++;
	}
	return (nbr);
}
