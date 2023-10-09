/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:20:58 by fde-alen          #+#    #+#             */
/*   Updated: 2023/09/28 23:22:45 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#ifndef FRACTOL_H
//# define FRACTOL_H
//# define WIN_WIDTH 720
//# define WIN_HEIGHT 720
//# define ESC_KEY 0xFF1B
//
//typedef struct s_data {
//    void *mlx;
//    void *mlx_win;
//    void	*img;
//    char	*addr;
//    int		bits_per_pixel;
//    int		line_length;
//    int		endian;
//} t_data;
//
//# include <fcntl.h>    // for open
//# include <unistd.h>   // for close, read, write
//# include <stdlib.h>   // for malloc, free, exit
//# include <stdio.h>    // for perror
//# include <string.h>   // for strerror
//# include <math.h>
//# include <MLX42/MLX42.h>
////# include "minilibx-linux/mlx.h"
////# include "minilibx-linux/mlx_int.h"
////# include "libft/libft.h"
//
////int					ft_atoi(const char *nptr);
//
//
//#endif

//void	*mlx_init ();

// -lm -lmlx -lXext -lX11 -L minilibx-linux/

//link with -lmlx -lXext -lX11 -L path/to/libs/
// gcc myfile.c -o myfile -lm // -lm is for math.h
// -lmlx -lXext -lX11 -L
// https://github.com/codam-coding-college/MLX42
// AMD ROCm (Radeon Open Compute) is an open-source software foundation for GPU computing on Linux.
//Install it to try running fractol on GPU
// CUDA is a parallel computing platform and application programming interface model created by Nvidia.
// OpenCL (Open Computing Language) is a framework for writing programs that execute across heterogeneous platforms consisting of central processing units (CPUs), graphics processing units (GPUs), digital signal processors (DSPs), field-programmable gate arrays (FPGAs) and other processors or hardware accelerators. OpenCL specifies programming languages (based on C99 and C++11) for programming these devices and application programming interfaces (APIs) to control the platform and execute programs on the compute devices. OpenCL provides a standard interface for parallel computing using task- and data-based parallelism.
// Overall, OpenCL serves as an open and standard framework for parallel computing across different GPU architectures, similar to how CUDA is specific to NVIDIA GPUs.
// https://github.com/paulo-santana/fractol-gpu
//https://developer.mozilla.org/en-US/docs/Web/API/UI_Events/Keyboard_event_key_values
// https://github.com/librity/ft_fractol


//gcc *.c MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm


//------------------------------------------------------------------------------------
#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 720
# define HEIGHT 720
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define MAGENTA 0xFF00FFFF   // Magenta
# define CYAN 0x00FFFFFF   // Cyan
# define YELLOW 0xFFFF00FF   // Yellow
# define ORANGE 0xFFA500FF   // Orange
# define PURPLE 0x800080FF   // Purple
# define PINK 0xFFC0CBFF   // Pink
# define LIME 0x32CD32FF   // Lime Green
# define DEEP 0xFF1493FF   // Deep Pink
# define GREEN 0x00FF00FF   // Green
# define VIOLET 0x8A2BE2FF   // Blue Violet
# define ORANGER 0xFF4500FF   // Orange Red
# define TOMATO 0xFF6347FF   // Tomato
# define AQUA        0x00FFFFFF
# define TEAL        0x008080FF
# define GOLD        0xFFD700FF
# define SILVER      0xC0C0C0FF
# define GRAY        0x808080FF
# define BROWN       0xA52A2AFF
# define PARAM_MSG "Error - incorrect params\n" //include options

# include <fcntl.h>    // for open
# include <unistd.h>   // for close, read, write
# include <stdlib.h>   // for malloc, free, exit
# include <stdio.h>    // for perror
# include <string.h>   // for strerror
# include <math.h>
# include "MLX42/MLX42.h"
//# include "libft/libft.h" //for ft_putstr_fd, ft_strcmp

typedef enum sets
{
	MANDELBROT,
	JULIA,
	VELA,
	MOUSE
}	t_sets;

/**
 * @struct t_complex
 * @brief A complex number.
 *
 * This struct represents a complex number. It has two members:
 *
 *   @param real: The real part of the number and X axis of the complex plane.
 *   @param imaginary: The imaginary part of the number and Y axis of the complex plane.
 */
typedef struct s_complex
{
    double		real;
    double		imaginary;
}	t_complex;

// typedef struct s_data {
//     void    *mlx;
//     void    *mlx_win;
//     void	*img;
//     char	*addr;
//     int		bits_per_pixel;
//     int		line_length;
//     int		endian;
// } t_data;
typedef struct s_map
{
	double		old_min;
	double		old_max;
	double		new_min;
	double		new_max;
}	t_map;

typedef struct s_fractal
{
	char		*name;
	int			id;
	mlx_image_t* img;
	void		*mlx;
	int			width;
	int			height;
	t_complex	c;
	double		escape_value;
	double		zoom;
	double		x;
	double		y;
	double		x_shift;
	double		y_shift;
	int		mouse_x;
	int		mouse_y;
	double		arg_x;
	double		arg_y;
	double		radius;
	int			iterations;
	int			color;
}				t_fractal;





int		ft_strncmp(const char *str1, const char *str2, size_t n);

/**
 * Lets you set a custom image as the program icon.
 *
 * @param[t_] fractal The image to use as icon.
 *
 */
void 		fractal_init(t_fractal *fractal);

/**
 * Lets you set a custom image as the program icon.
 *
 * @param[in] x The MLX instance handle.
 * @param[in] y The MLX instance handle.
 * @param[t_] fractal The image to use as icon.
 *
 */
void fractal_render(t_fractal *fractal);

/**
 * Maps a value from one range to another using linear interpolation.
 *
 * This function takes an unscaled number and maps it from an old range
 * defined by old_max and old_min to a new range defined by new_max and new_min.
 * The result is the scaled number within the new range.
 *
 * @param[in] unscaled_num The value to be mapped from the old range to the new range.
 * @param[in] new_max The maximum value of the new range.
 * @param[in] new_min The minimum value of the new range.
 *
 * @return The scaled number within the new range.
 */
double	map(double unscaled_num, double old_max, double new_min, double new_max);

//double	map_color(double unscaled_num, double old_max, double new_min, double new_max);
//int	map_color(int i, int max_iterations, int start_color, int end_color);
double map_color(double pei, int iteration, int max_iteration, int color1, int color2);


/**
 * Adds two complex numbers together.
 *
 * This function takes two complex numbers 'a' and 'b' and computes their sum,
 * resulting in a new complex number 'sum'.
 *
 * @param[in] a The first complex number to be added.
 * @param[in] b The second complex number to be added.
 *
 * @return The sum of the two complex numbers 'a' and 'b'.
 */
t_complex complex_sum(t_complex a, t_complex b);

/**
 * Computes the square of a complex number.
 *
 * This function takes a complex number 'a' and computes its square,
 * resulting in a new complex number 'squared'.
 *
 * @param[in] a The complex number to be squared.
 *
 * @return The square of the complex number 'a'.
 */
t_complex complex_sqr(t_complex a);

void	guide(void);
void	select_fractal(t_fractal *fractal);
double	ft_atod(char *str);


#endif

//git@github.com:Xyckens/fract-ol.git
//gcc *.c MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
//valgrind --leak-check=full -s ./a.out mandelbrot
