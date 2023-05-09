/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P2-06.ft_strmapi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:17:54 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/08 18:17:56 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = 0;
	while (i < len)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}

// #1. The string on which to iterate.
// #2. The function to apply to each character.
// The string created from the successive applications
// of ’f’. Returns NULL if the allocation fails.
// malloc
// Applies the function ’f’ to each character of the
// string ’s’ to create a new string (with malloc(3))
// resulting from successive applications of ’f’.

// Parameters
// Return value
// External functs.
// Description

/*
This implementation checks if the input string
 and function pointers are not NULL, 
 allocates memory for the new string with malloc, 
 iterates through the input string applying the function f
  to each character, and returns the resulting string. 
 If the allocation fails, it returns NULL. 
ft_strlen is used to determine the length of the input string.
*/