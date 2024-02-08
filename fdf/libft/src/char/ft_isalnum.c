/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:37:07 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/14 17:12:23 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ('0' <= c && c <= '9')
		return (8);
	if ('a' <= c && c <= 'z')
		return (8);
	if ('A' <= c && c <= 'Z')
		return (8);
	return (0);
}