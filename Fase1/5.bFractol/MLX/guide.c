/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:44:47 by fde-alen          #+#    #+#             */
/*   Updated: 2023/10/07 22:44:48 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	guide(void)
{
	puts("Controls:\n" \
	"\tpress \033[1m\033[38;5;110mESC\033[0m to exit\n" \
	"\tpress \033[1m\033[38;5;110marrow keys\033[0m to move\n" \
	"\tuse \033[1m\033[38;5;110mmouse scroll\033[0m for zoom\n" \
	"\tuse \033[1m\033[38;5;110mleft_shift + scroll\033[0m for zoom\n" \
	"\tpress \033[1m\033[38;5;110mTAB\033[0m to change fractal\n" \
	"\tpress \033[1m\033[38;5;110mR\033[0m to randomize julia set\n");
}
