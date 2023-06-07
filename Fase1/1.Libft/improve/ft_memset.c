/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P1-07.ft_memset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/08 18:29:10 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp_str;
	unsigned char	tmp_char;

	tmp_str = s;
	tmp_char = c;
	while (n-- > 0)
	{
		*tmp_str++ = tmp_char;
	}
	return (s);
}
