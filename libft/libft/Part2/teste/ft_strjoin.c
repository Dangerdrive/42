#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	size;

	size = strlen(s1) + strlen(s2) + 1;

	strjoin = (char *)malloc(sizeof(char) * size);
	if (strjoin == NULL)
		return (NULL);
	strcpy(strjoin, s1); // copy s1 to strjoin
	strcat(strjoin, s2); // concatenate s2 to strjoin
	return (strjoin);
}


// #1. The prefix string.
// #2. The suffix string.
// The new string. NULL if the allocation fails.
// malloc
// Allocates (with malloc(3)) and returns a new
// string, which is the result of the concatenation
// of ’s1’ and ’s2’.

// Parameters
// Return value
// External functs.
// Description