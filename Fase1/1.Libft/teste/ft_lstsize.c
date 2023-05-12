/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PB-03.ft_lstsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:05:19 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/09 18:06:27 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
// #1. The beginning of the list.
// Length of the list.
// None
// Counts the number of elements in a list.

// Parameters
// Return value
// External functs.
// Description