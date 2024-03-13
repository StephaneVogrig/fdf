/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:02:06 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/21 15:33:34 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	error_msg(char *error_msg)
{
	ft_putstr_fd(error_msg, STDERR);
	write(STDERR, "\n", 1);
	return (ERROR);
}
