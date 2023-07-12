/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:17:50 by fde-alen          #+#    #+#             */
/*   Updated: 2023/07/12 11:58:36 by fde-alen         ###   ########.fr       */
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
	int		i;

	i = 0;
	len = 0;
	if (frmt == NULL)
		return (-1);
	va_start(args, frmt);
	while (frmt[i])
	{
		if (frmt[i] == '%')
		{
			len += parse_format_type(args, &frmt[i + 1]);
			if (frmt[i + 1] == '#' || frmt[i + 1] == ' ' || frmt[i + 1] == '+')
				i++;
			i++;
		}
		else
			len += ft_print_char(frmt[i]);
		i++;
	}
	va_end(args);
	return (len);
}
