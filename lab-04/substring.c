#include <stdio.h>
#include <string.h>
#define TAM 30

int main()
{
    char s1[TAM], s2[TAM];
    fgets(s1, TAM, stdin);
    fgets(s2, TAM, stdin);
    s2[strcspn(s2, "\n")] = 0;
    if (strstr(s1, s2))
        printf("É substring\n");
    else
        printf("Não é substring\n");
    return 0;
}