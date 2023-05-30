#include "get_next_line.h"
#include <stdio.h> // printf
#include <stdlib.h> // realloc
#include <fcntl.h>	// open
#include <unistd.h> // read, close

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

size_t	ft_linelen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*str != '\0' && *str != '\n')
	{
		i++;
		str++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	int		buffer_size = BUFFER_SIZE;
	char	*temp = "\0";
	char	*line = NULL;
	int		i = 0;

	//ultimo ponto funcionando5.

	buffer = (char *)malloc(sizeof(char) * (buffer_size + 1));
	while (read(fd, buffer, buffer_size))
	{
		line = ft_strjoin(temp, buffer);
		free(temp);
		temp = line;
		i++;
	}
	return (ft_substr(line, 0, ft_linelen(line)));
}

int	main(int argc, char **argv)
{
	char	*error;
	int		fd;
	char	*result = NULL;

	if (argc == 1)
	{
		error = "File name missing.\n";
		printf("%s\n", error);
		return (1);
	}
	if (argc > 2)
	{
		error = "Too many arguments.\n";
		printf("%s\n", error);
		return (2);
	}
	fd = open(argv[1], 00);
	result = get_next_line(fd);
	printf("\nresult: %s\n", result);
	// //if (fd == -1 || get_next_line(fd) == NULL)
	// {
	// 	error = "Cannot read file.\n";
	// 	printf("%s\n", error);
	// 	return (3);
	// }
	close(fd);
	return (0);
}





