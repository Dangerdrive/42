/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:41:37 by fde-alen          #+#    #+#             */
/*   Updated: 2023/06/07 14:27:21 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_text(int fd, char *line_buffer)
{
	char	*read_buffer;
	int		read_size;

	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	read_size = 1;
	while (!ft_strchr(line_buffer, '\n') && read_size != 0)
	{
		read_size = read(fd, read_buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(line_buffer);
			free(read_buffer);
			return (NULL);
		}
		read_buffer[read_size] = '\0';
		line_buffer = ft_strjoin(line_buffer, read_buffer);
	}
	free(read_buffer);
	return (line_buffer);
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
#include <stdio.h>
#include "get_next_line.h"

int main(void) {
    char *line;

    printf("Enter lines of text (press Ctrl+D to stop):\n");

    while ((line = get_next_line(0)) != NULL) {
        printf("Line: %s\n", line);
        free(line);
    }

    printf("End of input.\n");

    return 0;
}