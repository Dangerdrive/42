/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:05:19 by fde-alen          #+#    #+#             */
/*   Updated: 2023/04/25 20:40:38 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
}
// #1. The adress of a pointer to an element.
// #2. The adress of the function used to delete the
// content of the element.
// None
// free
// Deletes and frees the given element and every
// successor of that element, using the function ’del’
// and free(3).
// Finally, the pointer to the list must be set to
// NULL.

// Parameters
// Return value
// External functs.
// Description