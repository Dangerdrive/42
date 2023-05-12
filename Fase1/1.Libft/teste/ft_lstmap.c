/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PB-09.ft_lstmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:05:19 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/09 21:53:04 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
// #1. The adress of a pointer to an element.
// #2. The adress of the function used to iterate on
// the list.
// #3. The adress of the function used to delete the
// content of an element if needed.
// The new list. NULL if the allocation fails.
// malloc, free
// Iterates the list ’lst’ and applies the function
// ’f’ to the content of each element. Creates a new
// list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to
// delete the content of an element if needed.

// Parameters
// Return value
// External functs.
// Description

/*
The function takes three arguments:

lst: a pointer to the first element of the list to be mapped.
f: a pointer to the function to be applied to each element of the list.
del: a pointer to the function used to delete the content of an element if allocation fails.
The function first checks if the input list is NULL or if the mapping function is NULL. If either is NULL, the function returns NULL. It then initializes a new list to NULL and starts iterating over the input list.

For each element of the input list, the function applies the mapping function to its content and creates a new node with the result. If the creation of the new node fails, the function deletes the new list with ft_lstclear and returns NULL.

If the creation of the new node succeeds, the function adds it to the end of the new list with ft_lstadd_back. After iterating over the entire input list, the function returns the new list.
*/