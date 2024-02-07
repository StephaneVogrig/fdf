/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:12:55 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/12 19:29:27 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_u(t_ui64 nbr, t_spec *spec, t_buffer *buffer)
{
	char		str[LEN_MAXLONGLONG];
	t_nbrstr	nbrstr;

	nbrstr.is_zero = (nbr == 0);
	nbrstr.str = ui64_to_str_dec(str, nbr);
	nbrstr.nbr_digit = str + LEN_MAXLONGLONG - nbrstr.str;
	spec->prefix = '\0';
	nbrstr_to_buffer(buffer, spec, &nbrstr);
	return (1);
}
