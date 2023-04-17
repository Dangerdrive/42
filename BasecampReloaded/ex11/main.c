#include <stdio.h>

int	ft_iterative_factorial(int nb);

int	main(void)
{
	int	tdiv;
	int	tmod;

	ft_div_mod(19, 8, &tdiv, &tmod);
	printf("div = %d\nmod = %d\n", tdiv, tmod);
}
