/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:30:37 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/09 14:28:15 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	char			*start_ptr;
	unsigned int	i;

	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	start_ptr = substr;
	i = 0;
	while (*s && i < start)
	{
		i++;
		s++;
	}
	while (*s && i - start < len)
	{
		*substr = *s;
		i++;
		s++;
		substr++;
	}
	*substr = '\0';
	return (start_ptr);
}
