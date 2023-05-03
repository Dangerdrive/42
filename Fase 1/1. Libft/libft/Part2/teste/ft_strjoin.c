#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;

	strjoin = (char *)malloc(sizeof(char) * size);
	if (strjoin == NULL)
		return (NULL);
	ft_strlcpy(strjoin, s1, size); // copy s1 to strjoin
	ft_strlcat(strjoin, s2, size); // concatenate s2 to strjoin
	return (strjoin);
}

#include <stdio.h>

int	main(void)
{
	char	*str1 = "Keep those blurry memories somewhere safe, ";
	char	*str2 = "You may need them.";
	char	*joined;
	joined = ft_strjoin(str1, str2);
	printf("%s", joined);
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


//git remote set-url origin