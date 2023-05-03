/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2023/04/26 20:45:22 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1 = s1;
	const unsigned char	*p2 = s2;

	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}

/*
       #include <string.h>

       int memcmp(const void *s1, const void *s2, size_t n);

DESCRIPTION
       The  memcmp()  function compares the first n bytes (each interpreted as
       unsigned char) of the memory areas s1 and s2.


This function compares the first n bytes of the memory areas s1 and s2. It returns an integer less than, equal to, or greater than zero, depending on whether the first differing byte in s1 is less than, equal to, or greater than the corresponding byte in s2. If n is zero, the function returns zero.
*/