#include <stdio.h>
#include <string.h>
#define TAM 30

int main()
{
    char str[TAM], temp;
    int tam, dir, esq;
    fgets(str, TAM, stdin);
    tam = strlen(str) - 1;
    dir = tam - 1;
    for (esq = 0; esq <= dir; esq++)
    {
        temp = str[esq];
        str[esq] = str[dir];
        str[dir--] = temp;
    }
    printf("%s", str);
    return 0;
}