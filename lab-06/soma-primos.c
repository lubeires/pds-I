#include <stdio.h>

int primo(unsigned long int num)
{
    for (unsigned long int i = 2; i <= num / 2; i++)
        if (num % i == 0)
            return 0;
    return 1;
}

unsigned long int soma_primos(unsigned long int num)
{
    unsigned long long int cont = 0, i = 2, soma = 0;
    while (cont < num)
    {
        if (primo(i))
        {
            soma += i;
            cont++;
        }
        i++;
    }
    return soma;
}

int main()
{
    unsigned long int num;
    while (scanf("%lu", &num) != EOF)
        printf("%lu\n", soma_primos(num));

    return 0;
}