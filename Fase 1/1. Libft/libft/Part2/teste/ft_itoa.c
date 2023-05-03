#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_numlen(n);
	if (sign == -1)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = (sign * (n % 10)) + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
// 	int num = 34753;
// 	char *result = ft_itoa(num);
// 	printf("%s\n", result);

// 	char str[10];
// 	sprintf(str, "%d", num);
// 	printf("%s\n", str);

// 	free(result);
// 	return 0;
// }

/*
C standard library has a similar function called sprintf
 that can be used to convert an integer to a string, among other uses.

*/

// #1. the integer to convert.
// The string representing the integer. NULL if the
// allocation fails.
// malloc
// Allocates (with malloc(3)) and returns( a) string
// representing the integer received as an argument.
// Negative numbers must be handled.

// Parameters
// Return (value)
// External functs.
// Description

/*
ft_itoa takes an integer as input and returns
 a string that represents the integer. 
 It allocates memory for the resulting string using malloc.

The function first determines the length of the resulting string
 by counting the number of digits in the input integer.
  If the input integer is negative, it accounts for the
   negative sign as well.

It then allocates memory for the string and 
fills it with digits from the input integer. 
It starts filling the string from the end and works its way
 to the beginning. It adds the ASCII value of '0' to each digit 
  to convert it to a character. If the input integer is negative,
   it adds a '-' character at the beginning.

Finally, it returns the resulting string. 
If the memory allocation fails, it returns NULL.
*/