/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:57:21 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/10 22:47:35 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (n);
}

static size_t	word_length(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*copy_word(const char *s, size_t len)
{
	char	*word;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;

	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (i < count_words(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		split[i] = copy_word(&s[j], word_length(&s[j], c));
		if (!split[i])
			return (NULL);
		i++;
		j += word_length(&s[j], c);
	}
	split[i] = NULL;
	return (split);
}

// char	**ft_split(char const *s, char c)
// {
// 	char	**split;
// 	size_t	i;
// 	size_t	j;

// 	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
// 	if (!split)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (i < count_words(s, c))
// 	{
// 		while (s[j] && s[j] == c)
// 			j++;
// 		split[i] = copy_word(&s[j], word_length(&s[j], c));
// 		if (!split[i])
// 		{
// 			while (i > 0)
// 				free(split[--i]);
// 			free(split);
// 			return (NULL);
// 		}
// 		i++;
// 		j += word_length(&s[j], c);
// 	}
// 	split[i] = NULL;
// 	return (split);
// }