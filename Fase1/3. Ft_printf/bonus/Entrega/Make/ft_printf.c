/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:17:50 by fde-alen          #+#    #+#             */
/*   Updated: 2023/07/11 16:57:17 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_format_type(va_list args, const char *type)
{
	int		len;
	char	flag;

	flag = NO_FLAG;
	len = 0;
	if (*type == '#' || *type == ' ' || *type == '+')
	{
		flag = *type;
		type++;
	}
	if (*type == '%')
		len += ft_print_char('%');
	else if (*type == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (*type == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (*type == 'd' || *type == 'i')
		len += ft_print_nbr(va_arg(args, int), flag);
	else if (*type == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (*type == 'x' || *type == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), *type, flag);
	else if (*type == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long));
	return (len);
}

int	ft_printf(const char *frmt, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, frmt);
	while (*frmt)
	{
		if (*frmt == '%')
		{
			len += parse_format_type(args, frmt + 1);
			if (*(frmt + 1) == '#' || *(frmt + 1) == ' ' || *(frmt + 1) == '+')
				frmt++;
			frmt++;
		}
		else
		{
			if (frmt == NULL)
				return (-1);
			len += ft_print_char(*frmt);
		}
		frmt++;
	}
	va_end(args);
	return (len);
}
