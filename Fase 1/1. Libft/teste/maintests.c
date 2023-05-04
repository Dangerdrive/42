#include "libft.h"
#include "libftests.h"

int	main(void)
{
	// isalpha_test(); //teste não está dando output
	// isdigit_test();
	// isalnum_test();
	// isalnum_test();
	// isascii_test();
	// isprint_test(); //05
	// strlen_test(); //06
	// memset_test(); //07  - arrumar. Deve modificar a string recebida.
	// bzero_test();
	memcpy_test();
	// strlcpy_test(); //11
	//strlcat_test(); //12  arrumar
	//toupper_test(); //13
	//tolower_test(); //14

	//itoa_test();
	//strmapi_test();
	//striteri_test();
	//strjoin_test();
	//substr_test();
	//putchar_fd_test();
	//putstr_fd_test();
	//putnbr_fd_test();
	//putendl_fd_test();
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

// P1-01
int	isalphaft__test(void)
{
	char	*tested_func;
	char	c;
	int		isalpha_result;
	int		ft_isalpha_result;

	tested_func = "ft_isalpha";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);

	c = '0';
	printf("\nchar tested: %c", c);
	isalpha_result = isalpha(c);
	ft_isalpha_result = ft_isalpha(c);

	printf("\nft_isalpha: %i", ft_isalpha_result);	
	printf("\nisalpha: %i\n\n", isalpha_result);	

	c = 'X';
	printf("\nchar tested: %c", c);
	isalpha_result = isalpha(c);
	ft_isalpha_result = ft_isalpha(c);

	printf("\nft_isalpha: %i", ft_isalpha_result);	
	printf("\nisalpha: %i\n\n", isalpha_result);	

	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);
	return (1);
}

//P1-02
int	isdigit_test(void)
{
	char	*tested_func;
	char	c;
	int		isdigit_result;
	int		ft_isdigit_result;

	tested_func = "ft_isdigit";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);

	c = '0';
	printf("\nchar tested: %c", c);
	isdigit_result = isdigit(c);
	ft_isdigit_result = ft_isdigit(c);
	printf("\nft_isdigit: %i", ft_isdigit_result);	
	printf("\nisdigit: %i\n\n", isdigit_result);	

	c = 'X';
	printf("\nchar tested: %c", c);
	isdigit_result = isdigit(c);
	ft_isdigit_result = ft_isdigit(c);
	printf("\nft_isdigit: %i", ft_isdigit_result);	
	printf("\nisdigit: %i\n\n", isdigit_result);	

	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);
	return (1);
}

//P1-03
int	isalnum_test(void)
{
	char	*tested_func;
	char	c;
	int		isalnum_result;
	int		ft_isalnum_result;

	tested_func = "ft_isalnum";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);

	c = '0';
	printf("\nchar tested: %c", c);
	isalnum_result = isalnum(c);
	ft_isalnum_result = ft_isalnum(c);
	printf("\nft_isalnum: %i", ft_isalnum_result);	
	printf("\nisalnum: %i\n\n", isalnum_result);	

	c = 'X';
	printf("\nchar tested: %c", c);
	isalnum_result = isalnum(c);
	ft_isalnum_result = ft_isalnum(c);
	printf("\nft_isalnum: %i", ft_isalnum_result);	
	printf("\nisalnum: %i\n\n", isalnum_result);	

	c = '&';
	printf("\nchar tested: %c", c);
	isalnum_result = isalnum(c);
	ft_isalnum_result = ft_isalnum(c);
	printf("\nft_isalnum: %i", ft_isalnum_result);	
	printf("\nisalnum: %i\n\n", isalnum_result);	

	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);
	return (1);
}

//P1-04
int	isascii_test(void)
{
	char	*tested_func;
	char	c;
	int		isascii_result;
	int		ft_isascii_result;

	tested_func = "ft_isascii";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);

	c = '&';
	printf("\nchar tested: %c", c);
	isascii_result = isascii(c);
	ft_isascii_result = ft_isascii(c);
	printf("\nft_isascii: %i", ft_isascii_result);	
	printf("\nisascii: %i\n\n", isascii_result);	

	c = '\t';
	printf("\nchar tested: %c (\\t)", c);
	isascii_result = isascii(c);
	ft_isascii_result = ft_isascii(c);
	printf("\nft_isascii: %i", ft_isascii_result);	
	printf("\nisascii: %i\n\n", isascii_result);

	c = '\xE7';
	printf("\nchar tested: %c (ç)", c);
	isascii_result = isascii(c);
	ft_isascii_result = ft_isascii(c);
	printf("\nft_isascii: %i", ft_isascii_result);	
	printf("\nisascii: %i\n\n", isascii_result);

	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);
	return (1);
}

//P1-05
int	isprint_test(void)
{
	char	*tested_func;
	char	c;
	int		isprint_result;
	int		ft_isprint_result;

	tested_func = "ft_isprint";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);

	c = '&';
	printf("\nchar tested: %c", c);
	isprint_result = isprint(c);
	ft_isprint_result = ft_isprint(c);
	printf("\nft_isprint: %i", ft_isprint_result);	
	printf("\nisprint: %i\n\n", isprint_result);	

	c = '\t';
	printf("\nchar tested: %c (\\t)", c);
	isprint_result = isprint(c);
	ft_isprint_result = ft_isprint(c);
	printf("\nft_isprint: %i", ft_isprint_result);	
	printf("\nisprint: %i\n\n", isprint_result);	

	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);
	return (1);
}

//P1-06
int	strlen_test(void)
{
	char	*tested_func;
	char	*str;
	int		strlen_result;
	int		ft_strlen_result;

	tested_func = "ft_strlen";
	printf("\033[0;32m\\\\TEST %s\n\033[0m", tested_func);

	str = "Ik spreek geen nederlands";
	printf("\nstring tested: %s\n", str);
	ft_strlen_result = ft_strlen(str);
	strlen_result = strlen(str);
	printf("\nft_strlen result: %d", ft_strlen_result);	
	printf("\nstrlen result: %d", strlen_result);	

	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);
	return (1);
}


//P1-07
int	memset_test(void)
{
	char	*tested_func;
	char	*ft_memset_dest;
	size_t	destsize;
	int		c;
	size_t	n;
	char	*s;

	tested_func = "ft_memset";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);

	destsize = 10;
	ft_memset_dest = malloc(destsize);
	if (!ft_memset_dest)
	{
		printf("Error: memory allocation failed\n");
		return (0);
	}

	//Test 1
	c = 'A';
	n = 3;
	s = "Hello";
	printf("\nTest 1: memset %zu bytes of %s with %c\n", n, s, c);
	ft_memset_dest = ft_memset(s, c, n);
	printf("%s\n",s);
	if (memcmp(s, "AAAlo", strlen("AAAlo")) == 0)
		printf("Test 1 passed\n");
	else
		printf("Test 1 failed\n");

	// Test 2
	c = 0;
	n = 5;
	s = "Hello";
	printf("\nTest 2: memset %zu bytes of %s with null character\n", n, s);
	ft_memset_dest = ft_memset(s, c, n);
	if (memcmp(s, "", strlen("")) == 0)
		printf("Test 2 passed\n");
	else
		printf("Test 2 failed\n");

	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);
	free(s);
	return (1);
}

//P1-08
int bzero_test(void)
{
	char str[] = "Hello, World!";
	size_t len = sizeof(str) - 1;
	
	// Initialize the string with non-zero values
	for (size_t i = 0; i < len; i++) {
		str[i] = 'a';
	}

	// Print the original string
	printf("Original string: %s\n", str);

	// Call ft_bzero to zero out the string
	ft_bzero(str, len);

	// Print the modified string
	printf("Modified string: %s\n", str);

	// Check if the string was zeroed out
	for (size_t i = 0; i < len; i++) {
		if (str[i] != '\0') {
			printf("Error: string not zeroed out\n");
			return (0);
		}
	}
	return (1);
}

//P1-09
int	memcpy_test(void)
{
	char	*tested_func;
	char	*src;
	char	dest[30];
	char	ft_dest[30];
	size_t	size;
	int		result;

	tested_func = "ft_memcpy";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);

	src = "Hello, world!";
	size = strlen(src) + 1;
	result = memcmp(memcpy(dest, src, size), ft_memcpy(ft_dest, src, size), size);
	printf("src: \"%s\"\nsize: %lu\nresult: %d\n", src, size, result);

	src = "Test case 2.";
	size = strlen(src) + 1;
	result = memcmp(memcpy(dest, src, size), ft_memcpy(ft_dest, src, size), size);
	printf("src: \"%s\"\nsize: %lu\nresult: %d\n", src, size, result);

	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);
	return (1);
}


//P1-11
int	strlcpy_test(void)
{
	char	*tested_func;
	char	*str;
	char	*ft_strlcpy_dest;
	size_t	destsize = 0;
	size_t	ft_strlcpy_result = 0;

	tested_func = "ft_strlcpy";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);

	destsize = 5;
	ft_strlcpy_dest = malloc(destsize);
	if (!ft_strlcpy_dest)
	{
		printf("Error: memory allocation failed\n");
		return (0);
	}
	str = "Knock, knock.\nWho's there?\nBoo.\nBoo who?\nDon't cry, it's just a joke!";
	printf("\nstring tested: %s\n\ndestsize: %zu", str, destsize);
	ft_strlcpy_result = ft_strlcpy(ft_strlcpy_dest, str, destsize);
	printf("\nft_strlcpy: %s\nft_strlcpy result: %zu", ft_strlcpy_dest, ft_strlcpy_result);	

	str = "Why was the math book sad? Because it had too many problems.";
	printf("\n\n\nstring tested: %s\n\ndestsize: %zu", str, destsize);
	ft_strlcpy_result = ft_strlcpy(ft_strlcpy_dest, str, destsize);
	printf("\nft_strlcpy: %s\nft_strlcpy result: %zu", ft_strlcpy_dest, ft_strlcpy_result);	

	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);
	free(ft_strlcpy_dest);
	return (1);
}

//P1-12
int	strlcat_test(void)
{
	char	*tested_func;
	char	*ft_strlcat_src;
	char	*ft_strlcat_dest;
	size_t	destsize = 0;
	size_t	ft_strlcat_result = 0;

	tested_func = "ft_strlcat";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);

	destsize = 25;
	ft_strlcat_dest = malloc(destsize);
	if (!ft_strlcat_dest)
	{
		printf("Error: memory allocation failed\n");
		return (0);
	}
	ft_strlcat_dest[0] = '\0'; // initialize ft_strlcat_dest to an empty string
	ft_strlcat_src = "Knock, knock.\n";
	printf("\nstring tested: %s\ndestsize: %zu", ft_strlcat_src, destsize);
	ft_strlcat_result = ft_strlcat(ft_strlcat_dest, ft_strlcat_src, destsize);
	printf("\nft_strlcat_dest: %s\nft_strlcat result: %zu", ft_strlcat_dest, ft_strlcat_result);

	ft_strlcat_src = "Why was the math book sad? Because it had too many problems.";
	printf("\n\n\nstring tested: %s\ndestsize: %zu", ft_strlcat_src, destsize);
	ft_strlcat_result = ft_strlcat(ft_strlcat_dest, ft_strlcat_src, destsize);
	printf("\nft_strlcat_dest: %s\nft_strlcat result: %zu", ft_strlcat_dest, ft_strlcat_result);

	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);
	free(ft_strlcat_dest);
	return (1);
}

//P1-13
int	toupper_test(void)
{
	char	*tested_func;
	char	c;
	int		toupper_result;
	int		ft_toupper_result;

	tested_func = "ft_toupper";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);

	c = '0';
	printf("\nchar tested: %c", c);
	toupper_result = toupper(c);
	ft_toupper_result = ft_toupper(c);
	printf("\nft_toupper: %c", ft_toupper_result);	
	printf("\ntoupper: %c\n\n", toupper_result);	

	c = 'x';
	printf("\nchar tested: %c", c);
	toupper_result = toupper(c);
	ft_toupper_result = ft_toupper(c);
	printf("\nft_toupper: %c", ft_toupper_result);	
	printf("\ntoupper: %c\n\n", toupper_result);	

	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);
	return (1);
}

//P1-14
int	tolower_test(void)
{
	char	*tested_func;
	char	c;
	int		tolower_result;
	int		ft_tolower_result;

	tested_func = "ft_tolower";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);

	c = 'B';
	printf("\nchar tested: %c", c);
	tolower_result = tolower(c);
	ft_tolower_result = ft_tolower(c);
	printf("\nft_tolower: %c", ft_tolower_result);	
	printf("\ntolower: %c\n\n", tolower_result);	

	c = 'x';
	printf("\nchar tested: %c", c);
	tolower_result = tolower(c);
	ft_tolower_result = ft_tolower(c);
	printf("\nft_tolower: %c", ft_tolower_result);	
	printf("\ntolower: %c\n\n", tolower_result);	

	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);
	return (1);
}

//P2-01
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

//P2-02
int	strjoin_test(void)
{
	char	*str1 = "Keep those blurry memories somewhere safe,\n";
	char	*str2 = "You may need them.";
	char	*joined;
	joined = ft_strjoin(str1, str2);
	printf("%s", joined);
	return (1);
}

//P2-08
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

//P2-09
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

//P2-10
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

//P2-11
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

// int striteri_test() {
//	 printf("\\\\TEST ft_striteri\n");
//	 char str[] = "hello world";
//	 printf("Before: %s\n", str);
//	 ft_striteri(str, &test_char_to_upper);
//	 printf("After: %s\n", str);
//	 printf("\\\\END of ft_striteri test\n");
//	 return 1;
// }

// int strmapi_test()
// {
// 	printf("\\\\TEST ft_strmapi\n");
// 	char	*str = "There's no rabbit out the hat.";
// 	printf("string tested: %s\n", str);

// 	char	*result = ft_strmapi(str, &aux_toupper);
	
// 	printf("ft_strmapi: %s\n", result);

// 	printf("\\\\END of ft_strmapi test\n");

// 	free(result);
// 	return (1);
// }

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
