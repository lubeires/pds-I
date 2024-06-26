#include <stdio.h>

int bissexto(int ano)
{
    int resultado = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0) ? 1 : 0;
    return resultado;
}

int main()
{
    int ano;
    while (scanf("%d", &ano) != EOF)
        printf("%d\n", bissexto(ano));
    return 0;
}