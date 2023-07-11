/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:15:31 by fde-alen          #+#    #+#             */
/*   Updated: 2023/07/10 12:44:15 by fde-alen         ###   ########.fr       */
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
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
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

// char	*ft_string_toupper(char *str)
// {
// 	char	*dest;
// 	char	*temp;
// 	size_t	len;

// 	len = ft_strlen(src);
// 	dest = malloc((len + 1) * sizeof(char));
// 	if (dest == NULL)
// 		return (NULL);
// 	temp = dest;
// 	while (*src)
// 	{
// 		if (*src >= 'a' && *src <= 'z')
// 			*temp++ = *src++ + ('A' - 'a');
// 		else
// 			*temp++ = *src++;
// 	}
// 	*temp = '\0';
// 	return (dest);
// }
