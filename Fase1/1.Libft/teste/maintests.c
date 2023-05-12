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
	//memcpy_test();
	//memmove_test();
	// strlcpy_test(); //11
	strlcat_test(); //12  arrumar
	//toupper_test(); //13
	//tolower_test(); //14

	//split_test();
	//itoa_test();
	//strmapi_test();
	//striteri_test();
	//strjoin_test();
	//substr_test();
	//putchar_fd_test();
	//putstr_fd_test();
	//putnbr_fd_test();
	//putendl_fd_test();
	//strchr_test();
	//strrchr_test();
	//strncmp_test();
	//memchr_test();
	//memcmp_test();
	//atoi_test();
	//calloc_test();
	//strdup_test();

	//striteri_test();
	//strtrim_test()


	//lstnew_test();
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

//P1-10
int	memmove_test(void)
{
	char	*tested_func;
	char	*src;
	char	dest[30];
	char	ft_dest[30];
	size_t	size;
	int		result;

	tested_func = "ft_memmove";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);

	src = "Hello, world!";
	size = strlen(src) + 1;
	result = memcmp(memmove(dest, src, size), ft_memmove(ft_dest, src, size), size);
	printf("src: \"%s\"\nsize: %lu\nresult: %d\n", src, size, result);

	src = "Test case 2.";
	size = strlen(src) + 1;
	result = memcmp(memmove(dest, src, size), ft_memmove(ft_dest, src, size), size);
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

#define BUFFER_SIZE 50

int	strlcat_test(void)
{
	char dst[BUFFER_SIZE] = "Hello, ";
	const char *src = "world!";
	size_t expected, result1, result2;

	// Test ft_strlcat
	expected = strlcat(dst, src, BUFFER_SIZE);
	result1 = ft_strlcat(dst, src, BUFFER_SIZE);
	if (expected != result1)
	{
		printf("ft_strlcat test failed: expected %zu, but got %zu\n", expected, result1);
		return 1;
	}

	// Test strlcat
	char dst2[BUFFER_SIZE] = "Hello, ";
	expected = strlcat(dst2, src, BUFFER_SIZE);
	result2 = strlcat(dst2, src, BUFFER_SIZE);
	if (expected != result2)
	{
		printf("strlcat test failed: expected %zu, but got %zu\n", expected, result2);
		return 1;
	}

	// Compare results
	if (memcmp(dst, dst2, BUFFER_SIZE) != 0)
	{
		printf("Results differ: ft_strlcat: \"%s\", strlcat: \"%s\"\n", dst, dst2);
		return 1;
	}

	printf("ft_strlcat test succeeded\n");
	return 0;
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
//P1-15
int strchr_test(void)
{
	char	*tested_func;
	char	*str;
	int		c;
	char	*ft_strchr_result;
	char	*strchr_result;
		
	tested_func = "ft_strchr";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);
		
	str = "test string, no jokes";
	c = 'j';
	printf("\nstring tested: %s\ncharacter tested: %c", str, c);
	ft_strchr_result = ft_strchr(str, c);
	strchr_result = strchr(str, c);
	printf("\nft_strchr result: %s", ft_strchr_result);
	printf("\nstrchr result: %s", strchr_result);
	if (ft_strchr_result != strchr_result)
	{
		printf("\n\033[0;31mError: result doesn't match the expected value\033[0m\n");
		return (0);
	}
		
	str = "tripouille";
	c = 't' + 256;
	printf("\n\n\nstring tested: %s\ncharacter tested: %c", str, c);
	ft_strchr_result = ft_strchr(str, c);
	strchr_result = strchr(str, c);
	printf("\nft_strchr result: %s", ft_strchr_result);
	printf("\nstrchr result: %s", strchr_result);
	if (ft_strchr_result != strchr_result)
	{
		printf("\n\033[0;31mError: result doesn't match the expected value\033[0m\n");
		return (0);
	}
		
	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);
	return (1);
}
//P1-16
int strrchr_test(void)
{
	char *tested_func;
	char *str;
	int c;
	char *ft_strrchr_result;
	char *strrchr_result;

	tested_func = "ft_strrchr";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);

	str = "kripouille";
	c = 't' + 256;
	printf("\nstring tested: %s\ncharacter tested: %c", str, c);
	ft_strrchr_result = ft_strrchr(str, c);
	strrchr_result = strrchr(str, c);
	printf("\nft_strrchr result: %s", ft_strrchr_result);
	printf("\nstrrchr result: %s", strrchr_result);
	if (ft_strrchr_result != strrchr_result)
	{
		printf("\n\033[0;31mError: result doesn't match the expected value\033[0m\n");
		return (0);
	}

	str = "Goodbye World!";
	c = 'o';
	printf("\n\n\nstring tested: %s\ncharacter tested: %c", str, c);
	ft_strrchr_result = ft_strrchr(str, c);
	strrchr_result = strrchr(str, c);
	printf("\nft_strrchr result: %s", ft_strrchr_result);
	printf("\nstrrchr result: %s", strrchr_result);
	if (ft_strrchr_result != strrchr_result)
	{
		printf("\n\033[0;31mError: result doesn't match the expected value\033[0m\n");
		return (0);
	}

	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);
	return (1);
}


//P1-17
int strncmp_test()
{
	char *str1 = "Hello, world!";
	char *str2 = "Hello";
	int result;
	int expected_result;
	unsigned int n;

	n = 5;

	// Test 1
	expected_result = strncmp(str1, str2, n);
	result = ft_strncmp(str1, str2, n);
	if (result != expected_result)
		printf("Test 1 failed: expected %d, got %d\n", expected_result, result);
	else
		printf("Test 1 succeeded!\n");

	// Test 2
	expected_result = strncmp(str1, str2, n);
	result = ft_strncmp(str2, str1, n);
	if (result != -expected_result)
		printf("Test 2 failed: expected %d, got %d\n", -expected_result, result);
	else
		printf("Test 2 succeeded!\n");

	// Test 3
	expected_result = strncmp(str1, str2, n + 1);
	result = ft_strncmp(str1, str2, n + 1);
	if (result != expected_result)
		printf("Test 3 failed: expected %d, got %d\n", expected_result, result);
	else
		printf("Test 3 succeeded!\n");

	return (0);
}

//P1-19
int memchr_test(void)
{
	char *tested_func = "ft_memchr";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);
		
	char str[] = "Hello, world!";
	char *result1, *result2;
	int c = 'o';

	// Using the standard library function to compare results
	result1 = memchr(str, c, strlen(str));
	result2 = ft_memchr(str, c, strlen(str));

	printf("Tested string: %s\n", str);
	printf("Using memchr:\n");
	printf("Result: %s\n", result1);
	printf("Using ft_memchr:\n");
	printf("Result: %s\n", result2);

printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);
	return (1);
}

int memcmp_test(void)
{
	char *tested_func = "ft_memchr";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);
    const char *s1 = "abcde";
    const char *s2 = "abcde";
    size_t n = strlen(s1);

    int cmp1 = memcmp(s1, s2, n);
    int cmp2 = ft_memcmp(s1, s2, n);

    printf("memcmp result: %d\n", cmp1);
    printf("ft_memcmp result: %d\n", cmp2);

	s1 = "abz";
	s2 = "abcde";
    cmp1 = memcmp(s1, s2, n);
    cmp2 = ft_memcmp(s1, s2, n);

    printf("memcmp result: %d\n", cmp1);
    printf("ft_memcmp result: %d\n", cmp2);

	s1 = "abz";
	s2 = "zsfsdfs";
    cmp1 = memcmp(s1, s2, n);
    cmp2 = ft_memcmp(s1, s2, n);

    printf("memcmp result: %d\n", cmp1);
    printf("ft_memcmp result: %d\n", cmp2);


    return 1;

	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);
}

//P1-20
int	strnstr_test(void)
{
	char *tested_func = "ft_strnstr";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);
		
	char haystack[] = "Hello, world!";
	char needle[] = "world";
	char /**result1, */*result2;
	size_t len = strlen(haystack);

	// Using the standard library function to compare results
	//result1 = strnstr(haystack, needle, len);
	result2 = ft_strnstr(haystack, needle, len);

	printf("Haystack: %s\n", haystack);
	printf("Needle: %s\n", needle);
	printf("Length: %zu\n", len);
	//printf("Using strnstr:\n");
   // printf("Result: %s\n", result1);
	printf("Using ft_strnstr:\n");
	printf("Result: %s\n", result2);

	printf("\n");

	// Testing with needle longer than haystack
	char haystack2[] = "world";
	char needle2[] = "Hello, world!";
	len = strlen(haystack2);

	// Using the standard library function to compare results
	//result1 = strnstr(haystack2, needle2, len);
	result2 = ft_strnstr(haystack2, needle2, len);

	printf("Haystack: %s\n", haystack2);
	printf("Needle: %s\n", needle2);
	printf("Length: %zu\n", len);
	//printf("Using strnstr:\n");
	//printf("Result: %s\n", result1);
	printf("Using ft_strnstr:\n");
	printf("Result: %s\n", result2);

	printf("\n");

	// Testing with needle length 0
	char haystack3[] = "Hello, world!";
	char needle3[] = "";
	len = strlen(haystack3);

	// Using the standard library function to compare results
	//result1 = strnstr(haystack3, needle3, len);
	result2 = ft_strnstr(haystack3, needle3, len);

	printf("Haystack: %s\n", haystack3);
	printf("Needle: %s\n", needle3);
	printf("Length: %zu\n", len);
	//printf("Using strnstr:\n");
	//printf("Result: %s\n", result1);
	printf("Using ft_strnstr:\n");
	printf("Result: %s\n", result2);

	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);
	return (0);
}

//P1-21

int	atoi_test(void)
{
	char *tested_func = "ft_atoi";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);
	char *str1 = "1234";
	char *str2 = "-5678";
	char *str3 = "9223499999999999999";
	char *str4 = "2147483647";
	char *str5 = "-2147483648";
	char *str6 = "12abc34";
	char *str7 = "  \t  123   ";
	char *str8 = "  \t  -456   ";
	char *str9 = "  \t  +789   ";
	char *str10 = "";
	char *str11 = "   ";
	char *str12 = "+-123";
	char *str13 = "1234 5678";
	char *str14 = "1234abc";
	char *str15 = "abc1234";
		
	printf("ft_atoi: %d\n", ft_atoi(str1));  // 1234
	printf("atoi: %d\n", atoi(str1));  // 1234
	printf("ft_atoi: %d\n", ft_atoi(str2));  // -5678
	printf("atoi: %d\n", atoi(str2));  // -5678
	printf("ft_atoi: %d\n", ft_atoi(str3));  // 99999999999999999999999999999
	printf("atoi: %d\n", atoi(str3));  // 2147483647
	printf("ft_atoi: %d\n", ft_atoi(str4));  // 2147483647
	printf("atoi: %d\n", atoi(str4));  // 2147483647
	printf("ft_atoi: %d\n", ft_atoi(str5));  // -2147483648
	printf("atoi: %d\n", atoi(str5));  // -2147483648
	printf("ft_atoi: %d\n", ft_atoi(str6));  // 12
	printf("atoi: %d\n", atoi(str6));  // 12
	printf("ft_atoi: %d\n", ft_atoi(str7));  // 123
	printf("atoi: %d\n", atoi(str7));  // 123
	printf("ft_atoi: %d\n", ft_atoi(str8));  // -456
	printf("atoi: %d\n", atoi(str8));  // -456
	printf("ft_atoi: %d\n", ft_atoi(str9));  // 789
	printf("atoi: %d\n", atoi(str9));  // 789
	printf("ft_atoi: %d\n", ft_atoi(str10)); // 0
	printf("atoi: %d\n", atoi(str10)); // 0
	printf("ft_atoi: %d\n", ft_atoi(str11)); // 0
	printf("atoi: %d\n", atoi(str11)); // 0
	printf("ft_atoi: %d\n", ft_atoi(str12)); // -123
	printf("atoi: %d\n", atoi(str12)); // -123
	printf("ft_atoi: %d\n", ft_atoi(str13)); // 1234
	printf("atoi: %d\n", atoi(str13)); // 1234
	printf("ft_atoi: %d\n", ft_atoi(str14)); // 1234
	printf("atoi: %d\n", atoi(str14)); // 1234
	printf("ft_atoi: %d\n", ft_atoi(str15)); // 0
	printf("atoi: %d\n", atoi(str15)); // 0


	printf("atoi: %d\n", atoi("-9223372036854775807"));
	printf("ft_atoi: %d\n",ft_atoi("-9223372036854775807"));
	printf("atoi: %d\n", atoi("-9223372036854775808"));
	printf("ft_atoi: %d\n", ft_atoi("-9223372036854775808"));
	printf("atoi: %d\n", atoi("-9223372036854775809"));
	printf("ft_atoi: %d\n", ft_atoi("-9223372036854775809"));


		
	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);

	return (0);
}

//P1-21

int	calloc_test(void)
{
	char *tested_func = "ft_calloc";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);
	
	char	*str;

	str = (char *)ft_calloc(10, sizeof(char));
	if (str == NULL)
	{
		printf("Allocation failed\n");
		return (0);
	}

	// The memory should be zero-initialized
	if (strcmp(str, "") != 0)
	{
		printf("Memory not initialized to zero\n");
		free(str);
		return (0);
	}

	// Change the first character
	str[0] = 'A';

	// Make sure the rest of the string is still zero
	if (strcmp(str + 1, "") != 0)
	{
		printf("Memory not initialized to zero\n");
		free(str);
		return (0);
	}
	printf("%s", str);
	free(str);

	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);

	return (1);
}
//P1-23
int	strdup_test(void)
{
	char *tested_func = "ft_strdup";
	printf("\033[0;32m\\\\TEST %s\n\n\033[0m", tested_func);

	char	*str1 = "Hello, world!";
	char	*str2;

	str2 = ft_strdup(str1);
	if (str2 == NULL)
	{
		printf("Error: ft_strdup failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);

	free(str2);

	printf("\033[0;32m\n\\\\END of %s test\n\033[0m", tested_func);

	return (0);
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

	sub_str = ft_substr("tripouille", 0, 42000);
	printf("trip substring:%s\n", sub_str);

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

//P2-03
int	split_test(void)
{
	char	**result;
	char	*str = "This is a test string for ft_split";

	result = ft_split(str, ' ');
	if (!result)
		return (1);
	for (int i = 0; result[i]; i++)
		printf("%s\n", result[i]);
	free(result);
	return (0);
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

	int	num_test = -2147483648;

	ft_putstr_fd("ft_putstr_fd:\t", 1);
	//printf("%s:", tested_func);
	ft_putnbr_fd(num_test, 1);
	printf("\nprintf:\t\t%i\n", num_test);


	printf("\n\\\\END of %s test\n", tested_func);
	return (1);
}




void	apply_func(unsigned int i, char *c)
{
	*c = *c + i;
}

int	ft_striteri_test(void)
{
	char	str[] = "hello";
	char	expected_str[] = "hfnos";
	
	ft_striteri(str, &apply_func);
	if (strcmp(str, expected_str) != 0)
	{
		printf("Error: result string does not match expected string.\n");
		return (0);
	}
	return (1);
}

int	striteri_test(void)
{
	if (ft_striteri_test())
		printf("ft_striteri test passed.\n");
	else
		printf("ft_striteri test failed.\n");
	return (0);
}





// int strmapi_test()
// {
// 	printf("\\\\TEST ft_strmapi\n");
// 	char	*str = "There's no rabbit out the hat.";
// 	printf("string tested: %s\n", str);

// 	char	*result = ft_strmapi(str, &apply_func);
	
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
	int		num = __INT_MAX__;
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

//PB-01
int lstnew_test()
{
	int content = 42;
	t_list *node = ft_lstnew(&content);

	printf("content: %d\n", *(int *)node->content);
	printf("next: %p\n", node->next);

	free(node);
	return (0);
}
