#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char *text1 = "ajuda é algo que você recebe, não algo que você dá\n";
	char *text2 = "ajuda é bão\n";

	printf("ft_strcmp = %d\n", ft_strcmp(text1, text2));
	printf("strcmp = %d", strcmp(text1, text2));
}
