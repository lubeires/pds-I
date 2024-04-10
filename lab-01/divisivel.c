#include <stdio.h>

int main()
{
    int x, y, z, divisivel;
    scanf("%d\n", &x);
    scanf("%d\n", &y);
    scanf("%d\n", &z);
    divisivel = x % y == 0 && x % z == 0;
    if (divisivel)
        printf("O número é divisível.\n");
    else
        printf("O número não é divisível.\n");
    return 0;
}