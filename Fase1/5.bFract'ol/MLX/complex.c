#include "fractol.h"

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	c;

	c.real = a.real + b.real;
	c.imaginary = a.imaginary + b.imaginary;
	return (c);
}

t_complex	complex_multiply(t_complex a, t_complex b)
{
	t_complex	c;

	c.real = a.real * b.real - a.imaginary * b.imaginary;
	c.imaginary = a.real * b.imaginary + a.imaginary * b.real;
	return (c);
}

