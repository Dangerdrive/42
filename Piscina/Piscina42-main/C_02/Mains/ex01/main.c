#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	int	dest_size = 5;
	char	dest_test[dest_size];

	ft_strncpy(dest_test, "tes", dest_size);
	printf("%s\n", dest_test);
	dest_size = 9;
	ft_strncpy(dest_test, "testando", dest_size);
	printf("%s\n", dest_test);
}
