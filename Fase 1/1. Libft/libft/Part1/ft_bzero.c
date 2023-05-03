/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2023/04/26 14:48:12 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n-- > 0)
		*p++ = '\0';
}
// #include <string.h>

// void bzero(void *s, size_t n);

// memset - fill memory with a constant byte
/*
The ft_bzero function takes a pointer to the start of the memory block to zero out and the number of bytes to zero out. It then uses a loop to iterate over the memory block and set each byte to 0.

Note that ft_bzero is similar to the memset function from the standard C library, which can be used to set a memory block to any arbitrary value.
*/