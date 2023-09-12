#include "fractol.h"

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	double		color;
	int 		i;

	i = 0;
	z.real = 0.0;
	z.imaginary = 0.0;

	c.real = map(x, -2, +2, WIDTH);
	c.imaginary = map(y, +2, -2, HEIGHT);

	z = complex_sum(complex_sqr(z), c);
	while (i < fractal->iterations)
	{
		if (((z.real * z.real) + (z.imaginary * z.imaginary)) < fractal->escape_value)
		{
			color = map (i, TOMATO, SILVER, fractal->iterations);
			mlx_put_pixel(fractal->img, x, y, SILVER);
			return;
		}
		i++;
	}
	mlx_put_pixel(fractal->img, x, y, ORANGER);
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

























