/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:41:34 by fde-alen          #+#    #+#             */
/*   Updated: 2023/06/01 21:54:24 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
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

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

// char	*ft_strchr(const char *str, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	if (c == '\0')
// 		return ((char *)&str[ft_strlen(str)]);
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == (unsigned char) c)
// 			return ((char *)&str[i]);
// 		i++;
// 	}
// 	return (0);
// }

char	*ft_strchr(const char *str, int c)
{
	if (str == NULL)
		return (NULL);

	if (c == '\0')
		return ((char *)(str + ft_strlen(str)));

	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
			return ((char *)str);

		str++;
	}

	return (NULL);
}