#include "get_next_line.h"
#include <stdio.h> // printf
#include <stdlib.h> // realloc
#include <fcntl.h>	// open
#include <unistd.h> // read, close

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

#include "get_next_line.h"
#include <unistd.h>
//#include <stdio.h>
//#include <fcntl.h>

char	*ft_read_to_left_str(int fd, char *remaining)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(remaining, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		remaining = ft_strjoin(remaining, buffer);
	}
	free(buffer);
	return (remaining);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remaining;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	remaining = ft_read_to_left_str(fd, remaining);
	if (!remaining)
		return (NULL);
	line = ft_get_line(remaining);
	remaining = ft_new_left_str(remaining);
	return (line);
}

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/