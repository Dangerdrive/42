/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_julia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:49:54 by fde-alen          #+#    #+#             */
/*   Updated: 2023/10/07 19:21:23 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_julia_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	int 		i;

	i = 0;
	z.real = map(x, WIDTH, -2.0, +2.0) * fractal->zoom + fractal->x_shift;
	z.i = map(y, HEIGHT, +2.0 , -2.0) * fractal->zoom + fractal->y_shift;

	while (i < fractal->iterations)
	{
		z = complex_sum(complex_sqr(z), fractal->c);
		// if ((((z.real * z.real) + (z.i * z.i)) < fractal->escape_value))
		// 	mlx_put_pixel(fractal->img, x, y, WHITE);
		if (((z.real * z.real) + (z.i * z.i)) > fractal->escape_value)
		{
		//fractal->color = map(i,fractal->iterations, CYAN*0.2, CYAN*0.7);
		fractal->color = map_color(fractal->img, i, fractal);
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











/*
diferenças minilibx e MLX codam
mlx_init -> mlx_init_window
mlx_init da codam já cria a janela, enquanto a da minilibx não. A da minilibx só cria a conexão.
então ela recebe parametros para a criação da janela também.

as structs de imagem são diferentes. Você nao tem uma mlx_get_address pra modificar valores da imagem.

typedef struct mlx_image
{
	const uint32_t	width;
	const uint32_t	height;
	uint8_t*		pixels;
	mlx_instance_t*	instances;
	size_t			count;
	bool			enabled;
	void*			context;
}	mlx_image_t;


*/

























