/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:24:51 by fde-alen          #+#    #+#             */
/*   Updated: 2023/04/27 15:01:30 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_display_file(int fd)
{
	char	buffer[65535];

	while (read(fd, buffer, 65534))
	{
		ft_putstr(buffer);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*error;
	int		fd;

	if (argc == 1)
	{
		error = "File name missing.\n";
		ft_putstr(error);
		return (1);
	}
	if (argc > 2)
	{
		error = "Too many arguments.\n";
		ft_putstr(error);
		return (2);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || ft_display_file(fd) == -1)
	{
		error = "Cannot read file.\n";
		ft_putstr(error);
		return (3);
	}
	close(fd);
	return (0);
}
