#include <stdio.h>
#include <stdlib.h>

void	ft_ft(int *nbr);

int	main(void)
{
	int *number = malloc(sizeof(int));
	ft_ft(number);
	printf("%d", *number);
	free(number);
}
