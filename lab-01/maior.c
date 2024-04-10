#include <stdio.h>

int main()
{
    int a, b, c, maior;
    scanf("%d\n", &a);
    scanf("%d\n", &b);
    scanf("%d\n", &c);
    maior = a > b ? (a > c ? a : c) : (b > c ? b : c);
    printf("%d\n", maior);
    return 0;
}