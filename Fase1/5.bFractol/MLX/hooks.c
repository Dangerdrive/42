/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:45:18 by fde-alen          #+#    #+#             */
/*   Updated: 2023/10/10 15:32:09 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Handles keyboard input events.
 *
 * This function processes keyboard input events and updates the state
 * of the fractal 'fractal' based on the pressed keys. It supports
 * actions such as zooming, panning, color selection, and fractal type switching.
 *
 * @param[in] fractal A pointer to the fractal structure to be updated.
 */
void	keyhook(void *fractal)
{
	t_fractal	*fractal_ptr;

	fractal_ptr = (t_fractal *)fractal;
	if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal_ptr->mlx);
	if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_UP))
		if (fractal_ptr->y_shift <= 2.5)
			fractal_ptr->y_shift += 0.1 * fractal_ptr->zoom;
	if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_DOWN))
		if (fractal_ptr->y_shift >= -2.5)
			fractal_ptr->y_shift -= 0.1 * fractal_ptr->zoom;
	if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_LEFT))
		if (fractal_ptr->x_shift >= -2.5)
			fractal_ptr->x_shift -= 0.1 * fractal_ptr->zoom;
	if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_RIGHT))
		if (fractal_ptr->x_shift <= 2.5)
			fractal_ptr->x_shift += 0.1 * fractal_ptr->zoom;
	// if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_G))
	// 	guide();
	if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_C))
		pick_color(fractal_ptr);
	if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_R))
		randomize_julia(fractal_ptr);
	if (mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_TAB))
		select_fractal(fractal_ptr);
	update_render(fractal_ptr);
}

/**
 * Handles scroll wheel input events.
 *
 * This function processes scroll wheel input events and updates the state
 * of the fractal 'fractal' based on the scroll direction and modifiers.
 * It supports zooming and panning functionalities.
 *
 * @param[in] xdelta The horizontal scroll delta.
 * @param[in] ydelta The vertical scroll delta.
 * @param[in] param A pointer to the fractal structure to be updated.
 */
void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal_ptr;

	fractal_ptr = (t_fractal *)param;
	if (fractal_ptr->id == JULIA
		&& mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_LEFT_SHIFT))
	{
		fractal_ptr->c.real += (ydelta / 1000) * fractal_ptr->zoom;
		fractal_ptr->c.i += (ydelta / 1000) * fractal_ptr->zoom;
	}
	else if (ydelta > 0)
	{
		//fractal_ptr->shift *=0.9;
		fractal_ptr->zoom *= 0.9;
		//fractal_ptr->x_shift /= map(fractal_ptr->mouse_x, fractal_ptr->width, -2, +2) * fractal_ptr->zoom;
		//printf("x_shift = %f\n", fractal_ptr->x_shift);
		//fractal_ptr->y_shift /= map(fractal_ptr->mouse_x, fractal_ptr->width, +2, -2)* fractal_ptr->zoom;
	}
	else if (ydelta < 0)
	{
		fractal_ptr->zoom *= 1.1;
		fractal_ptr->x_shift *= map(fractal_ptr->mouse_x, fractal_ptr->width,
			-2, +2) * fractal_ptr->zoom;
		fractal_ptr->y_shift *= map(fractal_ptr->mouse_x, fractal_ptr->height,
			+2, -2)* fractal_ptr->zoom;
	}
	//update_mouse_pos(fractal_ptr);
	//zoom(fractal_ptr);
	update_render(fractal_ptr);
}

/**
 * Handles cursor (mouse) position events.
 *
 * This function processes cursor (mouse) position events and updates the state
 * of the fractal 'fractal_ptr' based on the cursor's position and modifiers.
 * It supports actions such as adjusting the Julia set parameter 'c'.
 *
 * @param[in] xmouse The x-coordinate of the cursor.
 * @param[in] ymouse The y-coordinate of the cursor.
 * @param[in] param A pointer to the fractal structure to be updated.
 */
void	cursorhook(double xmouse, double ymouse, void *param)
{
	t_fractal	*fractal_ptr;

	fractal_ptr = (t_fractal *)param;
	mlx_get_mouse_pos(fractal_ptr->mlx, &fractal_ptr->mouse_x,
		&fractal_ptr->mouse_y);
	if (fractal_ptr->id == JULIA
		&& mlx_is_key_down(fractal_ptr->mlx, MLX_KEY_LEFT_CONTROL))
	{
		fractal_ptr->c.real = map(fractal_ptr->mouse_x, WIDTH, -0.8, +0.4);
		//printf("c.real = %f\n", fractal_ptr->c.real);
		fractal_ptr->c.i = map(fractal_ptr->mouse_y, HEIGHT, +0.7, -0.7);
		//printf("c.i = %f\n", fractal_ptr->c.i);
		update_render(fractal_ptr);
	}
}
