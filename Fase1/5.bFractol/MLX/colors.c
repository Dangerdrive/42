#include "fractol.h"

#define ESCAPE_COUNT 100

// double	map_color(double unscaled_num, double old_max, double new_min, double new_max)
// {
// 	double old_min;
// 	double	scaled_num;

// 	old_min = 0;
// 	scaled_num = 0;

// 	scaled_num = ((new_max - new_min) * (unscaled_num - old_min))
// 			/ (old_max - old_min) + new_min;
// 	return (scaled_num);
// }








// int	map_color(int i, int max_iterations, int start_color, int end_color)
// {
// 	double mu = i + 1 - log(log(fabs(z))) / log(2.0); // Calculate mu value

// 	// Normalize mu to the range [0, 1]
// 	double normalized_mu = mu / max_iterations;

// 	// Interpolate between start_color and end_color based on normalized_mu
// 	int red = (int)((1.0 - normalized_mu) * ((start_color >> 16) & 0xFF) + normalized_mu * ((end_color >> 16) & 0xFF));
// 	int green = (int)((1.0 - normalized_mu) * ((start_color >> 8) & 0xFF) + normalized_mu * ((end_color >> 8) & 0xFF));
// 	int blue = (int)((1.0 - normalized_mu) * (start_color & 0xFF) + normalized_mu * (end_color & 0xFF));

// 	// Combine red, green, and blue to get the final color
// 	int result_color = (red << 16) | (green << 8) | blue;

// 	return result_color;
// }







// // Function to calculate the magnitude of a complex number
// static double complex_magnitude(t_complex z)
// {
//   return sqrt(z.real * z.real + z.imaginary * z.imaginary);
// }

// // Function to calculate the fractional escape count (mu) for a pixel
// double calculate_mu(t_complex z)
// {
//   double magnitude = complex_magnitude(z);

//     if (magnitude == 0.0)
//     {
//         return 0.0; // Handle the case where |z| is 0 to avoid division by zero
//     }

//     double log_magnitude = log(log(magnitude));
//     return ESCAPE_COUNT + 1 - log_magnitude / log(2.0);
// }

// Function to map a value from one range to another
// static double mapp(double value, double from_min, double from_max, double to_min, double to_max)
// {
//     return (value - from_min) * (to_max - to_min) / (from_max - from_min) + to_min;
// }

// // Function to map the fractional escape count (mu) to a color
// uint32_t map_color(double mu, double max_iterations, uint32_t color_start, uint32_t color_end)
// {

// 	// Normalize mu to the range [0, 1]
//     double mu_normalized = mu / max_iterations;

//     // Interpolate between color_start and color_end based on mu_normalized
//     int red = (int)(mapp(mu_normalized, 0.0, 1.0, (color_start >> 16) & 0xFF, (color_end >> 16) & 0xFF));
//     int green = (int)(mapp(mu_normalized, 0.0, 1.0, (color_start >> 8) & 0xFF, (color_end >> 8) & 0xFF));
//     int blue = (int)(mapp(mu_normalized, 0.0, 1.0, color_start & 0xFF, color_end & 0xFF));

//     // Ensure RGB values are in the valid range [0, 255]
//     red = fmin(255, fmax(0, red));
//     green = fmin(255, fmax(0, green));
//     blue = fmin(255, fmax(0, blue));

//     // Pack the RGB values into an RGBA color
//     return ((uint32_t)red << 16) | ((uint32_t)green << 8) | (uint32_t)blue | 0xFF000000; // Alpha set to 255 (opaque)
// }


// double map_color(double pei,int iteration, int max_iteration, int color1, int color2)
// {
//     double mu;
//     //double modulus;

//     // Calculate mu
//     mu = iteration + 1 - log(log(fabs(pei))) / log(2);

//     // Map mu to color
//     double color = (double)((1 - mu) * color1 + mu * color2);

//     return color;
// }


// double map_color(double pei,int iteration, int max_iteration, int color1, int color2)
// {
//     double mu;
//     //double modulus;

//     // Calculate mu
//     mu = iteration + 1 - log(log(fabs(pei))) / log(2);

// 	// Normalize mu to the range [0, 1]
//     double mu_normalized = mu / max_iteration;

//     // Interpolate between color_start and color_end based on mu_normalized
//     int red = (int)(mapp(mu_normalized, 0.0, 1.0, (WHITE >> 16) & 0xFF, (TOMATO >> 16) & 0xFF));
//     //printf("a%d\n",(WHITE >> 16) & 0xFF);

//     int green = (int)(mapp(mu_normalized, 0.0, 1.0, (color1 >> 8) & 0xFF, (color2 >> 8) & 0xFF));
//     int blue = (int)(mapp(mu_normalized, 0.0, 1.0, color1 & 0xFF, color2 & 0xFF));

//     // Ensure RGB values are in the valid range [0, 255]
//     red = fmin(255, fmax(0, red));
//    // printf("b%d\n",red);
//     green = fmin(255, fmax(0, green));
//     blue = fmin(255, fmax(0, blue));

//     // Pack the RGB values into an RGBA color
//     return ((uint32_t)red << 16) | ((uint32_t)green << 8) | (uint32_t)blue | 0xFF000000; // Alpha set to 255 (opaque)
// }

//     // Map mu to color
//     double color = (double)((1 - mu) * color1 + mu * color2);

//     return color;
// }

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
int	map_color(int iter, int color, t_fractal *fractal)
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
