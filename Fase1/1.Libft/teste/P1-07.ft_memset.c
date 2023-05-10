/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P1-07.ft_memset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/09 17:17:17 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp_str;
	unsigned char	tmp_char;

	tmp_str = s;
	tmp_char = c;
	while (n-- > 0)
	{
		*tmp_str++ = tmp_char;
	}
	return (s);
}
// #include <string.h>

//void	*memset(void *s, int c, size_t n)

// memset - fill memory with a constant byte
/*
This implementation sets the first n bytes of the memory block pointed to by s to the value of c. The function returns a pointer to the memory block that was modified.

The implementation uses a pointer p to traverse the memory block byte by byte and a temporary variable uc to hold the value of c as an unsigned char. The loop continues until n bytes have been written, at which point the function returns the original pointer s.

Note that the implementation assumes that the memory block pointed to by s has at least n bytes of available space. If you want to ensure that the function does not write past the end of the memory block, you may need to modify the function to perform additional bounds checking.
*/