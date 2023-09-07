/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:20:58 by fde-alen          #+#    #+#             */
/*   Updated: 2023/09/07 18:44:27 by fde-alen         ###   ########.fr       */
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
# define ERROR_MSG "Error - incorrect params\n" //include options

# include <fcntl.h>    // for open
# include <unistd.h>   // for close, read, write
# include <stdlib.h>   // for malloc, free, exit
# include <stdio.h>    // for perror
# include <string.h>   // for strerror
# include <math.h>
# include "MLX42/MLX42.h"
//# include "libft/libft.h" //for ft_putstr_fd, ft_strcmp

typedef struct s_mlx
{
    void*		window;
    void*		context;
    int32_t		width;
    int32_t		height;
    double		delta_time;
}	t_mlx;

typedef struct s_complex
{
    double		real;
    double		imaginary;
}	t_complex;

typedef struct s_data {
    void    *mlx;
    void    *mlx_win;
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
} t_data;

typedef struct s_fractal {
	char		*name;
	//void		*img;
    mlx_image_t* img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_complex	c;
	double		zoom;
	double		x;
	double		y;
	double		xarrow;
	double		yarrow;
	double		radius;
	int			iterations;
	int			color;
}				t_fractal;

//int					ft_atoi(const char *nptr);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_sqr(t_complex a);



int	        strcmp(const char *str1, const char *str2);
void	    ft_putstr_fd(char *str, int fd);

#endif

//git@github.com:Xyckens/fract-ol.git
//gcc *.c MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm