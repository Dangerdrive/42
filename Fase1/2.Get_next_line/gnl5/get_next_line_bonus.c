/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:41:21 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/31 22:14:50 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_text(int fd, char *line_buffer)
{
	char	*buffer;
	int		size;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	size = 1;
	while (!ft_strchr(line_buffer, '\n') && size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(line_buffer);
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		line_buffer = ft_strjoin(line_buffer, buffer);
	}
	free(buffer);
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
	char	*tab;

	i = 0;
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	if (!line_buffer[i])
	{
		free(line_buffer);
		return (NULL);
	}
	tab = (char *)malloc(sizeof(char) * (ft_strlen(line_buffer) - i + 1));
	if (!tab)
		return (NULL);
	i++;
	j = 0;
	while (line_buffer[i])
		tab[j++] = line_buffer[i++];
	tab[j] = '\0';
	free(line_buffer);
	return (tab);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_buffer[16384];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line_buffer[fd] = read_text(fd, line_buffer[fd]);
	if (!line_buffer[fd])
		return (NULL);
	line = extract_line(line_buffer[fd]);
	line_buffer[fd] = extract_remaining(line_buffer[fd]);
	return (line);
}
