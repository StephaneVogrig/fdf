/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hexagit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 02:00:51 by svogrig           #+#    #+#             */
/*   Updated: 2024/02/10 02:02:18 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_hexagit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	if ('a' <= c && c <= 'f')
		return (1);
	if ('A' <= c && c <= 'F')
		return (1);
	return (0);
}