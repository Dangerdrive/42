#include "fractol.h"

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int		color;
	int 		i;

	i = 0;
	z.real = 0.0;
	z.imaginary = 0.0;

	c.real = map(x, WIDTH, -2, +2) + fractal->x_shift;
	printf("x_shift %f\n", c.real);
	c.imaginary = map(y, HEIGHT, +2, -2) + fractal->y_shift;

	while (i < fractal->iterations)
	{
		z = complex_sum(complex_sqr(z), c);
		//if ((((z.real * z.real) + (z.imaginary * z.imaginary)) < fractal->escape_value))
		//	mlx_put_pixel(fractal->img, x, y, 0x11FF00);
		if (((z.real * z.real) + (z.imaginary * z.imaginary)) > fractal->escape_value)
		{
			//printf("real2 %f, im2 %f\n", z.real * z.real, z.imaginary * z.imaginary);
			//color = map(i,fractal->iterations, SILVER, SILVER);
			//printf("%d", color);
			mlx_put_pixel(fractal->img, x, y, rand() % RAND_MAX);
			//printf("color %f\n", z.color);

			return;
		}
		i++;
	}
}

void fractal_render(t_fractal *fractal)
{
	int y;
	int x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(x, y, fractal);
			//printf("x: %d, y: %d\n", x, y);
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

























