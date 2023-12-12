/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:41:34 by fde-alen          #+#    #+#             */
/*   Updated: 2023/12/11 19:21:59 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenn(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strjoinn(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!str1)
	{
		str1 = (char *)malloc(1 * sizeof(char));
		str1[0] = 0;
	}
	if (!str1 || !str2)
		return (NULL);
	result = malloc(sizeof(char) * ((ft_strlenn(str1) + ft_strlenn(str2)) + 1));
	if (result == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str1)
		while (str1[++i] != '\0')
			result[i] = str1[i];
	while (str2[j] != '\0')
		result[i++] = str2[j++];
	result[ft_strlenn(str1) + ft_strlenn(str2)] = '\0';
	free(str1);
	return (result);
}

char	*ft_strchr(const char *str, int c)
{
	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
