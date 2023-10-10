/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tricorn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:50:01 by fde-alen          #+#    #+#             */
/*   Updated: 2023/10/09 20:27:40 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	tricorn_data_init(t_fractal *fractal)
{
	fractal->name = "❄️ Tricorn ❄️";
	fractal->id = TRICORN;
	fractal->escape_value = 4.0;
	fractal->iterations = 100.0;
	fractal->x_shift = -0.5;
	fractal->y_shift = 0.0;
	fractal->zoom = 1;
}
void handle_tricorn_pixel(int x, int y, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	int i;

	i = 0;
	z.real = 0.0;
	z.i = 0.0;

	c.real = map(x, WIDTH, -2.0, +2.0) * fractal->zoom + fractal->x_shift;
	c.i = map(y, HEIGHT, +2.0 , -2.0) * fractal->zoom + fractal->y_shift;

	while (i < fractal->iterations)
	{
		z = (complex_sum(complex_conjugate(complex_sqr(z))),c); // Use complex_conjugate here.
		// z = complex_sum(z, c);
		if (((z.real * z.real) + (z.i * z.i)) < fractal->escape_value)
		{
	        mlx_put_pixel(fractal->img, x, y, WHITE);
        }
    	else if (((z.real * z.real) + (z.i * z.i)) > fractal->escape_value)
		{
			fractal->color = map_color(i, fractal->color, fractal);
			mlx_put_pixel(fractal->img, x, y, fractal->color);
			return;
		}
		i++;
	}
}

void tricorn_render(t_fractal *fractal)
{
	int y;
	int x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_tricorn_pixel(x, y, fractal);
	}
mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}