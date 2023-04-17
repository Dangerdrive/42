#include <stdio.h>

void ft_swap(int *a, int *b);

int main() {
    int x = 10;
    int y = 20;

    printf("Before swap: x = %d, y = %d\n", x, y);

    ft_swap(&x, &y);

    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}
