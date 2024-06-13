#include <stdio.h>
#include <string.h>
#define TAM 30

int main()
{
    char s1[TAM], s2[TAM];
    fgets(s1, TAM, stdin);
    fgets(s2, TAM, stdin);
    s1[strcspn(s1, "\n")] = 0;
    printf("%s", strcat(s1, s2));
    return 0;
}