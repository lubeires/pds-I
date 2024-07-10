#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *arquivo;
    char c;
    int cont_a = 0;
    arquivo = fopen(argv[1], "r");
    while ((c = fgetc(arquivo)) != EOF)
        cont_a += (c == 'a');
    printf("%d", cont_a);
    fclose(arquivo);
    return 0;
}
