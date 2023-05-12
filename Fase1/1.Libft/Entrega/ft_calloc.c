/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P1-22.ft_calloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:50:44 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/08 18:28:40 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (!size || nmemb > __SIZE_MAX__ / size)
		return (NULL);
	arr = malloc(nmemb * size);
	if (arr)
	{
		ft_bzero(arr, nmemb * size);
		return (arr);
	}
	else
		return (NULL);
}
