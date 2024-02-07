/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:01:11 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/18 19:38:08 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int	format_i_min(t_spec *spec, t_buffer *buffer)
{
	t_nbrstr	nbrstr;

	nbrstr.is_zero = FALSE;
	nbrstr.str = "9223372036854775808";
	nbrstr.nbr_digit = 19;
	spec->prefix = '-';
	nbrstr_to_buffer(buffer, spec, &nbrstr);
	return (1);
}

static inline int	format_i_neg(t_ui64 nbr, t_spec *spec, t_buffer *buffer)
{
	char		str[LEN_MAXLONGLONG];
	t_nbrstr	nbrstr;

	nbrstr.is_zero = FALSE;
	nbrstr.str = ui64_to_str_dec(str, -nbr);
	nbrstr.nbr_digit = str + LEN_MAXLONGLONG - nbrstr.str;
	spec->prefix = '-';
	nbrstr_to_buffer(buffer, spec, &nbrstr);
	return (1);
}

static inline int	format_i_pos(t_ui64 nbr, t_spec *spec, t_buffer *buffer)
{
	char		str[LEN_MAXLONGLONG];
	t_nbrstr	nbrstr;

	nbrstr.is_zero = nbr == 0;
	nbrstr.str = ui64_to_str_dec(str, nbr);
	nbrstr.nbr_digit = str + LEN_MAXLONGLONG - nbrstr.str;
	set_prefix(spec);
	nbrstr_to_buffer(buffer, spec, &nbrstr);
	return (1);
}

int	format_i(t_si64 nbr, t_spec *spec, t_buffer *buffer)
{
	if (nbr == LLONG_MIN)
		return (format_i_min(spec, buffer));
	if (nbr < 0)
		return (format_i_neg(nbr, spec, buffer));
	return (format_i_pos(nbr, spec, buffer));
}
