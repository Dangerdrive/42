/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:30:36 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/18 19:29:49 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}


char	*ft_strdup(const char *src)
{
	char	*dest;
	char	*temp;
	size_t	len;

	len = ft_strlen(src);
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	temp = dest;
	while (*src)
	{
		*temp++ = *src++;
	}
	*temp = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	else
		return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	unsigned int	i;
	unsigned int	srclen;

	i = 0;
	srclen = 0;
	while (src[srclen])
		srclen++;
	if (destsize > 0)
	{
		while (src[i] && i < destsize - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (srclen);
}

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (destsize <= dest_len)
		return (src_len + destsize);
	i = 0;
	while (src[i] && dest_len + i + 1 < destsize)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = (char *)malloc(sizeof(char) * size);
	if (strjoin == NULL)
		return (NULL);
	ft_strlcpy(strjoin, s1, size);
	ft_strlcat(strjoin, s2, size);
	return (strjoin);
}

void	ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
