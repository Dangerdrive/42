#include "libft.h"
#include "libftests.h"

int	main(void)
{
	//itoa_test();
	//strmapi_test();
	//striteri_test();
	//strjoin_test();
	//substr_test();
	//putchar_fd_test();
	//putstr_fd_test();
	//putnbr_fd_test();
	putendl_fd_test();
}

// char	*aux_ft_strlupcase(unsigned int n, char *str)
// {
// 	unsigned int i;

// 	i = 0;
// 	while (str[i] != '\0' && i < n)
// 	{
// 		if (str[i] >= 'a' && str[i] <= 'z')
// 			str[i] -= 32;
// 		i++;
// 	}
// 	return (str);
// }
int	putendl_fd_test(void)
{
	char	*tested_func = "ft_putendl_fd";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);

	char	*str_test = "Keep those blurry memories";

	ft_putstr_fd("ft_putendl_fd: ", 1);
	//printf("%s:", tested_func);
	ft_putendl_fd(str_test, 1);
	printf("printf: %s\n", str_test);


	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);
	return (1);
}

int	putnbr_fd_test(void)
{
	char	*tested_func;
	tested_func = "ft_putnbr_fd";
	printf("\\\\TEST %s\n\n", tested_func);

	int	num_test = -2147483647;

	ft_putstr_fd("ft_putstr_fd:\t", 1);
	//printf("%s:", tested_func);
	ft_putnbr_fd(num_test, 1);
	printf("\nprintf:\t\t%i\n", num_test);


	printf("\n\\\\END of %s test\n", tested_func);
	return (1);
}

int	putstr_fd_test(void)
{
	char	*tested_func = "ft_putstr_fd";
	printf("\\\\TEST %s\n\n", tested_func);

	char	*str_test = "Keep those blurry memories\n";

	ft_putstr_fd("ft_putstr_fd: ", 1);
	//printf("%s:", tested_func);
	ft_putstr_fd(str_test, 1);
	printf("\nprintf: %s", str_test);


	printf("\n\\\\END of %s test\n", tested_func);
	return (1);
}

int	putchar_fd_test(void)
{
	char	*tested_func = "ft_putchar_fd";
	printf("\\\\TEST %s\n\n", tested_func);

	char testchar = 'Z';

	ft_putchar_fd(testchar, 1);
	printf("\nprintf: %c", testchar);

	printf("\n");

	printf("\n\\\\END of %s test\n", tested_func);
	return (1);
}

int	substr_test(void)
{
	char	*tested_func = "substr_test";
    printf("\\\\TEST %s\n\n", tested_func);
	char	*src_str = "Se você está procurando um compositor que seja tão virtuoso e empolgante quanto Vivaldi, eu sugiro que você dê uma olhada em Johann Sebastian Bach. ";
	int		start = 9;
	size_t	len = 30;
	printf("1. source string: %s\nstart: %i \t lenght: %zu\n", src_str, start, len);
	char	*sub_str = ft_substr(src_str, start, len);

	printf("substring: %s\n", sub_str);

	src_str = "Se você está procurando um compositor que seja tão virtuoso e empolgante quanto Vivaldi, eu sugiro que você dê uma olhada em Johann Sebastian Bach. ";
	start = 2;
	len = 400;
	printf("\n2. source string: %s\nstart: %i \t lenght: %zu\n", src_str, start, len);

	sub_str = ft_substr(src_str, start, len);
	printf("substring%s\n", sub_str);

    printf("\n\\\\END of %s test\n", tested_func);
	return (1);
}

int	strjoin_test(void)
{
	char	*str1 = "Keep those blurry memories somewhere safe,\n";
	char	*str2 = "You may need them.";
	char	*joined;
	joined = ft_strjoin(str1, str2);
	printf("%s", joined);
	return (1);
}

char aux_toupper(unsigned int i, char c)
{
	if (islower(c)) {
		return toupper(c);
	} else {
		return c;
	}
	i = c - 48;
}
void test_char_to_upper(unsigned int i, char *c) {
    if (islower(*c)) {
        *c = toupper(*c);
		i = c[0];
    }
}

int striteri_test() {
    printf("\\\\TEST ft_striteri\n");
    char str[] = "hello world";
    printf("Before: %s\n", str);
    ft_striteri(str, &test_char_to_upper);
    printf("After: %s\n", str);
    printf("\\\\END of ft_striteri test\n");
    return 1;
}

int strmapi_test()
{
	printf("\\\\TEST ft_strmapi\n");
	char	*str = "There's no rabbit out the hat.";
	printf("string tested: %s\n", str);

	char	*result = ft_strmapi(str, &aux_toupper);
	
	printf("ft_strmapi: %s\n", result);

	printf("\\\\END of ft_strmapi test\n");

	free(result);
	return (1);
}

int	strtrim_test()
{
	char *s1 = "You can make a wish, but there's no rabbit out the hat.";
	char *set = "You can out the hat";
	char *s1_copy = strdup(s1); // Make a copy of s1
	char *trimmed = strtok(s1_copy, set);
	while (trimmed != NULL) 
	{
	printf("teste 1: %s\n", trimmed);
    trimmed = strtok(NULL, set);
	}
	printf("teste 1: %s\n", s1_copy);
	free(s1_copy);
	return (1); // Free the memory allocated by strdup
}

int itoa_test(void)
{
	int		num = 34753;
	char 	*result = ft_itoa(num);
	printf("\\\\TEST ft_itoa\n");
	printf("ft_itoa: %s\n", result);

	char str[10];
	sprintf(str, "%d", num);
	printf("sprintf: %s\n", str);
	printf("\\\\end of ft_itoa test\n");

	free(result);
	return (1);
}
