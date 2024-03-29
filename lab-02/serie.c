#include <stdio.h>

int main() {
    int n, x0, x1, aux;
    scanf("%d %d %d", &n, &x0, &x1);
    printf("x0: %d\n", x0);
    printf("x1: %d\n", x1);
    for (int i = 2; i <= n; i++) {
        aux = x1;
        x1 = 4 * x1 - 2 * x0;
        x0 = aux;
        printf("x%d: %d\n", i, x1);    
    }
    return 0;
}