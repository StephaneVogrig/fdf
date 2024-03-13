/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_10pow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:32:22 by stephane          #+#    #+#             */
/*   Updated: 2024/01/12 19:50:54 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline t_float128	vs_10pow_3(t_ui16 p)
{
	if (p < 19)
	{
		if (p == 16)
			return (1e16);
		if (p == 17)
			return (1e17);
		return (1e18);
	}
	if (p < 21)
	{
		if (p == 19)
			return (1e19);
		return (1e20);
	}
	if (p == 21)
		return (1e21);
	return (1e22);
}

static inline t_float128	vs_10pow_2(t_ui16 p)
{
	if (p < 12)
	{
		if (p == 7)
			return (1e7);
		if (p == 8)
			return (1e8);
		if (p == 9)
			return (1e9);
		if (p == 10)
			return (1e10);
		return (1e11);
	}
	if (p < 16)
	{
		if (p == 12)
			return (1e12);
		if (p == 13)
			return (1e13);
		if (p == 14)
			return (1e14);
		return (1e15);
	}
	return (vs_10pow_3(p));
}

static inline t_float128	vs_10pow_1(t_ui16 p)
{
	if (p == 0)
		return (1);
	if (p < 7)
	{
		if (p == 1)
			return (10);
		if (p == 2)
			return (1e2);
		if (p == 3)
			return (1e3);
		if (p == 4)
			return (1e4);
		if (p == 5)
			return (1e5);
		return (1e6);
	}
	return (vs_10pow_2(p));
}

t_float128	vs_10pow(t_ui16 p)
{
	t_float128	result;

	if (p < 23)
		return (vs_10pow_1(p));
	result = 1;
	while (p > 22)
	{
		p -= 22;
		result *= 1e22;
	}
	return (result * vs_10pow_1(p));
}
