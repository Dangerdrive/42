#include <stdio.h>
#include <stdlib.h>

int	main()
{
	size_t	max = -1;
	printf("int max: %d\n", 2147483647);
	printf("size_t max: %zu\n", max);
	// char *test = calloc(1844674407370955161, 1);
	// if (test == NULL)
	// 	printf("test is NULL\n");
	// else
	// 	printf("test is not NULL\n");

	char *test2 = calloc(4294967295*2, 1);
	if (test2 == NULL)
		printf("test2 is NULL\n");
	else
		printf("test2 is not NULL\n");
}