/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy_offset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:04:09 by svogrig           #+#    #+#             */
/*   Updated: 2024/01/23 00:09:30 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// copy the string src in string dest
// dest must have enough space to receive src
// return a pointer on the the next character in dest after copy 
char	*strcpy_offset(char *dest, const char *src)
{
	while (*src)
		*dest++ = *src++;
	return (dest);
}
