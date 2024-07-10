#include <stdio.h>

int main()
{
    FILE *arquivo;
    char c, nome[10];
    int cont_a = 0;
    scanf("%s", nome);
    arquivo = fopen(nome, "rb");
    while ((c = fgetc(arquivo)) != EOF)
        cont_a += (c == 'a');
    printf("%d", cont_a);
    fclose(arquivo);
    return 0;
}
