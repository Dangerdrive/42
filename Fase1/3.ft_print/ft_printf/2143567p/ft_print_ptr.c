/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:14:56 by fde-alen          #+#    #+#             */
/*   Updated: 2023/06/24 15:26:47 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long num)
{
	char	*str;
	int		len;

	len = 0;
	if (num == 0)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	else
	{
		if (num < 0)
			num = num * -1;
	}
	str = ft_uitoa_base(num, 16);
	len += write(1, "0x", 2);

	len += ft_printstr(str);
	free(str);
	return (len);
}
