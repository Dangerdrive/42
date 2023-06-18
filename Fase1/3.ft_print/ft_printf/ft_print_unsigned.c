/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:16:38 by fde-alen          #+#    #+#             */
/*   Updated: 2023/06/17 21:40:15 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int num)
{
	char	*str;
	int		len;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	str = ft_itoa_base(num, 10);
	len = ft_printstr(str);
	free(str);
	return (len);
}
