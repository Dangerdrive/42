#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str);
int	*ft_range(int min, int max);

int main() {
    int *arr;
    int min = -35;
    int max = 5;

    arr = ft_range(min, max);
    if (arr == NULL) {
        printf("Error: ft_range returned NULL\n");
        return 1;
    }

    int n = max - min;
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}