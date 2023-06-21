/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:15:31 by fde-alen          #+#    #+#             */
/*   Updated: 2023/06/19 21:18:26 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int num)
{
	int		i;
	char	*str;

	i = 0;
	if (num == 0)
		return (write(1, "0", 1));
	str = ft_itoa_base(num, 10);
	i = ft_printstr(str);
	free(str);
	return (i);
}

void	ft_string_toupper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str = *str + ('A' - 'a');
		}
		str++;
	}
}