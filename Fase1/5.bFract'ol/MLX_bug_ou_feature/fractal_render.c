#include "fractol.h"



// void	handle_pixel(int x, int y, t_fractal *fractal)
// {
// 	t_complex	z;
// 	t_complex	c;
// 	int 		i;

// 	i = 0;
// 	z.real = 0.0;
// 	z.imaginary = 0.0;

// 	c.real = map(x, WIDTH, -2.0, +2.0) * fractal->zoom + fractal->x_shift;
// 	c.imaginary = map(y, HEIGHT, +2.0 , -2.0) * fractal->zoom + fractal->y_shift;

// 	while (i < fractal->iterations)
// 	{
// 		z = complex_sum(complex_sqr(z), c);
// 		if ((((z.real * z.real) + (z.imaginary * z.imaginary)) < fractal->escape_value))
// 			mlx_put_pixel(fractal->img, x, y, WHITE);
// 		if (((z.real * z.real) + (z.imaginary * z.imaginary)) > fractal->escape_value)
// 		{
// 			//fractal->color = map_color(i,fractal->iterations, TOMATO*0.1, WHITE*0.2);
// 			fractal->color = map_color(calculate_mu(z),fractal->iterations, TOMATO, GOLD);
// 			mlx_put_pixel(fractal->img, x, y, fractal->color);
// 			return;
// 		}
// 		i++;
// 	}
// }

void	handle_mandelbrot_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int 		i;

	i = 0;
	z.real = 0.0;
	z.imaginary = 0.0;

	c.real = map(x, WIDTH, -2.0, +2.0) * fractal->zoom + fractal->x_shift;
	c.imaginary = map(y, HEIGHT, +2.0 , -2.0) * fractal->zoom + fractal->y_shift;

	while (i < fractal->iterations)
	{
		z = complex_sum(complex_sqr(z), c);
		if ((((z.real * z.real) + (z.imaginary * z.imaginary)) < fractal->escape_value))
			mlx_put_pixel(fractal->img, x, y, WHITE);
		if (((z.real * z.real) + (z.imaginary * z.imaginary)) > fractal->escape_value)
		{
			//fractal->color = abs(map_color(((z.real * z.real) + (z.imaginary * z.imaginary)),i,fractal->iterations, 0, 0));
			// fractal->color = map_color(calculate_mu(z),fractal->iterations, TOMATO, GOLD);
			fractal->color = map(i,fractal->iterations, TOMATO*0.2, TOMATO*0.7);
			mlx_put_pixel(fractal->img, x, y, fractal->color);
			return;
		}
		i++;
	}
}

void	handle_julia_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	int 		i;

	i = 0;
	z.real = map(x, WIDTH, -2.0, +2.0) * fractal->zoom + fractal->x_shift;
	z.imaginary = map(y, HEIGHT, +2.0 , -2.0) * fractal->zoom + fractal->y_shift;

	while (i < fractal->iterations)
	{
		z = complex_sum(complex_sqr(z), fractal->c);
		// if ((((z.real * z.real) + (z.imaginary * z.imaginary)) < fractal->escape_value))
		// 	mlx_put_pixel(fractal->img, x, y, WHITE);
		if (((z.real * z.real) + (z.imaginary * z.imaginary)) > fractal->escape_value)
		{
		fractal->color = map(i,fractal->iterations, CYAN*0.2, CYAN*0.7);
			mlx_put_pixel(fractal->img, x, y, fractal->color);
			return;
		}
		i++;
	}
}

void mandelbrot_render(t_fractal *fractal)
{
	int y;
	int x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_mandelbrot_pixel(x, y, fractal);
	}
mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
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
























