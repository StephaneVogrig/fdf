/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:52:36 by stephane          #+#    #+#             */
/*   Updated: 2024/01/12 19:51:19 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_x(t_ui64 nbr, t_spec *spec, t_buffer *buffer)
{
	char				str[MAX_DIGIT_HEXA];
	t_nbrstr			nbrstr;

	nbrstr.is_zero = nbr == 0;
	nbrstr.str = ui64_to_str_hexalower(str, nbr);
	nbrstr.nbr_digit = str + MAX_DIGIT_HEXA - nbrstr.str;
	if (spec->flag_hash && nbr > 0)
		spec->prefix = 'x';
	else
		spec->prefix = '\0';
	nbrstr_to_buffer(buffer, spec, &nbrstr);
	return (1);
}
