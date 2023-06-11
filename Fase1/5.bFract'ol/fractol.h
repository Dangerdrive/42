/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:20:58 by fde-alen          #+#    #+#             */
/*   Updated: 2023/06/10 19:07:57 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WIDTH 720
# define WIN_HEIGHT 480

typedef struct s_data {
    void *mlx;
    void *mlx_win;
} t_data;

# include <fcntl.h>    // for open
# include <unistd.h>   // for close, read, write
# include <stdlib.h>   // for malloc, free, exit
# include <stdio.h>    // for perror
# include <string.h>   // for strerror
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
//# include "libft/libft.h"

//int					ft_atoi(const char *nptr);


#endif

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