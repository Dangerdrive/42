/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalphatest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2023/04/25 20:57:46 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	main()
{
	char	c;

	c = '0';
	printf("%d\n", isalpha(c));
	c = 'a';
	printf("%d\n", isalpha(c));
	c = 'X';
	printf("%d\n", isalpha(c));
	c = '&';
	printf("%d\n", isalpha(c));
}
// #include <ctype.h>
// int isalpha(int c);