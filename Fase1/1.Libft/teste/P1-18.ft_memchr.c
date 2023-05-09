/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P1-18.ft_memchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/05 17:15:28 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p = s;

	while (n--)
	{
		if (*p == c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}

/*
#include <string.h>

       void *memchr(const void *s, int c, size_t n);

	   The  memchr()  function  scans  the  initial n bytes of the memory area
       pointed to by s for the first instance of c.  Both c and the  bytes  of
       the memory area pointed to by s are interpreted as unsigned char.

	   ft_memchr searches for the first occurrence of c (as an unsigned char) in the first n bytes of the memory block pointed to by s. If c is found, a pointer to the byte is returned; otherwise, NULL is returned.
*/