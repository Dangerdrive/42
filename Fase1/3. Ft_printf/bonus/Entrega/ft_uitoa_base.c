/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:35:21 by fde-alen          #+#    #+#             */
/*   Updated: 2023/07/10 22:35:23 by fde-alen         ###   ########.fr       */
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

char	*ft_uitoa_base(unsigned long num, int base, const char format)
{
	char	*str;
	int		len;

	len = ft_unumlen_base(num, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		if (format == 'x')
			str[len--] = "0123456789abcdef"[num % base];
		if (format == 'X')
			str[len--] = "0123456789ABCDEF"[num % base];
		num /= base;
	}
	return (str);
}
