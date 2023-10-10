/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:56:38 by fde-alen          #+#    #+#             */
/*   Updated: 2023/10/10 00:26:21 by fde-alen         ###   ########.fr       */
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

/**
 * Computes the square of a complex number.
 *
 * This function takes a complex number 'a' and computes its square,
 * resulting in a new complex number 'squared'.
 *
 * @param[in] a The complex number to be squared.
 *
 * @return The square of the complex number 'a'.
 */
t_complex	complex_sqr(t_complex a)
{
	t_complex	c;

	c.real = a.real * a.real - a.i * a.i;
	c.i = 2 * a.real * a.i;
	return (c);
}

t_complex	complex_conjugate(t_complex a)
{
	t_complex	c;

	c.real = a.real;
	c.i = -a.i;
	return (c);
}

t_complex	complex_power(t_complex a, int n)
{
	t_complex	result;
	t_complex	temp;

	// Initialize result to (1, 0)
	result.real = 1.0;
	result.i = 0.0;
	// Perform the power operation using repeated multiplication
	int i = 0;
	while (i < n)
	{
	// Store the current result in temp
		temp = result;

	// Multiply temp by a and update result
		result.real = temp.real * a.real - temp.i * a.i;
		result.i = temp.real * a.i + temp.i * a.real;

		i++;
	}
	return (result);
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
