/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:14:56 by fde-alen          #+#    #+#             */
/*   Updated: 2023/07/11 14:09:48 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long int num)
{
	char	*str;
	int		len;

	len = 0;
	if (num == 0)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	str = ft_uitoa_base(num, 16, 'x');
	len += write(1, "0x", 2);
	len += ft_print_str(str);
	free(str);
	return (len);
}
