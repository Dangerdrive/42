/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PB-02.ft_lstadd_front.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:05:19 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/09 17:52:07 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
// #1. The address of a pointer to the first link of
// a list.
// #2. The address of a pointer to the element to be
// added to the list.
// None
// None
// Adds the element ’new’ at the beginning of the
// list.

// Parameters
// Return value
// External functs.
// Description

// If both pointers are not null, it sets the next pointer of the new node to the current head of the list (*lst), and then updates the head of the list to point to the new node (*lst = new).