#include <stdio.h>

int primo(int num)
{
    for (int i = 2; i <= num / 2; i++)
        if (num % i == 0)
            return 0;
    return 1;
}

void primos(int m, int *p1, int *p2)
{
    int i;
    if (m == 2)
        *p1 = m;
    else
    {
        i = m - 1;
        while (!primo(i))
            i--;
        *p1 = i;
    }

    i = m + 1;
    while (!primo(i))
        i++;
    *p2 = i;
}

int main()
{
    int m, p1 = 0, p2 = 0;
    scanf("%d", &m);
    primos(m, &p1, &p2);
    printf("%d\n%d\n", p1, p2);
    return 0;
}