/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P1-16.ft_strrchr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/05 16:33:13 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last = NULL;

	while (*s)
	{
		if (*s == c)
			last = s;
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return ((char *)last);
}

/*
#include <string.h>

       char *strrchr(const char *s, int c);
	   
The  strrchr() function returns a pointer to the last occurrence of the
       character c in the string s.

Here, we initialize a const char pointer last to NULL before iterating through the string. Whenever we find the character c in the string, we update last to point to the current character. This way, we keep track of the last occurrence of c as we iterate through the string.

After we finish iterating through the string, we check if the last character is equal to c, since we haven't checked it in the loop. If it is, we return a pointer to that character. Otherwise, we return the pointer stored in last, which points to the last occurrence of c in the string.

*/