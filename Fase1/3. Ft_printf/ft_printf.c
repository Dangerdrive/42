/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:17:50 by fde-alen          #+#    #+#             */
/*   Updated: 2023/07/06 16:05:11 by fde-alen         ###   ########.fr       */
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

// #include <limits.h>
// int	main()
// {
// 	ft_printf("\n ft long min: %p \n", LONG_MIN);
// 	ft_printf("\n ft -ulong max: %p \n", -ULONG_MAX);
// 	printf("\n printf long min: %p \n", LONG_MIN);
// 	printf("\n printf-ulong max: %p \n", -ULONG_MAX);
// 	//ft_printf(" %p %p \n", 0, 0);
// }
