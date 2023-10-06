#include "fractol.h"

void	select_fractal(t_fractal *fractal)
{
	if (fractal->id == MANDELBROT)
	{
		fractal->id = JULIA;
		fractal->c.real = (drand48()*4) - 2;
		fractal->c.imaginary = (drand48()*4) - 2;
		puts("\nJulia set selected - random c values applied\n");
	printf("c = %f + %fi\n", fractal->c.real, fractal->c.imaginary);
	}
	// else if (fractal->id == JULIA)
	// 	fractal->id = BURNINGSHIP;
	else
		fractal->id = MANDELBROT;
}

static void	mandelbrot_data_init(t_fractal *fractal)
{
	fractal->name = "Mandelbrot";
	fractal->id = MANDELBROT;
	fractal->escape_value = 4.0;
	fractal->iterations = 100.0;
	fractal->x_shift = -0.5;
	fractal->y_shift = 0.0;
	fractal->zoom = 0.79;
}

static void	julia_data_init(t_fractal *fractal,double c_x, double c_y)
{
	// if ((c_x < -2.0 || c_x > 2.0) || (c_y < -2.0 || c_y > 2.0))
	// {
	// 	puts("c values must be between -2 and 2");
	// return;
	// }
	
		
	
	fractal->name = "Julia";
	fractal->id = JULIA;
	fractal->escape_value = 4.0;
	fractal->iterations = 100.0;
	fractal->x_shift = 0.0;
	fractal->y_shift = 0.0;
	fractal->zoom = 1;
	fractal->c.real = c_x;
	fractal->c.imaginary = c_y;	
}

void	fractal_init(t_fractal *fractal, int id, double c_x, double c_y)
{
	if(id == MANDELBROT)
		mandelbrot_data_init(fractal);
	if(id == JULIA)
		julia_data_init(fractal, c_x, c_y);
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

























