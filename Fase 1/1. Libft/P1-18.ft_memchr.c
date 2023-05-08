/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P1-18.ft_memchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/08 18:28:47 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p = s;

	while (n--)
	{
		if (*p == c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
