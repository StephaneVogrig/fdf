/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_digit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:50:33 by stephane          #+#    #+#             */
/*   Updated: 2024/01/18 22:10:39 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_digit_si32(int n)
{
	if (n >= 0)
		return (nbr_digit_ui32(n));
	if (n == INT_MIN)
		return (11);
	return (nbr_digit_ui32(n) + 1);
}

int	nbr_digit_si64(t_si64 n)
{
	if (n >= 0)
		return (nbr_digit_ui64(n));
	if (n == LLONG_MIN)
		return (21);
	return (nbr_digit_ui64(n) + 1);
}

int	nbr_digit_ui32(t_ui32 n)
{
	if (n < 10000)
	{
		if (n < 10)
			return (1);
		if (n < 100)
			return (2);
		if (n < 1000)
			return (3);
		return (4);
	}
	if (n < 10000000)
	{
		if (n < 100000)
			return (5);
		if (n < 1000000)
			return (6);
		return (7);
	}
	if (n < 1e8)
		return (8);
	if (n < 1e9)
		return (9);
	return (10);
}

int	nbr_digit_ui64(t_ui64 n)
{
	if (n < 10000000000ul)
		return (nbr_digit_ui32((t_ui32)n));
	if (n < 100000000000000ul)
	{
		if (n < 100000000000ul)
			return (11);
		if (n < 1000000000000ul)
			return (12);
		if (n < 10000000000000ul)
			return (13);
		return (14);
	}
	if (n < 100000000000000000ul)
	{
		if (n < 1000000000000000ul)
			return (15);
		if (n < 10000000000000000ul)
			return (16);
		return (17);
	}
	if (n < 1000000000000000000ul)
		return (18);
	if (n < 10000000000000000000ul)
		return (19);
	return (20);
}

t_ui16	nbr_digit_float64_integer_part(t_float128 n)
{
	t_ui16	nbr_digit;

	nbr_digit = 0;
	while (n >= 1e19L)
	{
		n /= 1e19L;
		nbr_digit += 19;
	}
	return (nbr_digit + nbr_digit_ui64(n));
}
