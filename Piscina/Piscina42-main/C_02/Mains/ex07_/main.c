#include <stdio.h>

char	*ft_strupcase(char *dest, char *src);

int main() {
    char src[] = "Hello, world!";
    char dest[20]; // make sure dest has enough space to hold src
    
    ft_strupcase(dest, src);
    
    printf("src: %s\n", src);
    printf("dest: %s\n", dest);
    
    return 0;
}