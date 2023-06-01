/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:41:37 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/31 22:24:23 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_text(int fd, char *line_buffer)
{
	char	*read_buffer;
	int		size;

	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	size = 1;
	while (!ft_strchr(line_buffer, '\n') && size != 0)
	{
		size = read(fd, read_buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(line_buffer);
			free(read_buffer);
			return (NULL);
		}
		read_buffer[size] = '\0';
		line_buffer = ft_strjoin(line_buffer, read_buffer);
	}
	free(read_buffer);
	return (line_buffer);
}

char	*extract_line(char *line_buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!line_buffer[i])
		return (NULL);
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (line_buffer[i] && line_buffer[i] != '\n')
	{
		line[i] = line_buffer[i];
		i++;
	}
	if (line_buffer[i] == '\n')
	{
		line[i] = line_buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*extract_remaining(char *line_buffer)
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line_buffer = read_text(fd, line_buffer);
	if (!line_buffer)
		return (NULL);
	line = extract_line(line_buffer);
	line_buffer = extract_remaining(line_buffer);
	return (line);
}
