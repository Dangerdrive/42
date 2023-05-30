#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *remaining, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!remaining)
	{
		remaining = (char *)malloc(1 * sizeof(char));
		remaining[0] = '\0';
	}
	if (!remaining || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(remaining) + ft_strlen(buffer)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (remaining)
		while (remaining[++i] != '\0')
			str[i] = remaining[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(remaining) + ft_strlen(buffer)] = '\0';
	free(remaining);
	return (str);
}

char	*ft_get_line(char *remaining)
{
	int		i;
	char	*str;

	i = 0;
	if (!remaining[i])
		return (NULL);
	while (remaining[i] && remaining[i] != '\n')
		i++;
	str = (char *)malloc((i + 2 + sizeof(char)));
	if (!str)
		return (NULL);
	i = 0;
	while (remaining[i] && remaining[i] != '\n')
	{
		str[i] = remaining[i];
		i++;
	}
	if (remaining[i] == '\n')
	{
		str[i] = remaining[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_remaining(char *remaining)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (remaining[i] && remaining[i] != '\n')
		i++;
	if (!remaining[i])
	{
		free(remaining);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(remaining) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (remaining[i])
		str[j++] = remaining[i++];
	str[j] = '\0';
	free(remaining);
	return (str);
}