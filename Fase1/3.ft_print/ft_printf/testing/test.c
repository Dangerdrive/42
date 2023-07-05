// #include "ft_printf.h"

// int	ft_print_ptr(unsigned long long num)
// {
// 	char	*str;
// 	int		len;

// 	printf("num1: %llu\n", num);
// 	len = 0;
// 	if (num == 0)
// 	{
// 		len += write(1, "(nil)", 5);
// 		return (len);
// 	}
// 	else
// 	{
// 		if (num < 0)
// 			num = num * -1;
// 		printf("num2if: %llu\n", num);
// 	}
// 	str = ft_itoa_base(num, 16);
// 	printf("num3: %llu\n", num);
// 	len += write(1, "0x", 2);
// 	// if (num == 0)
// 	// 	len += write(1, "0", 1);
// 		len += ft_printstr(str);
// 		free(str);
// //	}	
// 	return (len);
// }

// int	parse_flags(va_list args, const char flag)
// {
// 	int	len;

// 	len = 0;
// 	if (flag == '#')
// 	{
// 		//if X, printar 0X
// 		//if X, printar 0x
// 	}	//len += ft_printchar(va_arg(args, int));
// 	else if (flag == ' ')
// 	{
// 			return (len += ft_printchar(' '));
// 	}
// 	else if (flag == '+')
// 	{
// 		if (va_arg(args, int) >= 0)
// 			return (len += ft_printchar('+'));
// 		else
// 			return (len += ft_printchar('-'));
// 	}
// 	return (0);
// }

// int	parse_format_type(va_list args, const char type)
// {
// 	int	len;

// 	len = 0;
// 	if (type == 'c')
// 		len += ft_printchar(va_arg(args, int));
// 	else if (type == 's')
// 		len += ft_printstr(va_arg(args, char *));
// 	else if (type == 'd' || type == 'i')
// 		len += ft_printnbr(va_arg(args, int));
// 	else if (type == '%')
// 		len += ft_printchar('%');
// 	else if (type == 'u')
// 		len += ft_print_unsigned(va_arg(args, unsigned int));
// 	else if (type == 'x' || type == 'X')
// 		len += ft_print_hex(va_arg(args, unsigned int), type);
// 	else if (type == 'p')
// 		len += ft_print_ptr(va_arg(args, unsigned long long));
// 	return (len);
// }

// int	ft_printf(const char *format, ...)
// {
// 	va_list	args;
// 	int		i;
// 	int		len;

// 	i = 0;
// 	len = 0;
// 	va_start(args, format);
// 	while (format[i])
// 	{
// 		if (format[i] == '%')
// 		{
// 			if (format[i + 1] == '#' || format[i + 1] == ' ' || format[i + 1] == ' ')
// 				{
// 					//len += parse_flags(args,format[i + 1])
// 					i++;
// 				}
// 			if (format[i + 1] == '0' || format[i + 1] == '.' || format[i + 1] == '-')
// 				i++;
// 			len += parse_format_type(args, format[i + 1]);
// 			i++;
// 		}
// 		else
// 			len += ft_printchar(format[i]);
// 		i++;
// 	}
// 	va_end(args);
// 	return (len);
// }

#include <stdio.h>
#include <limits.h>

// int	main()
// {
// 	printf("teste %llu\n", -9223372036854775808);	
// }
