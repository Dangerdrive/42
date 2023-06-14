/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P2-02.ft_strjoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:26:40 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/08 18:36:31 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
