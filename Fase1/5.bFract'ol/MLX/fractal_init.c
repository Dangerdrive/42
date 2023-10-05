#include "fractol.h"

// void	select_fractal(t_fractal *fractal)
// {
// 	if (fractal->name == MANDELBROT)
// 		fractal->name = JULIA;
// 	else if (fractal->name == JULIA)
// 		fractal->name = BURNINGSHIP;
// 	else
// 		fractal->name = MANDELBROT;
// }

static void	mandelbrot_data_init(t_fractal *fractal)
{
	fractal->name = "Mandelbrot";
	fractal->escape_value = 4.0;
	fractal->iterations = 100.0;
	fractal->x_shift = -0.5;
	fractal->y_shift = 0.0;
	fractal->zoom = 0.79;
}

static void	julia_data_init(t_fractal *fractal)
{
	fractal->name = "Julia";
	fractal->escape_value = 4.0;
	fractal->iterations = 100.0;
	fractal->x_shift = 0.0;
	fractal->y_shift = 0.0;
	fractal->zoom = 1;
}

void	fractal_init(t_fractal *fractal)
{
	if(fractal->id == MANDELBROT)
		mandelbrot_data_init(fractal);
	if(fractal->id == JULIA)
		julia_data_init(fractal);
	puts("press G for guide");
fractal->mlx = mlx_init(WIDTH, HEIGHT, fractal->name, true);
	if(!fractal->mlx)
		exit(EXIT_FAILURE); // (da documentação)
fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if(!fractal->img)
		{
			//mlx_close_window(fractal.mlx);--
			mlx_terminate(fractal->mlx); //um dos dois ou os dois?
			exit(EXIT_FAILURE);// confirmar se esse seria o jeito certo de dar free
		}
//events_init(fractal);
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

























