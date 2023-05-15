/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:05:19 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/15 20:45:11 by fde-alen         ###   ########.fr       */
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

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*node;
// 	size_t	content_len;

// 	node = malloc(sizeof(t_list));
// 	if (node)
// 	{
// 		content_len = ft_strlen(content);
// 		node->content = malloc(content_len + 1);
// 		if (!node->content)
// 		{
// 			free(node);
// 			return (NULL);
// 		}
// 		ft_strlcpy(node->content, content, content_len + 1);
// 		node->next = NULL;
// 	}
// 	return (node);
// }
