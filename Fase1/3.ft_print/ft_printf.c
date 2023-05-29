#include "ft_printf.h"

#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c)
{
	return write(1, &c, 1);
}

int ft_putstr(char *str)
{
	int len = 0;
	while (*str)
	{
		len += ft_putchar(*str);
		str++;
	}
	return len;
}

int ft_putnbr(int n)
{
	int count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
	}
	count += ft_putchar(n % 10 + '0');
	return count;
}

int ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);
				count += ft_putchar(c);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				count += ft_putstr(str);
			}
			else if (*format == 'd')
			{
				int n = va_arg(args, int);
				count += ft_putnbr(n);
			}
		}
		else
		{
			count += ft_putchar(*format);
		}
		format++;
	}

	va_end(args);

	return count;
}

int main()
{
	ft_printf("Hello, %s! The answer is %d.\n", "world", 42);
	return 0;
}
