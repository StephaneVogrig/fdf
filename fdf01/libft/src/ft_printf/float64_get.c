/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float64_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:11:42 by stephane          #+#    #+#             */
/*   Updated: 2024/01/14 05:42:21 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

int	float64_get_sign(t_float64 nbr)
{
	t_u_float64	uf;

	uf.f = nbr;
	if (uf.sign)
		return (-1);
	return (1);
}

int	float64_get_exponent(t_float64 nbr)
{
	t_u_float64	uf;

	if (nbr == 0.0)
		return (0);
	uf.f = nbr;
	if (uf.exponent_biais == 0)
		return ((int)uf.exponent_biais - DOUBLE_BIAS_DENORMALISE);
	return ((int)uf.exponent_biais - DOUBLE_BIAS_NORMALISE);
}

t_ui64	float64_get_mantissa(t_float64 f)
{
	t_u_float64	uf;

	uf.f = f;
	return ((t_ui64)uf.mantissa);
}

t_float64	float64_get_decimal_part(t_float64 nbr)
{
	int			exp;
	t_u_float64	uf;

	exp = float64_get_exponent(nbr);
	if (exp < 0)
		return (nbr);
	if (exp == 0)
		return (nbr - (t_ui64)nbr);
	if (exp > 51)
		return (0.0);
	return (nbr - (int)nbr);
	uf.f = nbr;
	uf.exponent_biais -= exp;
	uf.mantissa <<= exp;
	uf.f -= 1;
	return (uf.f);
}
