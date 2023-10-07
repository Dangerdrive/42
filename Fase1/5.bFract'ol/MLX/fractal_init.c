#include "fractol.h"

void	select_fractal(t_fractal *fractal)
{
	if (fractal->id == MANDELBROT)
	{
		fractal->id = JULIA;
		fractal->c.real = (drand48() * 1.2) - 0.8;
		fractal->c.i = fractal->c.i = (drand48() * 1.4) - 0.7;
		puts("\nJulia set selected - random c values applied\n");
	printf("c = %f + %fi\n", fractal->c.real, fractal->c.i);
	}
	// else if (fractal->id == JULIA)
	// 	fractal->id = BURNINGSHIP;
	else
		fractal->id = MANDELBROT;
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
		exit(EXIT_FAILURE);
fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if(!fractal->img)
		{
			mlx_terminate(fractal->mlx); 
			exit(EXIT_FAILURE);
		}
//events_init(fractal);
}