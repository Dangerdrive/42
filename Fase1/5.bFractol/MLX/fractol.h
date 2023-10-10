/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:20:58 by fde-alen          #+#    #+#             */
/*   Updated: 2023/10/10 15:55:32 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//---------------------------------------------------------------------------
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
# define PARAM_MSG "Error - incorrect params\n\n" \
"params:\t \033[1m\033[38;5;110mmandelbrot\n" \
"\t julia \033[0m\033[38;5;115m<real> <imaginary>\033[0m\n\n" \
"examples:\n" \
"./fractol julia \033[38;5;115m-0.8 0.156\033[0m\n" \
"./fractol julia \033[38;5;115m-0.8 0.156\n" \

# include <fcntl.h>    // for open
# include <unistd.h>   // for close, read, write
# include <stdlib.h>   // for malloc, free, exit
# include <stdio.h>    // for perror
# include <string.h>   // for strerror
# include <math.h>
# include "MLX42/MLX42.h"
//# include "libft/libft.h" //for ft_putstr_fd, ft_strcmp

/**
 * @enum t_sets
 * @brief Represents different types of fractal sets.
 *
 * This enumeration defines symbolic constants representing various types
 * of fractal sets, including Mandelbrot, Julia, Tricorn, Vela, and Nova.
 * These constants are used to identify and specify the type of fractal
 * being rendered or manipulated in the code.
 */
typedef enum sets
{
	MANDELBROT,
	JULIA,
	TRICORN,
	VELA,
	NOVA
}	t_sets;

/**
 * @struct t_complex
 * @brief A complex number.
 *
 * This struct represents a complex number. It has two members:
 *
 *  @param real: The real part of the number and X axis of the complex plane.
 *  @param imaginary: The imaginary part of the number and 
 * 	Y axis of the complex plane.
 */
typedef struct s_complex
{
	double		real;
	double		i;
}	t_complex;

/**
 * @struct t_fractal
 * @brief Represents a fractal rendering configuration.
 *
 * This structure stores information related to fractal rendering and
 * configuration settings. It is used to control the rendering of different
 * types of fractals and manage their properties.
 */
typedef struct s_fractal
{
	char		*name;
	int			id;
	mlx_image_t	*img;
	void		*mlx;
	int			width;
	int			height;
	t_complex	c;
	double		escape_value;
	double		zoom;
	//double		x;
	//double		y;
	double		x_shift;
	double		y_shift;
	int			mouse_x;
	int			mouse_y;
	//double		radius;
	int			iterations;
	int			color;
	int			r;
	int			g;
	int			b;
}				t_fractal;



int			ft_strncmp(const char *str1, const char *str2, size_t n);

/**
 * Lets you set a custom image as the program icon.
 *
 * @param[t_] fractal The image to use as icon.
 *
 */
void		fractal_init(t_fractal *fractal, int id, double c_x, double c_y);

/**
 * Lets you set a custom image as the program icon.
 *
 * @param[in] x The MLX instance handle.
 * @param[in] y The MLX instance handle.
 * @param[t_] fractal The image to use as icon.
 *
 */

void		mandelbrot_render(t_fractal *fractal);
void		julia_render(t_fractal *fractal);


double		map(double unscaled_num, double old_max, double new_min, double new_max);

//double	map_color(double unscaled_num, double old_max, double new_min, double new_max);
//int	map_color(int i, int max_iterations, int start_color, int end_color);
//double map_color(double pei, int iteration, int max_iteration, int color1, int color2);


t_complex	complex_sum(t_complex a, t_complex b);
t_complex	complex_sqr(t_complex a);

void		guide(void);
void		select_fractal(t_fractal *fractal);
double		ft_atod(char *str);
void		randomize_julia(t_fractal *fractal_ptr);
void		mandelbrot_data_init(t_fractal *fractal);
void		randomize_julia(t_fractal *fractal_ptr);
void		keyhook(void	*fractal);
void		scrollhook(double xdelta, double ydelta, void	*param);
void		cursorhook(double xmouse, double ymouse, void	*param);
void		julia_data_init(t_fractal *fractal, double c_x, double c_y);
void		update_render(t_fractal *fractal);
int			map_color(int iter, int color, t_fractal *fractal);
t_complex	complex_power(t_complex a, int n);
void		tricorn_render(t_fractal *fractal);
t_complex	complex_conjugate(t_complex a);
void		vela_render(t_fractal *fractal);
void		nova_render(t_fractal *fractal);
void		tricorn_data_init(t_fractal *fractal);

void		vela_data_init(t_fractal *fractal);

void		nova_data_init(t_fractal *fractal);

void		mandelbrot_data_init(t_fractal *fractal);
void		pick_color(t_fractal *fractal);


#endif

//git@github.com:Xyckens/fract-ol.git
//gcc *.c MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
//valgrind --leak-check=full -s ./a.out mandelbrot

// gcc *.c MLX42/build/libmlx42.a -Iinclude -O3 -ldl -lglfw -pthread -lm && ./a.out julia 0.285 0.01
// gcc *.c MLX42/build/libmlx42.a -Iinclude -O3 -ldl -lglfw -pthread -lm && ./a.out julia -0.8 0.156
