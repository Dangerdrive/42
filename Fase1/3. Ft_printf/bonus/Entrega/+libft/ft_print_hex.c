/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:15:11 by fde-alen          #+#    #+#             */
/*   Updated: 2023/07/11 14:10:25 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int num, const char format, const char flag)
{
	char	*str;
	int		len;

	len = 0;
	if (flag == '#' && num != 0)
	{
		if (format == 'x')
			len += ft_print_str("0x");
		if (format == 'X')
			len += ft_print_str("0X");
	}
	if (format == 'x')
		str = ft_uitoa_base(num, 16, 'x');
	if (format == 'X')
		str = ft_uitoa_base(num, 16, 'X');
	len += ft_print_str(str);
	free(str);
	return (len);
}
