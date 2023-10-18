/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_mandelbrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:50:01 by fde-alen          #+#    #+#             */
/*   Updated: 2023/10/17 23:48:15 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Initializes the Mandelbrot fractal data in the given fractal structure.
 *
 * @param[in] fractal The fractal structure to be initialized.
 */
void	mandelbrot_data_init(t_fractal *fractal)
{
	fractal->name = "❄️ Mandelbrot ❄️";
	fractal->color = CYAN;
	fractal->id = MANDELBROT;
	fractal->escape_value = 4.0;
	fractal->iterations = 100;
	fractal->x_shift = +0.7 * fractal->initial_zoom;
	fractal->y_shift = 0.0;
	fractal->initial_zoom = 0.7;
	fractal->zoom_factor = 1.1;
	fractal->xmin = -2.0 * fractal->initial_zoom;
	fractal->xmax = 2.0 * fractal->initial_zoom;
	fractal->ymin = -2.0 * fractal->initial_zoom;
	fractal->ymax = 2.0 * fractal->initial_zoom;
}

/**
 * Handles the rendering of a Mandelbrot fractal pixel.
 *
 * @param[in] x The x-coordinate of the pixel.
 * @param[in] y The y-coordinate of the pixel.
 * @param[in] fractal The fractal structure containing rendering parameters.
 */
void	handle_mandelbrot_pixel(int x, int y, t_fractal *fractal)
{
	t_complex		z;
	t_complex		c;
	unsigned int	i;

	i = 0;
	z.real = 0.0;
	z.i = 0.0;

	c.real = map(x, WIDTH, fractal->xmin, fractal->xmax)
		+ fractal->x_shift * fractal->zoom ;
	c.i = map(y, HEIGHT, fractal->ymin, fractal->ymax)
		+ fractal->y_shift * fractal->zoom;
	while (i < fractal->iterations)
	{
		z = complex_sum(complex_sqr(z), c);
		if ((((z.real * z.real) + (z.i * z.i)) < fractal->escape_value))
			mlx_put_pixel(fractal->img, x, y, darken_color(fractal));
		else if ((z.real * z.real + z.i * z.i) > fractal->escape_value)
		{
			fractal->color2 = map_color(i, fractal->color, fractal);
			mlx_put_pixel(fractal->img, x, y, fractal->color2);
			return ;
		}
		i++;
	}
}

/**
 * Renders the Mandelbrot fractal using the provided fractal structure.
 *
 * @param[in] fractal The fractal structure containing rendering parameters.
 */
void	mandelbrot_render(t_fractal *fractal)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_mandelbrot_pixel(x, y, fractal);
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}
