#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <errno.h>

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

	// Read lines until the end of the file or an error occurs
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}

	// Check if an error occurred or if there is more to read
	if (line == NULL && errno != 0)
	{
		perror("Error reading file");
		close(fd);
		return 1;
	}

	// Close the file
	close(fd);

	return 0;
}
