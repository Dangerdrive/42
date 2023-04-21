/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:41:59 by fde-alen          #+#    #+#             */
/*   Updated: 2023/04/21 16:45:43 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	*ft_range(int min, int max)
{
	size_t	n;
	int	i;

	if (min >= max)
		return (NULL);
	n = max - min - 1;
	i = 0;
	while ((min + i) < max)
	{
		arr[i] = min + i;
		i++;
	}
}
	// char	*dest;
	// char	*temp;
	// size_t	len;

	// len = ft_strlen(src);
	// dest = malloc(len + 1);
	// if (dest == NULL)
	// 	return (NULL);
	// temp = dest;
	// while (*src)
	// {
	// 	*temp++ = *src++;
	// }
	// *temp = '\0';
	// return (dest);

