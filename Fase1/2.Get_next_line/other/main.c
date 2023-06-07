// #include <stdio.h>
// #include <fnctl.h>
// int	main(int argc, char **argv)
// {
// 	char	*error;
// 	int		fd;
// 	char	*result = NULL;

// 	if (argc == 1)
// 	{
// 		error = "File name missing.\n";
// 		printf("%s\n", error);
// 		return (1);
// 	}
// 	if (argc > 2)
// 	{
// 		error = "Too many arguments.\n";
// 		printf("%s\n", error);
// 		return (2);
// 	}
// 	fd = open(argv[1], 00);
// 	result = get_next_line(fd);
// 	printf("\nresult: %s\n", result);
// 	// //if (fd == -1 || get_next_line(fd) == NULL)
// 	// {
// 	// 	error = "Cannot read file.\n";
// 	// 	printf("%s\n", error);
// 	// 	return (3);
// 	// }
// 	close(fd);
// 	return (0);
// }
