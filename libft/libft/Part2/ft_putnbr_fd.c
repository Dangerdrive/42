/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:05:19 by fde-alen          #+#    #+#             */
/*   Updated: 2023/04/25 20:13:06 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(fd, &c, 1);
}

void ft_putnbr_fd(int n, int fd)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(fd('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	nb = nb % 10;
	}
	if (nb < 10)
		write(fd,(nb + '0'), 1);;
}

// #include "libft.h"

// void ft_putnbr_fd(int n, int fd)
// {
// }
// #1. The integer to output.
// #2. The file descriptor on which to write.
// None
// write
// Outputs the integer ’n’ to the given file
// descriptor.

// Parameters
// Return value
// External functs.
// Description