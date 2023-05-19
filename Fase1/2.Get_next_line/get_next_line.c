#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 300
#endif

static char	*read_line(int fd, char *buffer, char *remainder)
{
	int		bytes_read;
	char	*line_break;
	char	*temp;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if ((line_break = ft_strchr(buffer, '\n')) != NULL)
		{
			*line_break = '\0';
			temp = remainder;
			remainder = ft_strdup(line_break + 1);
			free(temp);
			return (buffer);
		}
		temp = remainder;
		remainder = ft_strjoin(remainder, buffer);
		free(temp);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(remainder);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (remainder != NULL)
	{
		if ((line = ft_strchr(remainder, '\n')) != NULL)
		{
			*line = '\0';
			line = ft_strdup(remainder);
			ft_strcpy(remainder, line + ft_strlen(line) + 1);
			free(buffer);
			return (line);
		}
		free(buffer);
		buffer = ft_strdup(remainder);
		free(remainder);
		remainder = NULL;
	}
	return (read_line(fd, buffer, remainder));
}
