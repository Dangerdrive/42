#include <stdio.h>
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	int	dest_size = 5;
	char	dest_test[dest_size];

	ft_strlcpy(dest_test, "testando", dest_size);
	printf("%s\n", dest_test);
	dest_size = 9;
	ft_strlcpy(dest_test, "testando", dest_size);
	printf("%s\n", dest_test);
}

 The purpose of strlcpy is to copy a string 
 while ensuring that the destination buffer is not overflowed,
  whereas the purpose of strncpy is to copy a fixed number of characters from one string to another.