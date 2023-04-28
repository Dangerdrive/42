/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2023/04/26 20:49:13 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hlen;
	size_t	nlen;

	hlen = ft_strlen(haystack);
	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char *)haystack);
	if (nlen > len)
		return (NULL);
	while (*haystack && len >= nlen)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, nlen) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

/*
 #include <string.h>
     (See libbsd(7) for include usage.)

     char *
     strnstr(const char *big, const char *little, size_t len);

DESCRIPTION
     The strnstr() function locates the first occurrence of the null-termi‐
     nated string little in the string big, where not more than len characters
     are searched.  Characters that appear after a ‘\0’ character are not
     searched.  Since the strnstr() function is a FreeBSD specific API, it
     should only be used when portability is not a concern.


This function takes three arguments: a pointer to the string to search within haystack, a pointer to the string to search for needle, and a maximum number of characters to search len.

The function first gets the length of the haystack and needle strings. If the needle string is empty, the function returns a pointer to the beginning of haystack. If the length of the needle string is greater than len, the function returns NULL.

The function then searches for the needle string within the haystack string. It compares the characters at the current position in haystack and needle, and if they match, it uses ft_memcmp to compare the nlen characters starting at the current position in haystack and needle. If the comparison succeeds, the function returns a pointer to the current position in haystack.

If the needle string is not found within the haystack string, the function returns NULL.*/