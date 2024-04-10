#define TAM 800
#include <stdio.h>

int main()
{
    int n, fib[TAM];
    fib[0] = 0;
    fib[1] = 1;
    do
    {
        scanf("%d", &n);
        if (n < 0 || n > TAM)
            return 1;
        for (int i = 2; i <= n; i++)
            fib[i] = fib[i - 1] + fib[i - 2];
        printf("%d\n", fib[n]);
    } while (n >= 0);
    return 0;
}