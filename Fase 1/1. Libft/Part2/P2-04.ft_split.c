static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (n);
}

static size_t	word_length(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static cha	*copy_word(const char *s, size_t len)
{
	char	*word;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	n;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	n = count_words(s, c);
	split = (char **)malloc((n + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (i < n)
	{
		while (s[j] && s[j] == c)
			j++;
		split[i] = copy_word(&s[j], word_length(&s[j], c));
		if (!split[i])
		{
			while (i > 0)
				free(split[--i]);
			free(split);
			return (NULL);
		}
		i++;
		j += word_length(&s[j], c);
	}
	split[i] = NULL;
	return (split);
}


// #1. The string to be split.
// #2. The delimiter character.
// The array of new strings resulting from the split.
// NULL if the allocation fails.
// malloc, free
// Allocates (with malloc(3)) and returns an array
// of strings obtained by splitting ’s’ using the
// character ’c’ as a delimiter. The array must be
// ended by a NULL pointer.

// Parameters
// Return value
// External functs.
// Description