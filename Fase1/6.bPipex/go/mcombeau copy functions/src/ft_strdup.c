/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:41:59 by fde-alen          #+#    #+#             */
/*   Updated: 2023/12/11 19:27:47 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "pipex.h"


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
