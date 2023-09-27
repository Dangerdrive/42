#include "fractol.h"

double	map_color(double unscaled_num, double old_max, double new_min, double new_max)
{
	double old_min;
	double	scaled_num;

	old_min = 0;
	scaled_num = 0;

	scaled_num = ((new_max - new_min) * (unscaled_num - old_min))
			/ (old_max - old_min) + new_min;
	return (scaled_num);
}