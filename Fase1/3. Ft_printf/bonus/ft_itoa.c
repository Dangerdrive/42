/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:42:51 by fde-alen          #+#    #+#             */
/*   Updated: 2023/07/10 20:35:08 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_numlen_base(long long num, int base)
// {
// 	int	len;

// 	len = 1;
// 	while (num / base)
// 	{
// 		num /= base;
// 		len++;
// 	}
// 	return (len);
// }

// char	*ft_itoa_base(long long int num, int base)
// {
// 	char	*str;
// 	int		len;
// 	int		sign;

// 	sign = 1;
// 	if (num < 0)
// 		sign = -1;
// 	len = ft_numlen_base(num, base);//
// 	if (sign == -1)
// 		len++;
// 	str = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	str[len--] = '\0';
// 	while (len >= 0)
// 	{
// 		str[len--] = "0123456789abcdef"[num % base];
// 		num /= base;
// 	}
// 	if (sign == -1)
// 		str[0] = '-';
// 	return (str);
// }

int	ft_numlen(int num)
{
	int	len;

	len = 1;
	while (num / 10)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int num)
{
	char	*str;
	int		len;
	int		sign;

	if (num < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_numlen(num);
	if (sign == -1)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = (sign * (num % 10)) + '0';
		num /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

// int	main()
// {
// 	char	*str = ft_itoa(-31);
// 	printf("%s", str);
// }
