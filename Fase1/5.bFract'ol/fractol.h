/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:20:58 by fde-alen          #+#    #+#             */
/*   Updated: 2023/06/09 19:20:26 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

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