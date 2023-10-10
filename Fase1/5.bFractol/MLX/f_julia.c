/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_julia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:49:54 by fde-alen          #+#    #+#             */
/*   Updated: 2023/10/10 00:36:10 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_julia_pixel(int x, int y, t_fractal *fractal)
{
	fractal->color = CYAN;
	t_complex	z;
	int 		i;

	i = 0;
	z.real = map(x, WIDTH, -2.0, +2.0) * fractal->zoom + fractal->x_shift;
	z.i = map(y, HEIGHT, +2.0 , -2.0) * fractal->zoom + fractal->y_shift;

	while (i < fractal->iterations)
	{
		z = complex_sum(complex_sqr(z), fractal->c);
		if ((((z.real * z.real) + (z.i * z.i)) < fractal->escape_value))
			{
				//fractal->color = map_color(i, fractal->color * 0.9, fractal);
				mlx_put_pixel(fractal->img, x, y, fractal->color * 0.9995);
			}
		//if (((z.real * z.real) + (z.i * z.i)) > fractal->escape_value)
		else
		{
		fractal->color = map_color(i, fractal->color, fractal);
			mlx_put_pixel(fractal->img, x, y, fractal->color);
			return;
		}
		i++;
	}
}

void	julia_data_init(t_fractal *fractal,double c_x, double c_y)
{
	fractal->name = "❄️ Julia ❄️";
	fractal->id = JULIA;
	fractal->escape_value = 4.0;
	fractal->iterations = 100.0;
	fractal->x_shift = 0.0;
	fractal->y_shift = 0.0;
	fractal->zoom = 1;
	fractal->c.real = c_x;
	fractal->c.i = c_y;
}

void	randomize_julia(t_fractal *fractal_ptr)
{
	fractal_ptr->c.real = (drand48() * 1.2) - 0.8;
	fractal_ptr->c.i = fractal_ptr->c.i = (drand48() * 1.4) - 0.7;
	puts("\nJulia set selected - random c values applied\n");
	//printf("c = %f + %fi\n", fractal_ptr->c.real, fractal_ptr->c.i);
}

void julia_render(t_fractal *fractal)
{
	int y;
	int x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_julia_pixel(x, y, fractal);
	}
mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}
