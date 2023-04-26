/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:04:09 by fde-alen          #+#    #+#             */
/*   Updated: 2023/04/24 17:04:37 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_ft(int *nbr);

int	main(void)
{
	int	*number = malloc(sizeof(int));

	ft_ft(number);
	printf("%d", *number);
	free(number);
}
