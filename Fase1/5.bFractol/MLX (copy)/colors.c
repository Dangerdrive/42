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
//     return sqrt(z.real * z.real + z.imaginary * z.imaginary);
// }

// // Function to calculate the fractional escape count (mu) for a pixel
// double calculate_mu(t_complex z)
// {
//     double magnitude = complex_magnitude(z);

//     if (magnitude == 0.0)
//     {
//         return 0.0; // Handle the case where |z| is 0 to avoid division by zero
//     }

//     double log_magnitude = log(log(magnitude));
//     return ESCAPE_COUNT + 1 - log_magnitude / log(2.0);
// }

// // Function to map a value from one range to another
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


int map_color(double pei,int iteration, int max_iteration, int color1, int color2)
{
    double mu;
    //double modulus;

    // Calculate mu
    mu = iteration + 1 - log(log(fabs(pei))) / log(2);

    // Map mu to color
    int color = (int)((1 - mu) * color1 + mu * color2);

    return color;
}