/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:42:51 by fde-alen          #+#    #+#             */
/*   Updated: 2023/07/06 15:42:20 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unumlen_base(unsigned long num, int base)
{
	int	len;

	len = 1;
	while (num / base)
	{
		num /= base;
		len++;
	}
	return (len);
}

char	*ft_uitoa_base(unsigned long num, int base)
{
	char	*str;
	int		len;
	int		sign;

	if (num < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_unumlen_base(num, base);
	if (sign == -1)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = "0123456789abcdef"[num % base];
		num /= base;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

// #include <stdio.h>
// int	main()
// {
// 	// char	*str = ft_uitoa_base(-1, 16);
// 	// printf("%s\n", str);
// 	// str = ft_uitoa_base(-27, 16);
// 	// printf("%s\n", str);
// 	printf("%p\n", -1);
// }


