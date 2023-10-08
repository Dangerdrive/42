/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:36:37 by fde-alen          #+#    #+#             */
/*   Updated: 2023/10/07 22:39:41 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	select_fractal(t_fractal *fractal)
{
	if (fractal->id == MANDELBROT)
	{
		fractal->id = JULIA;
		fractal->c.real = (drand48() * 1.2) - 0.8;
		fractal->c.i = (drand48() * 1.4) - 0.7;
		puts("\nJulia set selected - random c values applied\n");
	}
	// else if (fractal->id == JULIA)
	// 	fractal->id = BURNINGSHIP;
	else
		fractal->id = MANDELBROT;
}

void	fractal_init(t_fractal *fractal, int id, double c_x, double c_y)
{
	if (id == MANDELBROT)
		mandelbrot_data_init(fractal);
	if (id == JULIA)
		julia_data_init(fractal, c_x, c_y);
	puts("press G for guide");
	fractal->mlx = mlx_init(WIDTH, HEIGHT, fractal->name, true);
	if (!fractal->mlx)
		exit(EXIT_FAILURE);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
	{
		mlx_terminate(fractal->mlx);
		exit(EXIT_FAILURE);
	}
//events_init(fractal);
}
