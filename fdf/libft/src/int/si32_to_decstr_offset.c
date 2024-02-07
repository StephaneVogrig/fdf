/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   si32_to_decstr_offset.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:43:23 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/23 00:09:53 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// convert an int n in decimal digit and put directly in str.
// str must have the place to accept digits.
// return a pointer on the next character after the last digit.
char	*si32_to_decstr_offset(char *str, int n)
{
	t_si64	nbr;
	int		nbr_digit;
	int		mul;
	int		digit;

	nbr = (t_si64)n;
	if (nbr < 0)
	{
		nbr = -nbr;
		*str++ = '-';
	}
	nbr_digit = nbr_digit_ui64(nbr);
	while (nbr_digit)
	{
		mul = vs_10pow(nbr_digit - 1);
		digit = nbr / (mul);
		nbr -= digit * mul;
		nbr_digit--;
		*str++ = digit + '0';
	}
	return (str);
}
