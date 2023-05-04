#include <stdio.h>

int main() {
    int x, y;
    printf("Enter width of rectangle: ");
    scanf("%d", &x);
    printf("Enter length of rectangle: ");
    scanf("%d", &y);

    for(int i=1; i<=y; i++) {
        for(int j=1; j<=x; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
