//
//#include "fractol.h"
//
//void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//    char	*dest;
//
//    dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//    *(unsigned int*)dest = color;
//}
//
//
//int handle_esc(int keycode, t_data *data)
//{
//    // Check if ESC key is pressed
//    if (keycode == 65307) // 53 is the keycode for ESC key
//    {
//        // Exit the program
//        //mlx_destroy_window(data->mlx, data->mlx_win);
//        printf("ESC key was pressed\n");
//        exit(0);
//    }
//
//    return 0;
//}
//
//int main(void)
//{
//    t_data  data;
//    int x = 50;
//    int y = 50;
//    long long color = 0x00FF0000;
//
//    char    *win_name = "Fract'ol (soon)!";
//    data.mlx = mlx_init();
//    data.mlx_win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, win_name);
//    data.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
//
//    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
//                                 &data.endian);
//    while (x < 400)
//    {
//            while (y < 400)
//            {
//                my_mlx_pixel_put(&data, x, y, color);
//                y++;
//            }
//        x++;
//    }
//    mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
//
//    // Register key press callback function
//    mlx_key_hook(data.mlx_win, handle_esc, &data);
//
//    mlx_loop(data.mlx);
//}
//

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


// Print the window width and height.
// static void ft_hook(void* param)
// {
//     const mlx_t* mlx = param;
//     if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
// 		mlx_close_window(param);
// 	// if (mlx_is_key_down(param, MLX_KEY_UP)) //implement
// 	// 	g_img->instances[0].y -= 5;
// 	// if (mlx_is_key_down(param, MLX_KEY_DOWN))
// 	// 	g_img->instances[0].y += 5;
// 	// if (mlx_is_key_down(param, MLX_KEY_LEFT))
// 	// 	g_img->instances[0].x -= 5;
// 	// if (mlx_is_key_down(param, MLX_KEY_RIGHT))
// 	// 	g_img->instances[0].x += 5;

//     //printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

//
//int32_t	main(void)
//{
//
//    // MLX allows you to define its core behaviour before startup.
//    mlx_set_setting(MLX_MAXIMIZED, false);
//    mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Fract'ol (soon)", true);
//    if (!mlx)
//        ft_error();
//
//    /* Do stuff */
//
//    // Create and display the image.
//    mlx_image_t* img = mlx_new_image(mlx, 256, 256);
//    if (!img || (mlx_image_to_window(mlx, img, 1, 1) < 0))
//        ft_error();
//    mlx_put_string(mlx, "Press ESC to exit.", 10, 10);
//
//    // Even after the image is being displayed, we can still modify the buffer.
//    mlx_put_pixel(img, 0, 0, 0xFF0000FF);
//
//    // Register a hook and pass mlx as an optional param.
//    // NOTE: Do this before calling mlx_loop!
//    mlx_loop_hook(mlx, ft_hook, mlx);
//    mlx_loop(mlx);
//    mlx_terminate(mlx);
//    return (EXIT_SUCCESS);
//}




//adaptar pra MLX codam
//int	main(int argc, char **argv)
//{
//	t_fractal		fractal;
//
//	if (argc == 2)
//	{
//		if (!ft_strncmp(argv[1], "mandelbrot", 10) && ft_strlen(argv[1]) == 10)
//			mandelbrot_param(&fractal, argv[1]);
//		else if (!ft_strncmp(argv[1], "julia", 5) && ft_strlen(argv[1]) == 5)
//			julia_param(&fractal, argv[1]);
//		else if (!ft_strncmp(argv[1], "burning", 7) && ft_strlen(argv[1]) == 7)
//			burning_param(&fractal, argv[1]);
//		fractal.mlx = mlx_init(WIDTH, HEIGHT, fractal.name, true); //adaptado
//		//fractal.win = mlx_new_window(fractal.mlx, fractal.width, //acho que nao precisa de new_window
//		//		fractal.height, fractal.name);
//		fractal.img = mlx_new_image(fractal.mlx, fractal.width, fractal.height); //igual
//		fractalsetup(&fractal);
//		mlx_key_hook(fractal.win, key_hook, &fractal);
//		mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
//		mlx_hook(fractal.win, 17, 1L << 17, close_game, &fractal);
//		mlx_loop(fractal.mlx);
//	}
//	else
//		wronginputs();
//	return (EXIT_SUCCESS);
//}

// static void ft_hook(void* fractal)
// {
// 	const mlx_t* temp = (mlx_t*)fractal->mlx;
// 	if (mlx_is_key_down(fractal.mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(fractal.mlx);
// 	// if (mlx_is_key_down(fractal.mlx, MLX_KEY_UP))
// 	// 	fractal->shift_y -= 0.5;
// 	// if (mlx_is_key_down(fractal.mlx, MLX_KEY_DOWN))
// 	// 	fractal->shift_y += 0.5;
// 	// if (mlx_is_key_down(fractal.mlx, MLX_KEY_LEFT))
// 	// 	fractal->shift_x += 0.5;
// 	// if (mlx_is_key_down(fractal.mlx, MLX_KEY_RIGHT))
// 	// 	fractal->shift_x -= 0.5;

// 	//printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

void	zoom(t_fractal *fractal)
{
	fractal->x_shift = fractal->mouse_x / fractal->zoom;
	fractal->y_shift = fractal->mouse_y / fractal->zoom;
	//fractal_render(fractal);
}

void scrollhook(double xdelta, double ydelta, void* param)
{
	// Simple up or down detection.
	t_fractal* fractal_ptr = (t_fractal*)param;
	if (ydelta > 0)
	{
		fractal_ptr->zoom *=0.9;
		//puts("Up!%f", fractal_ptr->zoom);

	}
	else if (ydelta < 0)
	{
		fractal_ptr->zoom *=1.1;
		//puts("Down!");
	}
	//TODO update_mouse_pos(fractal_ptr);
	//printf("%f\n", fractal_ptr->zoom);
	zoom(fractal_ptr);
	fractal_render(fractal_ptr);
}

static void ft_hook(void* fractal)
{
    t_fractal* fractal_ptr;
	fractal_ptr = (t_fractal*)fractal;
    const mlx_t* temp = fractal_ptr->mlx;
    if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(fractal_ptr->mlx);
    if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_UP))
    	fractal_ptr->y_shift += 0.1;
    if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_DOWN))
    	fractal_ptr->y_shift -= 0.1;
    if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_LEFT))
    	fractal_ptr->x_shift -= 0.1;
    if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_RIGHT))
    	fractal_ptr->x_shift += 0.1;
	if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_G))
    	guide();
	// if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_TAB))
	// 		select_fractal(fractal_ptr);
	// if (mlx_is_key_down(data->mlx, MLX_KEY_R))
	// 		reset_fractal(fractal_ptr);
	fractal_render(fractal_ptr);
}

int	main(int argc, char **argv)
{
	t_fractal		fractal;

	if ((argc == 2 && !strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		// fractal.arg_x = ft_atod(argv[2]);
		// fractal.arg_y = ft_atod(argv[3]);
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_scroll_hook(fractal.mlx, &scrollhook, &fractal);
		//mlx_mouse_hook(fractal.mlx, &mouse_hook, &fractal);
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

//map test
// int	main()
// {
// 	double test;
// 	test = map(1, HEIGHT, -2, 2);
// 	printf("%f", test);
// }

//criar função pra definir a cor

//incluir variavel na função map - criei uma struct pra isso

//trabalhar com a posição do mouse

