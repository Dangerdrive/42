#include <stdio.h>

int main() {
    int x, y;
    printf("Enter width of rectangle: ");
    scanf("%d", &x);
    printf("Enter length of rectangle: ");
    scanf("%d", &y);

    for(int i = 1; i <= y; i++) {
        for(int j = 1; j <= x; j++) {
            if(i == 1 && j == 1) {
                printf("/");
            } else if(i == 1 && j == x) {
                printf("\\");
            } else if(i == y && j == 1) {
                printf("\\");
            } else if(i == y && j == x) {
                printf("/");
            } else if(i == (y+1)/2 && j == (x+1)/2) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}
