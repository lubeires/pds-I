#include <stdio.h>
#include <string.h>
#define TAM_ARR 8
#define TAM_STR 50

typedef struct
{
    char nome[TAM_STR];
    char marca[TAM_STR];
    float preco;
} produto;

typedef struct
{
    char nome[TAM_STR];
    unsigned int qtd;
    float valor;
} marca;

int main()
{
    produto produtos[TAM_ARR];
    marca marcas[TAM_ARR];
    int cont_marcas, qtd_total;
    float valor_total;
    cont_marcas = qtd_total = valor_total = 0;

    for (int i = 0; i < TAM_ARR; i++)
    {
        produto *p = &produtos[i];
        scanf("%s %s %f", (*p).nome, (*p).marca, &((*p).preco));
        qtd_total++;
        valor_total += (*p).preco;

        int j = 0;
        for (; j < cont_marcas; j++)
        {
            if (strcmp((*p).marca, marcas[j].nome) == 0)
            {
                marcas[j].qtd++;
                marcas[j].valor += (*p).preco;
                break;
            }
        }
        if (j == cont_marcas)
        {
            strcpy(marcas[j].nome, (*p).marca);
            marcas[j].qtd = 1;
            marcas[j].valor = (*p).preco;
            cont_marcas++;
        }
    }

    for (int i = 0; i < cont_marcas; i++)
        printf("%s %d\n", marcas[i].nome, marcas[i].qtd);

    printf("media total %.2f\n", (valor_total / qtd_total));

    for (int i = 0; i < cont_marcas; i++)
        printf("media %s %.2f\n", marcas[i].nome, marcas[i].valor / marcas[i].qtd);

    return 0;
}
