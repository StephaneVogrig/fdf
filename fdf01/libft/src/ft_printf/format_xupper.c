/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_xupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 03:17:48 by stephane          #+#    #+#             */
/*   Updated: 2024/01/12 19:27:25 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_xupper(t_ui64 nbr, t_spec *spec, t_buffer *buffer)
{
	char				str[MAX_DIGIT_HEXA];
	t_nbrstr			nbrstr;

	nbrstr.is_zero = nbr == 0;
	nbrstr.str = ui64_to_str_hexaupper(str, nbr);
	nbrstr.nbr_digit = str + MAX_DIGIT_HEXA - nbrstr.str;
	if (spec->flag_hash && nbr > 0)
		spec->prefix = 'X';
	else
		spec->prefix = '\0';
	nbrstr_to_buffer(buffer, spec, &nbrstr);
	return (1);
}
