#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main() {
    int x, y;
    char print[] = "Enter width of rectangle: ";
    int i = 0;
    while (print[i] != '\0') {
        ft_putchar(print[i]);
        i++;
        scanf("%d", &x);
    printf("Enter length of rectangle: ");
    scanf("%d", &y);

    for(int i=1; i<=y; i++) {
        for(int j=1; j<=x; j++) {
            ft_putchar('*');
        }
        printf("\n");
    }
    return 0;
}
}