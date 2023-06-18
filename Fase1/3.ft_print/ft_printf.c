#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return 1;
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

int	print_type(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == '%')
		count += ft_print_char('%');
	// else if (type == 'c')
	// 	count += ft_print_char(va_arg(args, int));
	// else if (type == 's')
	// 	count += ft_print_str(va_arg(args, const char *));
	// else if (type == 'd' || type == 'i')
	// 	count += ft_print_int(va_arg(args, int));
	// else if (type == 'x')
	// 	count += ft_print_hex(va_arg(args, unsigned int), 0);
	// else if (type == 'X')
	// 	count += ft_print_hex(va_arg(args, unsigned int), 1);
	// else if (type == 'u')
	// 	count += ft_print_unsigned(va_arg(args, unsigned int));
	// else if (type == 'p')
	// 	count += ft_print_ptr((unsigned long int)va_arg(args, void *));
	return (count);
}





// int ft_printf(const char *format, ...)
// {
// 	va_list args;
// 	int count = 0;

// 	va_start(args, format);
// 	while (*format)
// 	{
// 		if (*format == '%')
// 		{
// 			format++;
// 			if (*format == 'c')
// 			{
// 				char c = va_arg(args, int);
// 				count += ft_putchar(c);
// 			}
// 			else if (*format == 's')
// 			{
// 				char *str = va_arg(args, char *);
// 				count += ft_putstr(str);
// 			}
// 			else if (*format == 'd')
// 			{
// 				int n = va_arg(args, int);
// 				count += ft_putnbr(n);
// 			}
// 		}
// 		else
// 			count += ft_putchar(*format);
// 		format++;
// 	}
// 	va_end(args);
// 	return count;
// }

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;
	char		*str;

	count = 0;
	if (!format || *format == '\0')
		return (0);
	str = ft_strdup(format);
	if (!str || *str == '\0')
		return (0);
	va_start(args, format);
	count = ft_parse(str, args);
	va_end(args);
	free(str);
	return (count);
}

int main()
{
	ft_printf("Hello, %s! The answer is %d.\n", "world", 42);
	return 0;
}
