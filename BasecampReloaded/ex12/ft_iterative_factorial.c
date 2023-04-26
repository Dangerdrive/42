/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:42:57 by fde-alen          #+#    #+#             */
/*   Updated: 2023/04/24 18:42:20 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;
	int	i;

	i = 1;
	result = 1;
	if ((nb < 0) || (nb > 12))
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	while (i <= nb)
	{
			result = i * result;
			i++;
	}
	return (result);
}
