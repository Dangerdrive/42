/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:41:59 by fde-alen          #+#    #+#             */
/*   Updated: 2023/04/24 17:06:57 by fde-alen         ###   ########.fr       */
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
	int		i;
	size_t	n;
	int		*arr;

	if (min >= max)
		return (NULL);
	n = max - min;
	arr = malloc(n * sizeof(int));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while ((min + i) < max)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
