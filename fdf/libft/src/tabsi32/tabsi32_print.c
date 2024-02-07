/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabsi32_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:40:14 by stephane          #+#    #+#             */
/*   Updated: 2024/02/05 00:20:50 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tabsi32_print(t_tabsi32 tab, char *before, char *sep, char *after)
{
	ft_putstr_fd(before, 1);
	while (tab.size--)
	{
		ft_putnbr_fd(*(tab.elem++), 1);
		if (tab.size)
			ft_putstr_fd(sep, 1);
	}
	ft_putstr_fd(after, 1);
}
