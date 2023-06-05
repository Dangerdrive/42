/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:41:37 by fde-alen          #+#    #+#             */
/*   Updated: 2023/06/04 20:11:08 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static char	*read_text(int fd, char *line_buffer)
// {
// 	char	*read_buffer;
// 	int		read_size;

// 	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!read_buffer)
// 		return (NULL);
// 	read_size = 1;
// 	while (!ft_strchr(line_buffer, '\n') && read_size != 0)
// 	{
// 		read_size = read(fd, read_buffer, BUFFER_SIZE);
// 		if (read_size == -1)
// 		{
// 			free(line_buffer);
// 			free(read_buffer);
// 			return (NULL);
// 		}
// 		read_buffer[read_size] = '\0';
// 		line_buffer = ft_strjoin(line_buffer, read_buffer);
// 	}
// 	free(read_buffer);
// 	//printf("\nread_text: %s\n\n", line_buffer);
// 	return (line_buffer);
// }

static char *read_text(int fd, char *line_buffer)
{
    char *read_buffer;
    int read_size;

    read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!read_buffer)
        return NULL;
    read_size = 1;
    while (!ft_strchr(line_buffer, '\n') && read_size != 0)
    {
        read_size = read(fd, read_buffer, BUFFER_SIZE);
        if (read_size == -1)
        {
            free(line_buffer);
            free(read_buffer);
            return NULL;
        }
        read_buffer[read_size] = '\0';
        line_buffer = ft_strjoin(line_buffer, read_buffer);
    }
    free(read_buffer);
    // printf("\nread_text: %s\n\n", line_buffer);
    return line_buffer;
}

static char	*extract_line(char *line_buffer)
{
	int		i;
	char	*extracted_line;

	i = 0;
	if (!line_buffer[i])
		return (0);
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	extracted_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!extracted_line)
		return (NULL);
	i = 0;
	while (line_buffer[i] && line_buffer[i] != '\n')
	{
		extracted_line[i] = line_buffer[i];
		i++;
	}
	if (line_buffer[i] == '\n')
	{
		extracted_line[i] = line_buffer[i];
		i++;
	}
	extracted_line[i] = '\0';
	return (extracted_line);
}

static char	*extract_remaining(char *line_buffer)
{
	int		i;
	int		j;
	char	*remaining_buffer;

	i = 0;
	j = 0;
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	if (!line_buffer[i])
	{
		free(line_buffer);
		return (NULL);
	}
	remaining_buffer = malloc(sizeof(char) * (ft_strlen(line_buffer) - i + 1));
	if (!remaining_buffer)
		return (NULL);
	i++;
	while (line_buffer[i])
		remaining_buffer[j++] = line_buffer[i++];
	remaining_buffer[j] = '\0';
	free(line_buffer);
	//printf("\nremaining_buffer: %s\n\n", remaining_buffer);
	return (remaining_buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_buffer;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line_buffer = read_text(fd, line_buffer);
	if (!line_buffer)
		return (NULL);
	line = extract_line(line_buffer);
	line_buffer = extract_remaining(line_buffer);
	return (line);
}

// #include <stdio.h>
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
