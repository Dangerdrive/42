#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define NO_FLAG (0)

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>

// auxiliary functions
char		*ft_itoa(int num);
int			ft_numlen(int num);
char		*ft_uitoa_base(unsigned long num, int base, const char format);
int			ft_unumlen_base(unsigned long num, int base);
// print type functions
int			ft_print_char(char c);
int			ft_print_hex(unsigned int num, const char format, const char flag);
int			ft_print_nbr(int num, const char flag);
int			ft_print_ptr(unsigned long int num);
int			ft_print_str(char *str);
int			ft_print_unsigned(unsigned int num);
// ft_print
int			ft_printf(const char *frmt, ...);

#endif

int	ft_unumlen_base(unsigned long num, int base)
{
	int	len;

	len = 1;
	while (num / base)
	{
		num /= base;
		len++;
	}
	return (len);
}

int	ft_numlen(int num)
{
	int	len;

	len = 1;
	while (num / 10)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int num)
{
	char	*str;
	int		len;
	int		sign;

	if (num < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_numlen(num);
	if (sign == -1)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = (sign * (num % 10)) + '0';
		num /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

char	*ft_uitoa_base(unsigned long num, int base, const char format)
{
	char	*str;
	int		len;

	len = ft_unumlen_base(num, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		if (format == 'x')
			str[len--] = "0123456789abcdef"[num % base];
		if (format == 'X')
			str[len--] = "0123456789ABCDEF"[num % base];
		num /= base;
	}
	return (str);
}

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

int	ft_print_nbr(int num, const char flag)
{
	int		count;
	char	*str;

	count = 0;
	if (flag == '+')
	{
		if (num >= 0)
			count += write(1, "+", 1);
	}
	else if (flag == ' ')
	{
		if (num >= 0)
			count += write(1, " ", 1);
	}
	str = ft_itoa(num);
	count += ft_print_str(str);
	free(str);
	return (count);
}

int	ft_print_hex(unsigned int num, const char format, const char flag)
{
	char	*str;
	int		len;

	len = 0;
	if (flag == '#' && num != 0)
	{
		if (format == 'x')
			len += ft_print_str("0x");
		if (format == 'X')
			len += ft_print_str("0X");
	}
	if (format == 'x')
		str = ft_uitoa_base(num, 16, 'x');
	if (format == 'X')
		str = ft_uitoa_base(num, 16, 'X');
	len += ft_print_str(str);
	free(str);
	return (len);
}
int	ft_print_ptr(unsigned long int num)
{
	char	*str;
	int		len;

	len = 0;
	if (num == 0)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	str = ft_uitoa_base(num, 16, 'x');
	len += write(1, "0x", 2);
	len += ft_print_str(str);
	free(str);
	return (len);
}

int	ft_print_unsigned(unsigned int num)
{
	char	*str;
	int		len;

	str = ft_uitoa_base(num, 10, 'x');
	len = ft_print_str(str);
	free(str);
	return (len);
}

static int	parse_format_type(va_list args, const char *type)
{
	int		len;
	char	flag;

	flag = NO_FLAG;
	len = 0;
	if (*type == '#' || *type == ' ' || *type == '+')
	{
		flag = *type;
		type++;
	}
	if (*type == '%')
		len += ft_print_char('%');
	else if (*type == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (*type == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (*type == 'd' || *type == 'i')
		len += ft_print_nbr(va_arg(args, int), flag);
	else if (*type == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (*type == 'x' || *type == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), *type, flag);
	else if (*type == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long));
	return (len);
}

int	ft_printf(const char *frmt, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (frmt == NULL)
		return (-1);
	va_start(args, frmt);
	while (frmt[i])
	{
		if (frmt[i] == '%')
		{
			len += parse_format_type(args, &frmt[i + 1]);
			if (frmt[i + 1] == '#' || frmt[i + 1] == ' ' || frmt[i + 1] == '+')
				i++;
			i++;
		}
		else
			len += ft_print_char(frmt[i]);
		i++;
	}
	va_end(args);
	return (len);
}
