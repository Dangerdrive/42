#include "get_next_line.h"
#include <stdio.h> // printf
#include <stdlib.h> // realloc
#include <fcntl.h>	// open
#include <unistd.h> // read, close
#include <string.h> // strlcpy - substituir

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

char* concatenateStrings(char** arr, int size)
{
    int totalLength = 0;

    // Calculate the total length of the concatenated string
    for (int i = 0; i < size; i++) {
        totalLength += ft_strlen(arr[i]);
    }

    // Allocate memory for the concatenated string (+1 for null terminator)
    char* result = (char*)malloc((totalLength + 1) * sizeof(char));
    if (result == NULL) {
        printf("Failed to allocate memory for concatenated string.\n");
        return NULL;
    }

    // Concatenate the strings
    int currentIndex = 0;
    for (int i = 0; i < size; i++) {
        strcpy(result + currentIndex, arr[i]);
        currentIndex += ft_strlen(arr[i]);
    }

    // Null terminate the concatenated string
    result[totalLength] = '\0';

    return result;
}

char	*get_next_line(int fd)
{
	char	*buffer;
	int		buffer_size = BUFFER_SIZE;
	char	*arr[3000];
	int		i = 0;
	//ultimo ponto funcionando3.

	buffer = (char *)malloc(sizeof(char) * (buffer_size + 1));
	while (read(fd, buffer, buffer_size))
	{
		//printf("%s", buffer);
		arr[i] = (char *)malloc(sizeof(char) * (buffer_size + 1));
		ft_strlcpy(arr[i], buffer, buffer_size + 1);
		i++;
		//printf("%d\n", i);

	}
	//printf("\n");
	i = 0;
	//int j = 0; //fix
	while (arr[i])
	{
		printf("%s", arr[i]);
		// while (arr[i][j] != '\0' && arr[i][j] != '\n')
		// {
		// 	write(1, &arr[i][j], 1);
		// 	 j++;
		// }
		i++;
	}
	printf("\n");
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	return (concatenateStrings(arr, arrSize + 1));
}

int	main(int argc, char **argv)
{
	char	*error;
	int		fd;

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
	/*char * result = */get_next_line(fd);
	//printf("char result: %s", result);
	// //if (fd == -1 || get_next_line(fd) == NULL)
	// {
	// 	error = "Cannot read file.\n";
	// 	printf("%s\n", error);
	// 	return (3);
	// }
	close(fd);
	return (0);
}










// static char	*read_line(int fd, char **buffer, char *remainder)
// {
// 	int		bytes_read;
// 	char	*line_break;
// 	char	*temp;
// 	int		buffer_size = BUFFER_SIZE;

// 	bytes_read = read(fd, *buffer, buffer_size);
// 	while (bytes_read > 0)
// 	{
// 		(*buffer)[bytes_read] = '\0';
// 		if ((line_break = ft_strchr(*buffer, '\n')) != NULL)
// 		{
// 			*line_break = '\0';
// 			temp = remainder;
// 			remainder = ft_strdup(line_break + 1);
// 			free(temp);
// 			return (*buffer);
// 		}
// 		buffer_size *= 2; // Double the buffer size
// 		*buffer = realloc(*buffer, buffer_size + 1);
// 		if (*buffer == NULL)
// 		{
// 			free(remainder);
// 			return (NULL);
// 		}
// 		temp = remainder;
// 		remainder = ft_strjoin(remainder, *buffer);
// 		free(temp);
// 		bytes_read = read(fd, *buffer + buffer_size / 2, buffer_size / 2);
// 	}
// 	free(remainder);
// 	return (NULL);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*remainder;
// 	char		*buffer;
// 	char		*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
// 	{
// 		"%s\n", printf("fd is negative or BUFFER_SIZE is negative or read() failed\n");
// 		return (NULL);
// 	}
// 	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (buffer == NULL)
// 	{
// 		"%s\n", printf("buffer is NULL\n");
// 		return (NULL);
// 	}
// 	if (remainder != NULL)
// 	{
// 		"%s\n", printf("remainder is not NULL\n");
// 		if ((line = ft_strchr(remainder, '\n')) != NULL)
// 		{
// 			"%s\n", printf("line break found\n");
// 			"%s\n", printf("line(ft_strchr): %s\n", line);
// 			*line = '\0';
// 			line = ft_strdup(remainder);
// 			"%s\n", printf("line(after ft_strdup remainder): %s\n", line);
// 			ft_strcpy(remainder, line + ft_strlen(line) + 1);
// 			"%s\n", printf("remainder(after ft_strcpy): %s\n", remainder);
// 			"%s\n", printf("line(after ft_strcpy): %s\n", line);
// 			free(buffer);
// 			return (line);
// 		}
// 		free(buffer);
// 		buffer = ft_strdup(remainder);
// 		free(remainder);
// 		remainder = NULL;
// 	}
// 	return (read_line(fd, &buffer, remainder));
// }

// #include <fcntl.h>
// #include "get_next_line.h"

// int main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("fucker.txt", O_RDONLY);  // Replace "example.txt" with the file you want to read
// 	if (fd == -1)
// 	{
// 		"%s\n", printf("Failed to open the file.\n");
// 		return 1;
// 	}

// 	line = get_next_line(fd);
// 	int i = 0;
// 	while (line != NULL)
// 	{
// 		"%s\n", printf("%s\n", line);
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 		if (i >= 3) // Print only the first 3 lines
// 			break;
// 	}

// 	close(fd);

// 	return 0;
// }
