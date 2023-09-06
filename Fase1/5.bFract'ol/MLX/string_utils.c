#include "fractol.h"

int	strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (str1 == NULL || str2 == NULL)
		return (0);
	while (i < n && str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (str == NULL || fd < 0)
		return;
	while (str)
		{
			write(fd, str, 1);
			str++;
		}
}