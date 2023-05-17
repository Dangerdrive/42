#include "get_next_line.h"

char	*get_next_line(int fd)
{

	return (NULL);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_display_file(int fd)
{
	char	buffer[65535];

	while (read(fd, buffer, 65534))
	{
		ft_putstr(buffer);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*error;
	int		fd;

	if (argc == 1)
	{
		error = "File name missing.\n";
		ft_putstr(error);
		return (1);
	}
	if (argc > 2)
	{
		error = "Too many arguments.\n";
		ft_putstr(error);
		return (2);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || ft_display_file(fd) == -1)
	{
		error = "Cannot read file.\n";
		ft_putstr(error);
		return (3);
	}
	close(fd);
	return (0);
}


/*
Parameters
Return value
External functs.
Description
get_next_line
char *get_next_line(int fd);
get_next_line.c, get_next_line_utils.c,
get_next_line.h
fd: The file descriptor to read from
Read line: correct behavior
NULL: there is nothing else to read, or an error
occurred
read, malloc, free
Write a function that returns a line read from a
file descriptor

*/