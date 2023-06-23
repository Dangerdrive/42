/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:17:50 by fde-alen          #+#    #+#             */
/*   Updated: 2023/06/23 19:55:33 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	set_flags(const char flag)
// {
// 	int	flag_set;

// 	flag_set = 0;
// 	if (flag == '#')
// 		return (flag_set |= FLAG_HASH);
// 	else if (flag == ' ')
// 		return (flag_set |= FLAG_SPACE);
// 	else if (flag == '+')
// 		return (flag_set |= FLAG_PLUS);
// 	return (0);
// }

// int	parse_flags(va_list args, const char flag)
// {
// 	int	len;

// 	len = 0;
// 	if (flag == '#')
// 	{
// 		//if X, printar 0X
// 		//if X, printar 0x
// 	}	//len += ft_printchar(va_arg(args, int));
// 	else if (flag == ' ')
// 	{
// 			return (len += ft_printchar(' '));
// 	}
// 	else if (flag == '+')
// 	{
// 		if (va_arg(args, int) >= 0)
// 			return (len += ft_printchar('+'));
// 		else
// 			return (len += ft_printchar('-'));
// 	}
// 	return (0);
// }

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

int	ft_printf(const char *frmt, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, frmt);
	while (frmt[i])
	{
		if (frmt[i] == '%')
		{
			if (frmt[i + 1] == '#' || frmt[i + 1] == ' ' || frmt[i + 1] == '+')
			{
			len += parse_format_type(args, frmt[i + 2], frmt[i + 1]);
			i++;
			}
			len += parse_format_type(args, frmt[i + 1], NO_FLAG);
			i++;
		}
		else
			len += ft_printchar(frmt[i]);
		i++;
	}
	va_end(args);
	return (len);
}


int main()
{
//     // Testing %c - Prints a single character
//     ft_printf("Character: %c\n", 'A');

//     // Testing %s - Prints a string
//     ft_printf("String: %s\n", "Hello, World!");

//     // Testing %p - Prints a void * pointer in hexadecimal format
//     void* ptr = NULL; // Replace NULL with an actual pointer value if desired
//     ft_printf("Pointer: %p\n", ptr);

    // Testing %d - Prints a decimal (base 10) number
    ft_printf("Decimal: %d\n", 12345);

    // Testing %i - Prints an integer in base 10
    ft_printf("negative Decimal: %i\n", -94967295);

	    // Testing %+d - Prints a decimal (base 10) number
    ft_printf("ft_Decimal: %+d\n", 12345);
    printf("printf_Decimal: %+d\n", 12345);

    // Testing %+i - Prints an integer in base 10
    ft_printf("ft_negative Decimal: %+i\n", -94967295);
    printf("printf_negative Decimal: %+i\n", -94967295);
	
    // Testing %+i - i = 0
    ft_printf("ft_0: %+i\n", 0);
    printf("printf_0: %+i\n", 0);

//     // Testing %x - Prints a number in hexadecimal (base 16) lowercase format
//     ft_printf("Hexadecimal (lowercase): %x\n", 255);

//     // Testing %X - Prints a number in hexadecimal (base 16) uppercase format
//     ft_printf("Hexadecimal (uppercase): %X\n", 255);

//     // Testing %% - Prints a percent sign
//     ft_printf("Percent Sign: %%\n");

    return 0;
}



// #include <limits.h>
// int	main()
// {
// 	ft_printf("\n %p %p \n", LONG_MIN, LONG_MAX);
// 	ft_printf("\n %p %p \n", ULONG_MAX, -ULONG_MAX);
// 	//ft_printf(" %p %p \n", 0, 0);
// }
