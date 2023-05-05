/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P1-22.ft_calloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:50:44 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/05 20:22:40 by fde-alen         ###   ########.fr       */
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

/*
	   The  calloc()  function allocates memory for an array of nmemb elements
       of size bytes each and returns a pointer to the allocated memory.   The
       memory  is  set  to zero.  If nmemb or size is 0, then calloc() returns
       either NULL, or a unique pointer value that can later  be  successfully
       passed to free().  If the multiplication of nmemb and size would result
       in integer overflow, then calloc() returns an error.  By  contrast,  an
       integer  overflow  would  not be detected in the following call to mal‐
       loc(), with the result that an incorrectly sized block of memory  would
       be allocated:


*/