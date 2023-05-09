/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P2-01.ft_substr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:30:37 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/08 18:36:18 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (*s && i < start)
	{
		i++;
	}
	while (*s && i - start < len)
	{
		*substr = s[i];
		i++;
		substr++;
	}
	*substr = '\0';
	return (substr - len);
}
