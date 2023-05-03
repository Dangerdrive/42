
#include "libft.h"

static int	is_set_char(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_set_char(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_set_char(s1[end - 1], set))
		end--;
	trimmed = (char *)malloc((end - start + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, end - start + 1);
	return (trimmed);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char const	*s1 = "You can make a wish, but there's no rabbit out the hat.";
// 	char const	*set = "You can out the hat";
// 	char		*trimmed = ft_strtrim(s1, set);
// 	printf("teste 1: %s\n", trimmed);
	
// 	set = "ou the hat. You can";
// 	trimmed = ft_strtrim(s1, set);
// 	printf("teste 2: %s\n", trimmed);
	
// 	set = "the";
// 	trimmed = ft_strtrim(s1, set);
// 	printf("teste 3: %s\n", trimmed);	
// }

// #1. The string to be trimmed.
// #2. The reference set of characters to trim.
// The trimmed string. NULL if the allocation fails.
// malloc
// Allocates (with malloc(3)) and returns a copy of
// ’s1’ with the characters specified in ’set’ removed
// from the beginning and the end of the string.

// Parameters
// Return value
// External functs.
// Description

/*
the C standard library has a similar function 
called strtok() which is used to extract tokens
 (substrings) from a string based on a delimiter character.
However, strtok() modifies the original string
 by replacing the delimiter characters with null 
 terminators. This means that subsequent calls to strtok()
  on the same string will return different tokens,
   which may not be desirable in all situations.
In contrast, ft_strtrim() does not modify 
the original string and returns a newly allocated string 
with the trimmed result.
*/