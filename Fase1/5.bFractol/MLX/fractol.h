/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:20:58 by fde-alen          #+#    #+#             */
/*   Updated: 2023/10/17 21:47:27 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//---------------------------------------------------------------------------
#ifndef FRACTOL_H
# define FRACTOL_H
# define ESCAPE_COUNT 100
# define WIDTH 720
# define HEIGHT 720
# define BLACK	0x000000FF
# define WHITE	0xFFFFFFFF
# define MAGENTA	0xFF00FFFF
# define CYAN	0x00FFFFFF
# define YELLOW	0xFFFF00FF
# define ORANGE	0xFFA500FF
# define PURPLE	0x800080FF
# define PINK	0xFFC0CBFF
# define LIME	0x32CD32FF
# define DEEP	0xFF1493FF
# define GREEN	0x00FF00FF
# define VIOLET	0x8A2BE2FF
# define ORANGER	0xFF4500FF
# define TOMATO	0xFF6347FF
# define AQUA	0x00FFFFFF
# define TEAL	0x008080FF
# define GOLD	0xFFD700FF
# define SILVER	0xC0C0C0FF
# define GRAY	0x808080FF
# define BROWN 	0xA52A2AFF


# include <fcntl.h>    // for open
# include <unistd.h>   // for close, read, write
# include <stdlib.h>   // for malloc, free, exit
# include <stdio.h>    // for perror
# include <string.h>   // for strerror
# include <math.h>
# include "MLX42/MLX42.h"

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
	BURNING
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
	char			*name;
	int				id;
	mlx_image_t		*img;
	void			*mlx;
	int				width;
	int				height;
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	double			xzoom;
	double			yzoom;
	double			zoom_factor;
	t_complex		c;
	double			escape_value;
	double			zoom;
	double			x_shift;
	double			y_shift;
	int				mouse_x;
	int				mouse_y;
	unsigned int	iterations;
	unsigned int	color;
	unsigned int	color2;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}				t_fractal;

//-------Colors
unsigned int	map_color(int iter, int color, t_fractal *fractal);
void			pick_color(t_fractal *fractal);
unsigned int	darken_color(t_fractal *fractal);

void			fractal_init(t_fractal *fractal, int id, double c_x,
					double c_y);
void			select_fractal(t_fractal *fractal);
void			update_render(t_fractal *fractal);
//-------Julia Set
void			julia_data_init(t_fractal *fractal, double c_x, double c_y);
void			randomize_julia(t_fractal *fractal_ptr);
void			julia_render(t_fractal *fractal);
//-------Mandelbrot
void			mandelbrot_data_init(t_fractal *fractal);
void			mandelbrot_render(t_fractal *fractal);
//-------Tricorn
void			tricorn_render(t_fractal *fractal);
void			tricorn_data_init(t_fractal *fractal);
//-------Hooks
void			keyhook(void	*fractal);
void			scrollhook(double xdelta, double ydelta, void	*param);
void			cursorhook(double xmouse, double ymouse, void	*param);
//-------Math
double			map(double unscaled_num, double old_max, double new_min,
					double new_max);
t_complex		complex_sum(t_complex a, t_complex b);
t_complex		complex_sqr(t_complex a);
t_complex		complex_power(t_complex a, int n);
t_complex		complex_conjugate(t_complex a);
//-------Messages
void			error(void);
void			param_error(void);
void			guide(void);
//-------String Utils
int				ft_strncmp(const char *str1, const char *str2, size_t n);
double			ft_atod(char *str);

#endif
