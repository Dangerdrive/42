#include "fractol.h"

// static void	ft_get_decimal(char *str, double *decimal)
// {
// 	double	factor;

// 	factor = 1;
// 	if (*str == '.')
// 		str++;
// 	while (*str)
// 	{
// 		*decimal = *decimal * 10 + (*str - '0');
// 		factor *= 10;
// 		str++;
// 	}
// 	*decimal /= factor;
// }


// double	ft_atod(char *str)
// {
// 	double	result;
// 	double	decimal;
// 	int		sign;

// 	result = 0;
// 	decimal = 0;
// 	sign = 1;
// 	if (*str == '-')
// 	{
// 		sign = -1;
// 		str++;
// 	}
// 	while (*str && *str != '.')
// 	{
// 		result = result * 10 + (*str - '0');
// 		str++;
// 	}
// 	ft_get_decimal(str, &decimal);
// 	return (sign * (result + decimal));
// }

/**
 * @brief Converts a string to a double
 *
 * @param str The string to convert
 *
 * @return double The converted string
 */
double	ft_atod(char *str)
{
	long	integer_part;
	double	decimal_part;
	double	decimal_factor;
	int		sign;

	integer_part = 0;
	decimal_part = 0;
	sign = 1;
	decimal_factor = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	if(*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
while ((*str >= '0' && *str <= '9') && *str && *str != '.')
		integer_part = integer_part * 10 + (*str++ - '0');
	if (*str == '.')
		++str;
	while ((*str >= '0' && *str <= '9') && *str)
	{
		decimal_factor /= 10;
		decimal_part += (*str++ - '0') * decimal_factor;
	}
	return ((integer_part + decimal_part) * sign);
}
