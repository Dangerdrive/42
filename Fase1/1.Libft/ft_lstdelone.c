/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PB-06.ft_lstdelone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:05:19 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/09 20:52:49 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dellst(void *content)
{
	free(content);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del || !lst)
		return ;
	del(lst->content);
	free(lst);
}
// #1. The element to free.
// #2. The address of the function used to delete the
// content.
// None
// free
// Takes as a parameter an element and frees the
// memory of the element’s content using the function
// ’del’ given as a parameter and free the element.
// The memory of ’next’ must not be freed.

// Parameters
// Return value
// External functs.
// Description