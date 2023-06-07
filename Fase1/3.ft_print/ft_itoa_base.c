#include <stdio.h>
#include <stdlib.h>

static int	ft_numlen(int n, int base)
{
	int	len;

	len = 1;
	while (n / base)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int n, int base)
{
	char	*str;
	int		len;
	int		sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_numlen(n, base);
	if (sign == -1)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = "0123456789ABCDEF"[(sign * (n % base))];
		n /= base;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

int main() {
    int hexValue = 0xABCDEF;
    char* hexString = ft_itoa_base(hexValue, 16);

    printf("Hexadecimal value: 0x%X\n", hexValue);
    printf("Converted string: %s\n", hexString);

    free(hexString);  // Remember to free the allocated memory

    return 0;
}
