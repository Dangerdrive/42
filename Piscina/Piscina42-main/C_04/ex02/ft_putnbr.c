/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felippe <felippe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:57:53 by felippe           #+#    #+#             */
/*   Updated: 2023/03/16 15:34:21 by felippe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c,1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11); //special case handling
		return;
	}
	if (nb < 0)
		{
		ft_putchar('-'); //is it negative?
		nb = -nb;
		}
	if (nb >= 10)
		{
		ft_putnbr(nb / 10);
		nb = nb % 10;
		}
	if (nb < 10) ft_putchar(nb + '0');
}
