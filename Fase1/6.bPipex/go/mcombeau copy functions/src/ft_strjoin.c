/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:26:40 by fde-alen          #+#    #+#             */
/*   Updated: 2023/12/11 20:54:09 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "pipex.h"

// char	*ft_strjoin(char *str1, char *str2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*result;

// 	if (!str1)
// 	{
// 		str1 = (char *)malloc(1 * sizeof(char));
// 		str1[0] = 0;
// 	}
// 	if (!str1 || !str2)
// 		return (NULL);
// 	result = malloc(sizeof(char) * ((ft_strlen(str1) + ft_strlen(str2)) + 1));
// 	if (result == NULL)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	if (str1)
// 		while (str1[++i] != '\0')
// 			result[i] = str1[i];
// 	while (str2[j] != '\0')
// 		result[i++] = str2[j++];
// 	result[ft_strlen(str1) + ft_strlen(str2)] = '\0';
// 	free(str1);
// 	return (result);
// }















// void	ft_bzero(void *s, size_t n)
// {
// 	unsigned char	*p;

// 	p = (unsigned char *)s;
// 	while (n != 0)
// 	{
// 		*p = '\0';
// 		p++;
// 		n--;
// 	}
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*r;

// 	r = malloc(count * size);
// 	if (!r)
// 		return (NULL);
// 	ft_bzero(r, size * count);
// 	return (r);
// }

// /*
// 	DESCRIPTION :
// 	The function ft_strjoin concatenates the given strings s1 and s2
// 	and allocates sufficient memory for the newly created string.

// 	RETURN VALUE :
// 	A pointer to the new concatenated string.
// 	NULL if the memory allocation fails.
// */

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*s;
// 	size_t	len;
// 	int		i;

// 	len = ft_strlen(s1) + ft_strlen(s2);
// 	s = ft_calloc(len + 1, sizeof(char));
// 	if (!s)
// 		return (NULL);
// 	len = 0;
// 	while (s1[len])
// 	{
// 		s[len] = s1[len];
// 		len++;
// 	}
// 	i = 0;
// 	while (s2[i])
// 	{
// 		s[len + i] = s2[i];
// 		i++;
// 	}
// 	return (s);
// }

static size_t	ft_strlcatt(char *dest, const char *src, size_t destsize)
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

static size_t	ft_strlcpyy(char *dest, const char *src, size_t destsize)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = (char *)malloc(sizeof(char) * size);
	if (strjoin == NULL)
		return (NULL);
	ft_strlcpyy(strjoin, s1, size);
	ft_strlcatt(strjoin, s2, size);
	return (strjoin);
}