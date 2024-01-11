/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:15:31 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/10 18:39:06 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int fd, int num, const char flag)
{
	int		count;
	char	*str;

	count = 0;
	if (flag == '+')
	{
		if (num >= 0)
			count += write(fd, "+", 1);
	}
	else if (flag == ' ')
	{
		if (num >= 0)
			count += write(fd, " ", 1);
	}
	str = ft_itoa(num);
	count += ft_print_str(fd, str);
	free(str);
	return (count);
}
