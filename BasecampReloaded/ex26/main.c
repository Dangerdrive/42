#include <stdio.h>

int ft_count_if(char **tab, int(*f)(char*));

int is_uppercase(char* str)
{
    if (*str == '\0')
    {
        return 0;
    }
    while (*str != '\0')
    {
        if (*str < 'A' || *str > 'Z')
        {
            return 0;
        }
        str++;
    }
    return 1;
}

int main(void)
{
    char *tab[] = {"HELLO", "WORLD", "123", "", NULL};
    int count = ft_count_if(tab, &is_uppercase);
    printf("Number of uppercase strings in the array: %d\n", count);
    return 0;
}