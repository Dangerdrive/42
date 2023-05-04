/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalphatest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/03 13:24:37 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>


int	isalphatest()
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