/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P1-10.ft_memmove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/05 13:06:30 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_cpy;
	const unsigned char	*src_cpy;

	dest_cpy = (unsigned char *)dest;
	src_cpy = (const unsigned char *)src;
	while (n--)
		*dest_cpy++ = *src_cpy++;
	return (dest);
}
// #include <string.h>

//void *memmove(void *dest, const void *src, size_t n);

// memmove - copy memory area
/*
man description
The memmove() function copies n bytes from memory area src to memory area dest.
       The memory areas may overlap: copying takes place as though the  bytes  in  src
       are  first copied into a temporary array that does not overlap src or dest, and
       the bytes are then copied from the temporary array to dest.

This implementation copies n bytes of data from the memory block pointed to by src to the memory block pointed to by dest. The function is designed to handle overlapping memory blocks, meaning that the source and destination memory blocks may partially or completely overlap with each other.

The implementation first checks whether the source and destination pointers are the same or whether n is 0. If either of these conditions is true, the function returns the destination pointer without performing any operations.

If the destination pointer is less than the source pointer, the function performs a forward copy, where it copies the bytes from the source to the destination one by one. Otherwise, if the destination pointer is greater than the source pointer, the function performs a backward copy, where it copies the bytes from the end of the source block to the end of the destination block.

Note that this implementation assumes that both src and dest point to valid memory blocks that are at least n bytes in size. If you want to ensure that the function does not read or write past the end of either memory block, you may need to modify the function to perform additional bounds checking.
*/