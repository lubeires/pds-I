#include <stdio.h>

int primo(unsigned long int num)
{
    if (num < 2)
        return -1;
    else
    {
        for (unsigned long int i = 2; i <= num / 2; i++)
            if (num % i == 0)
                return 0;
        return 1;
    }
}

int main()
{
    unsigned long int num;
    while (scanf("%lu", &num) != EOF)
        printf("%d\n", primo(num));

    return 0;
}