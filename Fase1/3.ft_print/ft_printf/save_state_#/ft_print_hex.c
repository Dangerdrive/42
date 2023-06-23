/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:15:11 by fde-alen          #+#    #+#             */
/*   Updated: 2023/06/22 22:42:14 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int num, const char format, const char flag)
{
	char	*str;
	char	*prefix;

	prefix = "0x";
	if (flag == '#')
	{
		if (format == 'x')
			ft_printstr(prefix);
		if (format == 'X')
		{
			ft_string_toupper(prefix);
			ft_printstr(prefix);
		}
	}
	str = ft_itoa_base(num, 16);
	if (format == 'x')
		ft_printstr(str);
	if (format == 'X')
	{
		ft_string_toupper(str);
		ft_printstr(str);
	}
	free(str);
	return (ft_numlen_base(num, 16));
}
