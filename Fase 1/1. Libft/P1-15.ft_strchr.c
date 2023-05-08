/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P1-15.ft_strchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/08 18:28:53 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
// #1. The character to output.
// #2. The file descriptor on which to write.
// None
// write
// Outputs the character ’c’ to the given file
// descriptor.

// Parameters
// Return value
// External functs.
// Description