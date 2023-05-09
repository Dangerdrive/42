/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P2-07.ft_striteri.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:22:34 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/08 18:22:35 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #1. The string on which to iterate.
// #2. The function to apply to each character.
// None.
// None
// Applies the function f to each character of the
// string passed as argument, and passing its index
// as first argument. Each character is passed by
// address to f to be modified if necessary

// Parameters
// Return value
// External functs.
// Description