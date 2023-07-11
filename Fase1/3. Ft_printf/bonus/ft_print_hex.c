/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:15:11 by fde-alen          #+#    #+#             */
/*   Updated: 2023/07/10 12:56:05 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stddef.h>

size_t ft_strlen(const char *str)
{
    if (str == NULL)
		return (0);
	size_t len = 0;
    while (str[len] != '\0')
        len++;
    return (len);
}

int	ft_print_hex(unsigned int num, const char format, const char flag)
{
	char	*str;
	int		len;
	// char	*prefix;

	// prefix = NULL;
	len = 0;
	if (flag == '#' && num != 0)
	{
		//prefix = "0x";
		if (format == 'x')
			len += ft_printstr("0x");
		if (format == 'X')
		{
			//ft_string_toupper(prefix);
			len += ft_printstr("0X");
		}
	}
	if (format == 'x')
		str = ft_uitoa_base(num, 16, 'x');
	if (format == 'X')
		str = ft_uitoa_base(num, 16, 'X');
	len += ft_printstr(str);
	free(str);
	return (len);
}

// int	main()
// {
// 	int		num = 33;
// 	int		len;
// 	char	format = 'x';
// 	char	flag = '#';

// 	len = ft_print_hex(num, format, flag);
// 	printf("\n%#x\n", num);
// 	return (0);
// }
