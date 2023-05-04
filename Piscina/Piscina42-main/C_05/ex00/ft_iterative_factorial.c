
int	ft_iterative_factorial(int nb)
{
	int fat;
	int i;

	if (nb < 0)
		return (0);
	
	fat = 1;
	i = 1;

	while (i <= nb)
	{
		fat *= i;
		i++;
	}

	return (fat);
}