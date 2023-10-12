/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_burningship.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:50:01 by fde-alen          #+#    #+#             */
/*   Updated: 2023/10/11 22:06:25 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burningship_init(t_fractal *fractal)
{
	fractal->color = GOLD;
	fractal->name = "❄️ BURNING SHIP ❄️";
	fractal->id = BURNING;
	fractal->escape_value = 4.0;
	fractal->iterations = 100.0;
	fractal->x_shift = -0.5;
	fractal->y_shift = 0.0;
	fractal->zoom = 1;
}

/**
 * Renders a Burning Ship fractal pixel at coordinates (x, y) within the given 
 * fractal struct.
 *
 * @param[in] x       The x-coordinate of the pixel.
 * @param[in] y       The y-coordinate of the pixel.
 * @param[in] fractal The fractal structure containing rendering parameters.
 */
void handle_burningship_pixel(int x, int y, t_fractal *fractal)
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
		double temp = z.real;
		z.real = fabs(z.real * z.real - z.i * z.i) + c.real;
		z.i = fabs(2 * temp * z.i) + c.i;
		if ((z.real * z.real + z.i * z.i) > fractal->escape_value)
		{
			fractal->color2 = map_color(i, fractal->color, fractal);
			mlx_put_pixel(fractal->img, x, y, fractal->color2);
			return ;
		}
		i++;
	}
}

void	burningship_render(t_fractal *fractal)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_nova_pixel(x, y, fractal);
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}
