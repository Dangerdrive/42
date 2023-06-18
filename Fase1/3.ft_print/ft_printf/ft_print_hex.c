/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:15:11 by fde-alen          #+#    #+#             */
/*   Updated: 2023/06/17 22:03:12 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int num, const char format)
{
	char	*str;

	str = ft_itoa_base(num, 16);
	if (format == 'x')
		ft_printstr(str);
	if (format == 'X')
		ft_printstr(str);
	return (ft_numlen_base(num, 16));
}
