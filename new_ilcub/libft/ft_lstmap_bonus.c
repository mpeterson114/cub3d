/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:10:58 by mpeterso          #+#    #+#             */
/*   Updated: 2022/10/18 12:38:32 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Creates a new list from a given list by applying the function 'f'
	passed as parameter to the original list. If the memory allocation fails 
	for any node in the new list, the new list will be deleted with the function 
	'del' passed as parameter and its memory will be freed. */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*list_n;

	if (!f | !del)
		return (0);
	list_n = 0;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&list_n, del);
		}
		ft_lstadd_back(&list_n, new);
		lst = lst->next;
	}
	return (list_n);
}
