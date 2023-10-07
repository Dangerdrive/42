#include "fractol.h"

t_complex	complex_sum(t_complex a, t_complex b)
{
	t_complex	c;

	c.real = a.real + b.real;
	c.i = a.i + b.i;
	return (c);
}

t_complex	complex_sqr(t_complex a)
{
	t_complex	c;

	c.real = a.real * a.real - a.i * a.i;
	c.i = 2 * a.real * a.i;
	return (c);
}
double	map(double unscaled_num, double old_max, double new_min, double new_max)
{
	if (old_max == 0 || new_max == 0)
    	return 1;
	double old_min;
	double	scaled_num;

	old_min = 0;
	scaled_num = 0;

	scaled_num = ((new_max - new_min) * (unscaled_num - old_min))
			/ (old_max - old_min) + new_min;
	return (scaled_num);
}



