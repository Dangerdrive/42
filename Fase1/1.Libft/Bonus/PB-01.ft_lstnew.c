/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PB-01.ft_lstnew.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:05:19 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/05 15:09:12 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node)
	{
		node->content = content;
		node->next = NULL;
	}
	return (node);
}
// #1. The content to create the new element with.
// The new element.
// malloc
// Allocates (with malloc(3)) and returns a new
// element. The variable ’content’ is initialized
// with the value of the parameter ’content’. The
// variable ’next’ is initialized to NULL.

// Parameters
// Return value
// External functs.
// Description