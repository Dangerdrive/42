int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;

	// Skip white spaces
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;

	// Handle signs
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}

	// Convert digits to integer
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}

	return (result * sign);
}