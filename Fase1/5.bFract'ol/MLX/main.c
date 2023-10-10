/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:49:57 by fde-alen          #+#    #+#             */
/*   Updated: 2023/10/09 21:54:08 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if(fractal->id == TRICORN)
	{
		tricorn_render(fractal);
	}
		if(fractal->id == VELA)
	{
		vela_render(fractal);
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



// int	main(int argc, char **argv)
// {
// 	t_fractal		fractal;

// 	if ((argc == 2 && !strncmp(argv[1], "mandelbrot", 10))
// 		|| (argc == 4 && !strncmp(argv[1], "julia", 5))
// 		&& ft_atod(argv[2])>= -2.0 && ft_atod(argv[2])<= 2.0
// 		&& ft_atod(argv[3])>= -2.0 && ft_atod(argv[3])<= 2.0)
// 	{
// 		if(argc == 2 && !strncmp(argv[1], "mandelbrot", 10))
// 			fractal_init(&fractal, MANDELBROT, 0, 0);
// 		if(argc == 4 && !strncmp(argv[1], "julia", 5))
// 			fractal_init(&fractal, JULIA, ft_atod(argv[2]), ft_atod(argv[3]));
// 		update_render(&fractal);
// 		mlx_scroll_hook(fractal.mlx, &scrollhook, &fractal);
// 		mlx_cursor_hook(fractal.mlx, &cursorhook, &fractal);
// 		mlx_loop_hook(fractal.mlx, keyhook, &fractal);
// 		mlx_loop(fractal.mlx);
// 	}
// 	else
// 	{
// 		puts(PARAM_MSG);
// 		return (EXIT_FAILURE);
// 	}
// 	mlx_delete_image(fractal.mlx, fractal.img);
// 	mlx_terminate(fractal.mlx);
// 	return (EXIT_SUCCESS);
// }

bool	check_input(int argc, char **argv, t_fractal fractal)
{
	if (argc == 2 && !strncmp(argv[1], "mandelbrot", 10))
		fractal_init(&fractal, MANDELBROT, 0, 0);
	else if (argc == 4 && !strncmp(argv[1], "julia", 5))
		fractal_init(&fractal, JULIA, ft_atod(argv[2]), ft_atod(argv[3]));
	else if (argc == 2 && !strncmp(argv[1], "tricorn", 7))
		fractal_init(&fractal, TRICORN, 0, 0);
	else if (argc == 2 && !strncmp(argv[1], "vela", 4))
		fractal_init(&fractal, VELA, 0, 0);
	else	
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_fractal		fractal;

if(check_input(argc, argv, fractal))
	if ((argc == 2 && !strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !strncmp(argv[1], "julia", 5))
		&& ft_atod(argv[2])>= -2.0 && ft_atod(argv[2])<= 2.0
		&& ft_atod(argv[3])>= -2.0 && ft_atod(argv[3])<= 2.0)
	{
		if(argc == 2 && !strncmp(argv[1], "mandelbrot", 10))
			fractal_init(&fractal, MANDELBROT, 0, 0);
		if(argc == 4 && !strncmp(argv[1], "julia", 5))
			fractal_init(&fractal, JULIA, ft_atod(argv[2]), ft_atod(argv[3]));
		update_render(&fractal);
		mlx_scroll_hook(fractal.mlx, &scrollhook, &fractal);
		mlx_cursor_hook(fractal.mlx, &cursorhook, &fractal);
		mlx_loop_hook(fractal.mlx, keyhook, &fractal);
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