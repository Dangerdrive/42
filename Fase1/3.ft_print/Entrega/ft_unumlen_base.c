/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlem_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:10:09 by fde-alen          #+#    #+#             */
/*   Updated: 2023/07/11 13:50:17 by fde-alen         ###   ########.fr       */
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
