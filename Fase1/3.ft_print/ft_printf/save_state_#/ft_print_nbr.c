/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:15:31 by fde-alen          #+#    #+#             */
/*   Updated: 2023/06/24 15:49:27 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int num, const char flag)
{
	int		count;
	char	*str;

	count = 0;
	if (flag == '+')
	{
		if (num >= 0)
			count += write(1, "+", 1);
		else
		{	
			count += write(1, "-", 1);
			num *= -1;
		}
	}
	if (num == 0)
		return (write(1, "0", 1));
	else if (num != 0)
	{
		if (flag == ' ')
			count += write(1, " ", 1);
	}
	str = ft_itoa_base(num, 10);
	count = ft_printstr(str);
	free(str);
	return (count);
}