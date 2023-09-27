#include "fractol.h"

static void	ft_get_decimal(char *str, double *decimal)
{
	double	factor;

	factor = 1;
	if (*str == '.')
		str++;
	while (*str)
	{
		*decimal = *decimal * 10 + (*str - '0');
		factor *= 10;
		str++;
	}
	*decimal /= factor;
}

/**
 * @brief Converts a string to a double
 *
 * @param str The string to convert
 *
 * @return double The converted string
 */
double	ft_atod(char *str)
{
	double	result;
	double	decimal;
	int		sign;

	result = 0;
	decimal = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && *str != '.')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	ft_get_decimal(str, &decimal);
	return (sign * (result + decimal));
}