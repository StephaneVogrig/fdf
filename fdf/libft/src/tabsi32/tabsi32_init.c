/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabsi32_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:32:35 by stephane          #+#    #+#             */
/*   Updated: 2024/02/05 00:20:45 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tabsi32	tabsi32_init(int *tab, int size)
{
	t_tabsi32	new;

	new.elem = tab;
	new.size = size;
	return (new);
}
