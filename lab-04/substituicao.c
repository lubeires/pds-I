#include <stdio.h>
#include <string.h>
#define TAM 30

int main()
{
    char s[TAM], c1, c2;
    fgets(s, TAM, stdin);
    scanf("%c", &c1);
    getchar();
    scanf("%c", &c2);
    char *p = strchr(s, c1);
    if (p)
        p[0] = c2;
    printf("%s", s);
    return 0;
}