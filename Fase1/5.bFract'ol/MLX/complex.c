#include "fractol.h"

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	c;

	c.real = a.real + b.real;
	c.imaginary = a.imaginary + b.imaginary;
	return (c);
}

t_complex	complex_sqr(t_complex a)
{
	t_complex	c;

	c.real = a.real * a.real - a.imaginary * a.imaginary;
	c.imaginary = 2 * a.real * a.imaginary;
	return (c);
}

