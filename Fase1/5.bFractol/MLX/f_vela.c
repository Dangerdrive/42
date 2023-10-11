/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_vela.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:50:01 by fde-alen          #+#    #+#             */
/*   Updated: 2023/10/10 21:04:00 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	vela_data_init(t_fractal *fractal)
{
	fractal->name = "❄️ Vela ❄️";
	fractal->id = VELA;
	fractal->escape_value = 4.0;
	fractal->iterations = 100.0;
	fractal->x_shift = -0.5;
	fractal->y_shift = 0.0;
	fractal->zoom = 1;
}

/**
 * Handles the rendering of a Vela fractal pixel.
 *
 * @param[in] x The x-coordinate of the pixel.
 * @param[in] y The y-coordinate of the pixel.
 * @param[in] fractal The fractal structure containing rendering parameters.
 */
void	handle_vela_pixel(int x, int y, t_fractal *fractal)
{
	fractal->color = TOMATO;
	t_complex	z;
	t_complex	c;
	double		z_real_temp;
	int			i;

	i = 0;
	z.real = 0.0;
	z.i = 0.0;
	c.real = map(x, WIDTH, -2.0, +2.0) * fractal->zoom + fractal->x_shift;
	c.i = map(y, HEIGHT, +2.0, -2.0) * fractal->zoom + fractal->y_shift;
	while (i < fractal->iterations)
	{
		z_real_temp = z.real;
		z.real = z.real * z.real - z.i * z.i + c.real;
		z.i = 2 * z_real_temp * z.i + c.i;
		if ((z.real * z.real + z.i * z.i) < fractal->escape_value)
		{
			mlx_put_pixel(fractal->img, x, y, WHITE);
		}
		else if ((z.real * z.real + z.i * z.i) > fractal->escape_value)
		{
			fractal->color = map_color(i, fractal->color, fractal);
			mlx_put_pixel(fractal->img, x, y, fractal->color);
			return ;
		}
		i++;
	}
}

/**
 * Renders the Vela fractal using the provided fractal structure.
 *
 * @param[in] fractal The fractal structure containing rendering parameters.
 */
void	vela_render(t_fractal *fractal)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_vela_pixel(x, y, fractal);
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}
