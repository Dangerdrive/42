/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PB-08.ft_lstiter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:05:19 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/09 21:50:24 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*i;

	if (lst == NULL || f == NULL)
		return ;
	i = lst;
	while (i != NULL)
	{
		f(i->content);
		i = i->next;
	}
}
// #1. The adress of a pointer to an element.
// #2. The adress of the function used to iterate on
// the list.
// None
// None
// Iterates the list ’lst’ and applies the function
// ’f’ to the content of each element.

// Parameters
// Return value
// External functs.
// Description