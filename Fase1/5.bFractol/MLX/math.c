/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:56:38 by fde-alen          #+#    #+#             */
/*   Updated: 2023/10/07 22:56:39 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_sum(t_complex a, t_complex b)
{
	t_complex	c;

	c.real = a.real + b.real;
	c.i = a.i + b.i;
	return (c);
}

t_complex	complex_sqr(t_complex a)
{
	t_complex	c;

	c.real = a.real * a.real - a.i * a.i;
	c.i = 2 * a.real * a.i;
	return (c);
}

double	map(double unscaled_num, double old_max, double new_min, double new_max)
{
	double	old_min;
	double	scaled_num;

	if (old_max == 0 || new_max == 0)
		return (1);
	old_min = 0;
	scaled_num = 0;
	scaled_num = ((new_max - new_min) * (unscaled_num - old_min))
		/ (old_max - old_min) + new_min;
	return (scaled_num);
}
