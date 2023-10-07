//https://en.wikipedia.org/wiki/List_of_fractals_by_Hausdorff_dimension
// Curve filling the Koch snowflake
// Von Koch in 3D-Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

#include "fractol.h"


// Exit the program as failure.
static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	update_render(t_fractal *fractal)
{
	if(fractal->id == MANDELBROT)
	{
		mandelbrot_render(fractal);
	}
	if(fractal->id == JULIA)
	{
		julia_render(fractal);
	}
}

void	zoom(t_fractal *fractal)
{
//	fractal->x_shift = fractal->mouse_x * fractal->zoom;
//	fractal->y_shift = fractal->mouse_y * fractal->zoom;
}

/**
 * @brief Function to update the mouse position so the zoom can be centered
 *
 * @param data The data struct
 */
static void	update_mouse_pos(t_fractal *fractal)
{
	int32_t	x;
	int32_t	y;

	mlx_get_mouse_pos(fractal->mlx, &x, &y);

	if (x >= 0 && x <= fractal->width)
		fractal->mouse_x = x;
	if (y >= 0 && y <= fractal->height)
		fractal->mouse_y = y;

	// if (x < 0)
	// 	fractal->mouse_x = 0;
	// else if (x > fractal->width)
	// 	fractal->mouse_x = fractal->width;
	// else
	// 	fractal->mouse_x = x;
	// if (y > 0)
	// 	fractal->mouse_y = 0;
	// else if (y < fractal->height)
	// 	fractal->mouse_y = fractal->height;
	// else
	// 	fractal->mouse_y = y;

	// fractal->mouse_x = x;
	// fractal->mouse_y = y;

	// printf("mouse_x = %d\n", fractal->mouse_x);
	//printf("mouse_y = %d\n", fractal->mouse_y);

}

void cursorhook(double xmouse, double ymouse, void* param)
{
	t_fractal* fractal_ptr = (t_fractal*)param;
	int32_t	x;
	int32_t	y;

	mlx_get_mouse_pos(fractal_ptr->mlx, &x, &y);
	fractal_ptr->mouse_x = x;
	fractal_ptr->mouse_y = y;
	if (fractal_ptr->id == JULIA 
		&& mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_LEFT_CONTROL))
	{
		fractal_ptr->c.real = map(x, WIDTH, -0.8, +0.4);
		//printf("c.real = %f\n", fractal_ptr->c.real);
		fractal_ptr->c.imaginary = map(y, HEIGHT, +0.7 , -0.7); //0.7
		//printf("c.imaginary = %f\n", fractal_ptr->c.imaginary);
		update_render(fractal_ptr);
	}
}


void scrollhook(double xdelta, double ydelta, void* param)
{
	t_fractal* fractal_ptr = (t_fractal*)param;
	
	if (fractal_ptr->id == JULIA 
		&& mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_LEFT_SHIFT))
	{
		fractal_ptr->c.real += (ydelta / 1000) * fractal_ptr->zoom;
		fractal_ptr->c.imaginary += (ydelta / 1000) * fractal_ptr->zoom;
	}
	else if (ydelta > 0)
	{
		//fractal_ptr->shift *=0.9;
		fractal_ptr->zoom *=0.9;
		//fractal_ptr->x_shift /= map(fractal_ptr->mouse_x, fractal_ptr->width, -2, +2) * fractal_ptr->zoom;
		printf("x_shift = %f\n", fractal_ptr->x_shift);
		//fractal_ptr->y_shift /= map(fractal_ptr->mouse_x, fractal_ptr->width, +2, -2)* fractal_ptr->zoom;
		
	}
	else if (ydelta < 0)
	{
		fractal_ptr->zoom *=1.1;
		fractal_ptr->x_shift *= map(fractal_ptr->mouse_x, fractal_ptr->width, -2, +2) * fractal_ptr->zoom;
		fractal_ptr->y_shift *= map(fractal_ptr->mouse_x, fractal_ptr->width, +2, -2)* fractal_ptr->zoom;
	}
	// update_mouse_pos(fractal_ptr);
	//zoom(fractal_ptr);
	update_render(fractal_ptr);
}

static void ft_hook(void* fractal)
{
    t_fractal* fractal_ptr;
	fractal_ptr = (t_fractal*)fractal;
    const mlx_t* temp = fractal_ptr->mlx;
    if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(fractal_ptr->mlx);
    if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_UP))
    	fractal_ptr->y_shift += 0.1 * fractal_ptr->zoom;
    if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_DOWN))
    	fractal_ptr->y_shift -= 0.1 * fractal_ptr->zoom;
    if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_LEFT))
    	fractal_ptr->x_shift -= 0.1 * fractal_ptr->zoom;
    if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_RIGHT))
    	fractal_ptr->x_shift += 0.1 * fractal_ptr->zoom;
	if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_G))
    	guide();
	if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_TAB))
			select_fractal(fractal_ptr);
	// if (mlx_is_key_down(data->mlx, MLX_KEY_R))
	// 		reset_fractal(fractal_ptr);
	update_render(fractal_ptr);
}

// /**
//  * @brief Parses the arguments and sets the fractal
//  *
//  * @param ac The argument count
//  * @param av The argument list
//  * @param data The data struct
//  */
// static void	parse_argv(int ac, char **av, t_data *data)
// {
// 	if (ac == 1)
// 		throw_err("Usage -> ./fractol [fractal] [r] [i]", data);
// 	if (ft_strcmp(av[1], "mandelbrot") == 0 && ac == 2)
// 		data->frctl = MANDELBROT;
// 	else if (ft_strcmp(av[1], "julia") == 0 && ac == 4)
// 	{
// 		data->frctl = JULIA;
// 		if (valid(av[2]) || valid(av[3]))
// 			throw_err("Please provide valid numbers", data);
// 		data->complex.r = ft_atod(av[2]);
// 		data->complex.i = ft_atod(av[3]);
// 		if (data->complex.r < -2.0 || data->complex.r > 2.0
// 			|| data->complex.i > 2.0 || data->complex.i < -2.0)
// 			throw_err("Please provide numbers between -2 & 2", data);
// 	}
// 	else
// 		throw_err("Usage -> ./fractol [fractal] [r] [i]", data);
// 	construct(data);
// 	init_color_palette(data);
// }



int	main(int argc, char **argv)
{
	t_fractal		fractal;

	if ((argc == 2 && !strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !strncmp(argv[1], "julia", 5))
		)
	{
		if(argc == 2 && !strncmp(argv[1], "mandelbrot", 10))
			fractal_init(&fractal, MANDELBROT, 0, 0);
		if(argc == 4 && !strncmp(argv[1], "julia", 5))
			fractal_init(&fractal, JULIA, ft_atod(argv[2]), ft_atod(argv[3]));
		update_render(&fractal);
		mlx_scroll_hook(fractal.mlx, &scrollhook, &fractal);
		mlx_cursor_hook(fractal.mlx, &cursorhook, &fractal);
		mlx_loop_hook(fractal.mlx, ft_hook, &fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		puts(PARAM_MSG);
		return (EXIT_FAILURE);
	}
	mlx_delete_image(fractal.mlx, fractal.img);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}



//criar função pra definir a cor

//incluir variavel na função map - criei uma struct pra isso

//trabalhar com a posição do mouse
	//onde pega mouse position?
	//mlx_mouse_hook(fractal.mlx, &mouse_hook, &fractal);

