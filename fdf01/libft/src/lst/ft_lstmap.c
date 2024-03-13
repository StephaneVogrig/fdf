/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 02:28:13 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/14 18:19:41 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_2;
	t_list	*new_node;
	t_list	*last_lst2;

	if (!f || !del)
		return (NULL);
	lst_2 = NULL;
	last_lst2 = NULL;
	while (lst)
	{
		new_node = ft_lstnew((*f)(lst->content));
		if (!new_node)
		{
			ft_lstclear(&lst_2, (*del));
			return (NULL);
		}
		if (!lst_2)
			lst_2 = new_node;
		else
			last_lst2->next = new_node;
		last_lst2 = new_node;
		lst = lst->next;
	}
	return (lst_2);
}
