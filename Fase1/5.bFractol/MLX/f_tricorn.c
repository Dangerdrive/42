/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tricorn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:50:01 by fde-alen          #+#    #+#             */
/*   Updated: 2023/10/12 18:03:15 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Initializes the fractal structure with parameters for rendering the 
 * Tricorn fractal.
 *
 * @param[in] fractal The fractal struct to be initialized.
 */
void	tricorn_data_init(t_fractal *fractal)
{
	fractal->name = "❄️ Tricorn ❄️";
	fractal->color = TOMATO;
	fractal->id = TRICORN;
	fractal->escape_value = 4.0;
	fractal->iterations = 100.0;
	fractal->x_shift = -0.0;
	fractal->y_shift = 0.0;
	fractal->zoom = 1;
}

/**
 * Renders a Tricorn fractal pixel at coordinates (x, y) within the given 
 * fractal struct.
 *
 * @param[in] x       The x-coordinate of the pixel.
 * @param[in] y       The y-coordinate of the pixel.
 * @param[in] fractal The fractal structure containing rendering parameters.
 */
void	handle_tricorn_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z.real = 0.0;
	z.i = 0.0;
	c.real = map(x, WIDTH, -2.0, +2.0) * fractal->zoom + fractal->x_shift;
	c.i = map(y, HEIGHT, +2.0, -2.0) * fractal->zoom + fractal->y_shift;
	while (i < fractal->iterations)
	{
		z = (complex_sum(complex_conjugate((complex_sqr(z))), c));
		if (((z.real * z.real) + (z.i * z.i)) < fractal->escape_value)
		{
			mlx_put_pixel(fractal->img, x, y, darken_color(fractal));// mlx_put_pixel(fractal->img, x, y, WHITE);
		}
		else if (((z.real * z.real) + (z.i * z.i)) > fractal->escape_value)
		{
			fractal->color2 = map_color(i, fractal->color, fractal);
			mlx_put_pixel(fractal->img, x, y, fractal->color2);
			return ;
		}
		i++;
	}
}

/**
 * Renders the Tricorn fractal using the given fractal structure.
 *
 * @param[in] fractal The fractal structure containing rendering parameters.
 */
void	tricorn_render(t_fractal *fractal)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_tricorn_pixel(x, y, fractal);
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}
