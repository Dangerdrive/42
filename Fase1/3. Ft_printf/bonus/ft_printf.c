/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:17:50 by fde-alen          #+#    #+#             */
/*   Updated: 2023/07/10 22:31:32 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format_type(va_list args, const char type, const char flag)
{
	int	len;

	len = 0;
	if (type == '%')
		len += ft_printchar('%');
	else if (type == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (type == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		len += ft_print_nbr(va_arg(args, int), flag);
	else if (type == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), type, flag);
	else if (type == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long));
	return (len);
}

// int	ft_printf(const char *frmt, ...)
// {
// 	va_list	args;
// 	int		i;
// 	int		len;

// 	i = 0;
// 	len = 0;
// 	va_start(args, frmt);
// 	while (frmt[i])
// 	{
// 		if (frmt[i] == '%')
// 		{
// 			if (frmt[i + 1] == '#' || frmt[i + 1] == ' ' || frmt[i + 1] == '+')
// 			{
// 				len += parse_format_type(args, frmt[i + 2], frmt[i + 1]);
// 				i++;
// 			}
// 			len += parse_format_type(args, frmt[i + 1], NO_FLAG);
// 			i++;
// 		}
// 		else
// 			len += ft_printchar(frmt[i]);
// 		i++;
// 	}
// 	va_end(args);
// 	return (len);
// }

int ft_printf(const char *frmt, ...)
{
	va_list args;
	int i = 0;
	int len = 0;

	va_start(args, frmt);
	while (frmt[i])
	{
		if (frmt[i] == '%')
		{
			if (frmt[i + 1] == '#' || frmt[i + 1] == ' ' || frmt[i + 1] == '+')
			{
				len += parse_format_type(args, frmt[i + 2], frmt[i + 1]);
				i += 2;
			}
			else
			{
				len += parse_format_type(args, frmt[i + 1], NO_FLAG);
				i++;
			}
		}
		else
		{
			len += ft_printchar(frmt[i]);
		}
		i++;
	}
	va_end(args);
	return len;
}

// int	main(void)
// {
// 	// int x = ft_printf("%x\n", 31);
// 	// printf("%i\n", x);
// 	// x = printf("%x\n", 31);
// 	// printf("%i\n", x);


// 	int x = ft_printf("ft %#X\n", 31);
// 	printf("%i\n", x);
// 	x = printf("printf %#X\n", 31);
// 	printf("y = %i\n", x);
// }

// int	main(void)
// {
// 	int x = ft_printf("ft % d\n", 0);
// 	printf("%i\n", x);
// 	x = printf("ft % d\n", 0);
// 	printf("%i\n", x);
// }

int	main(void)
{
ft_printf(" % s % s ", "", "-");
// 	printf("%i\n", x);
	int x = printf(" % s % s ", "", "-");
// 	printf("%i\n", x);
}
