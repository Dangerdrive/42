/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:42:51 by fde-alen          #+#    #+#             */
/*   Updated: 2023/06/23 19:56:19 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen_base(long long num, int base)
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


char	*ft_itoa_base(long long num, int base)
{
	char	*str;
	int		len;
	int		sign;

	if (num < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_numlen_base(num, base);
	if (sign == -1)
		len++;
	//printf("\nlen: %d\n", len);//debug
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



// int	main()
// {
// 	char	*str = ft_itoa_base(9223372036854775808, 16);
// 	printf("%s\n", str);
// 	str = ft_itoa_base(18446744073709551615, 16);
// 	printf("%s\n", str);
// }
