#define TAM 10
#include <stdio.h>

int main()
{
    int i, x[TAM];
    for (i = 0; i < TAM; i++)
        scanf("%d", &x[i]);
    for (i = TAM - 1; i >= 0; i--)
        printf("%d\n", x[i]);
    return 0;
}