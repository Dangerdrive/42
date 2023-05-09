#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);

	i = 0;
	while (*s && i < start)
	{
		i++;
	}
	while (*s && i - start < len)
	{
		*substr = s[i];
		i++;
		substr++;
	}
	*substr = '\0';
	return (substr - len);
// return the start address of the allocated memory
}




// #1. The string from which to create the substring.
// #2. The start index of the substring in the string
// ’s’.
// #3. The maximum length of the substring.
// The substring. NULL if the allocation fails.
// malloc
// Allocates (with malloc(3)) and returns a substring
// from the string ’s’.
// The substring begins at index ’start’ and is of
// maximum size ’len’

// Parameters
// Return value
// External functs.
// Description