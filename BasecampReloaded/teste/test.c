
void	ft_swap(int *a, int *b)
{
	int d;

	d = *a;
	*a = *b;
	*b = d;
}

#include <stdio.h>

int main()
{
	int	a;
	int b;

	ft_swap(&a, &b);
	a = 3;
	b = 7;
	printf("a=%d b=%d", a, b);
}