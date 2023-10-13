/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:41:15 by fde-alen          #+#    #+#             */
/*   Updated: 2023/10/13 18:38:13 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Picks a color for the fractal based on its type.
 *
 * This function assigns a color value to the fractal's 'color' field
 * depending on the fractal's type (e.g., Mandelbrot, Julia, Tricorn, etc.).
 *
 * @param[in,out] fractal A pointer to the fractal structure to be updated 
 * with the selected color.
 */
void	pick_color(t_fractal *fractal)
{
	if (fractal->color == CYAN)
		fractal->color = GOLD;
	else if (fractal->color == GOLD)
		fractal->color = TOMATO;
	else if (fractal->color == TOMATO)
		fractal->color = PINK;
	else if (fractal->color == PINK)
		fractal->color = DEEP;
	else if (fractal->color == DEEP)
		fractal->color = ORANGER;
	else if (fractal->color == ORANGER)
		fractal->color = VIOLET;
	else if (fractal->color == VIOLET)
		fractal->color = TEAL;
	else if (fractal->color == TEAL)
		fractal->color = BROWN;
	else if (fractal->color == BROWN)
		fractal->color = MAGENTA;
	else
		fractal->color = CYAN;
}

/**
 * Splits a 32-bit color value into its red, green, and blue components.
 *
 * This function takes a 32-bit color value as input and extracts its red (R),
 * green (G), and blue (B) components. It then assigns these components to the
 * respective fields in the given fractal structure.
 *
 * @param[in] base_color The 32-bit color value to be split.
 * @param[in,out] fractal A pointer to the fractal structure where color 
 * components will be stored.
 */
void	split_rgb(int32_t base_color, t_fractal *fractal)
{
	fractal->r = base_color >> 24 & 0xFF;
	fractal->g = base_color >> 16 & 0xFF;
	fractal->b = base_color >> 8 & 0xFF;
}

/**
 * Darkens a color by a factor of 10%.
 *
 * This function takes a 32-bit color value as input and darkens it by a factor
 * of 10%. It then returns the new color value.
 *
 * @param[in] base_color The 32-bit color value to be darkened.
 *
 * @return The darkened color value.
 */
unsigned int	darken_color(t_fractal *fractal)
{	
	split_rgb(fractal->color, fractal);
	fractal->r = (int)(fractal->r * 0.100);
	fractal->g = (int)(fractal->g * 0.100);
	fractal->b = (int)(fractal->b * 0.100);
	return ((fractal->r << 24) | (fractal->g << 16) | (fractal->b << 8) | 255);

}

/**
 * Maps an iteration count to a color for smoother gradient-based coloring.
 *
 * This function takes an iteration count, a base color, and a fractal
 * structure to compute a color based on a smoothed interpolation factor.
 * The interpolated color is calculated to create smoother gradient
 * transitions between colors in the fractal rendering.
 *
 * @param[in] iter The current iteration count.
 * @param[in] color The base color used for interpolation.
 * @param[in] fractal A pointer to the fractal structure.
 *
 * @return The interpolated color based on the iteration count.
 */
unsigned int	map_color(int iter, int color, t_fractal *fractal)
{
	double	interpolation_factor;
	double	smoothed_factor;

	split_rgb(color, fractal);
	interpolation_factor = (double)iter / (double)fractal->iterations;
	smoothed_factor = pow(interpolation_factor, 0.9);
	if (interpolation_factor < smoothed_factor * 20)
	{
		fractal->r *= smoothed_factor;
		fractal->g *= smoothed_factor;
		fractal->b *= smoothed_factor;
	}
	else
	{
		fractal->r = (int)((smoothed_factor) * 100);
		fractal->g = (int)((smoothed_factor) * 255);
		fractal->b = (int)((smoothed_factor) * 255);
	}
	return ((fractal->r << 24) | (fractal->g << 16) | (fractal->b << 8) | 255);
}
