#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;

	// Open the file
	fd = open("fucker.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return 1;
	}

	// Read lines until the end of file or an error occurs
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}

	// Check for errors
	if (line == NULL && !feof(fd))
	{
		perror("Error reading file");
		return 1;
	}

	// Close the file
	if (close(fd) < 0)
	{
		perror("Error closing file");
		return 1;
	}

	return 0;
}
