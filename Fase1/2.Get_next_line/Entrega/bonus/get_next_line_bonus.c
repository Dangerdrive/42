/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:41:21 by fde-alen          #+#    #+#             */
/*   Updated: 2023/06/07 13:42:35 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		return (NULL);
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
	j = 0;
	while (line_buffer[i])
		remaining_buffer[j++] = line_buffer[i++];
	remaining_buffer[j] = '\0';
	free(line_buffer);
	return (remaining_buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_buffer[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line_buffer[fd] = read_text(fd, line_buffer[fd]);
	if (!line_buffer[fd])
		return (NULL);
	line = extract_line(line_buffer[fd]);
	line_buffer[fd] = extract_remaining(line_buffer[fd]);
	return (line);
}
