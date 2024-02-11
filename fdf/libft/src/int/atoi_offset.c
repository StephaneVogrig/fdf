/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_offset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:54:54 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/11 20:44:21 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	atoi_offset(char **str)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (**str == ' ' || **str == '\t')
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	while (ft_isdigit(**str))
	{
		nbr = nbr * 10 + **str - '0';
		(*str)++;
	}
	return (nbr * sign);
}
