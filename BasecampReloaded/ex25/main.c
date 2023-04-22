#include <stdio.h>

void	ft_foreach(int *tab, int length, void (*f)(int));

void printnbr(int n)
{
    printf("%d ", n);
}
void printnbrplus(int n)
{
    n += 1;
    printf("%d ", n);
}

int main()
{
    int t_tab[] = {1, 2, 3, 4, 5};
    int t_length = sizeof(t_tab) / sizeof(t_tab[0]);
    ft_foreach(t_tab, t_length, &printnbr); // prints "1 2 3 4 5"
    ft_foreach(t_tab, t_length, &printnbrplus);
    return 0;
}