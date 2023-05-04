#include <stdio.h>

int	ft_atoi(char *str);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <string>\n", argv[0]);
		return (1);
	}
	int result = ft_atoi(argv[1]);
	printf("%d\n", result);
	return (0);
}

/*
    sign is initialized to 1, which represents a positive number.
    result is initialized to 0, which will hold the final result of the function.
    The first while loop skips all leading whitespace characters.
    The second while loop handles the plus and minus signs, and updates the sign variable accordingly.
    The third while loop reads all consecutive digits, 
	and updates the result variable by multiplying it by 10 and adding the value of the current digit (after converting it from character to integer).
    The final return statement returns the result multiplied by the sign (to make it negative if there were any minus signs).


	Write a function that converts the initial portion of the string pointed by str to its int
representation
• The string can start with an arbitray amount of white space (as determined by isspace(3))
• The string can be followed by an arbitrary amount of + and - signs, - sign will change
the sign of the int returned based on the number of - is odd or even.
• Finally the string can be followed by any numbers of the base 10.
• Your function should read the string until the string stop following the rules and return
the number found until now.
• You should not take care of overflow or underflow. result can be undefined in that case.
• Here’s an example of a program that prints the atoi return value:
$>./a.out "---+--+1234ab567"
-1234


The characters '\t', '\n', '\v', '\f', and '\r' are called whitespace characters, 
and isspace() function from ctype.h considers all of them as whitespace characters. 
They are used to represent horizontal and vertical spaces,
 as well as line breaks, in the ASCII character set.

Therefore, in the original code, isspace(*str) was used to skip all whitespace characters, 
which includes space (' '), tab ('\t'), newline ('\n'), vertical tab ('\v'), form feed ('\f'), and carriage return ('\r'). 
Since the task is to implement the function without using isspace(), 
the condition (*str >= '\t' && *str <= '\r') is used to check for these characters manually.
*/