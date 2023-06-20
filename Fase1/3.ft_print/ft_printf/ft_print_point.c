/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:14:56 by fde-alen          #+#    #+#             */
/*   Updated: 2023/06/19 21:09:36 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long num)
{
	char	*str;
	int		len;

	printf("num1: %llu\n", num);
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
		printf("num2if: %llu\n", num);
	}
	str = ft_itoa_base(num, 16);
	printf("num3: %llu\n", num);
	len += write(1, "0x", 2);
	// if (num == 0)
	// 	len += write(1, "0", 1);
		len += ft_printstr(str);
		free(str);
//	}	
	return (len);
}
