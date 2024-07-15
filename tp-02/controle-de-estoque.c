#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char codigo[10];
    char nome[100];
    unsigned int quantidade;
    float preco;
    char estado[3];
} PRODUTO;

int ler_produtos(const char *nome, PRODUTO *produtos)
{
    int quantidade;
    FILE *entrada = fopen(nome, "r");
    if (!entrada)
    {
        printf("Arquivo invalido.");
        return EXIT_FAILURE;
    }
    fscanf(entrada, "%d", &quantidade);
    for (int i = 0; i < quantidade; i++)
    {
        PRODUTO *p = produtos + i;
        fscanf(entrada, "%s\n", p->codigo);
        fgets(p->nome, 100, entrada);
        p->nome[strcspn(produtos[i].nome, "\n")] = '\0';
        fscanf(entrada, "%u\n", &p->quantidade);
        fscanf(entrada, "%f\n", &p->preco);
        fscanf(entrada, "%s\n", p->estado);
    }
    fclose(entrada);
    return quantidade;
}

void exibir_produto(PRODUTO *p)
{
    printf("%s\n%s\n%d\n%.2f\n%s\n", p->codigo, p->nome, p->quantidade, p->preco, p->estado);
}

void ordenar(PRODUTO *produtos, int quantidade)
{
    PRODUTO *p = produtos;
    for (int i = 0; i < quantidade - 1; i++)
        for (int j = i + 1; j < quantidade; j++)
            if (strcmp((p + i)->nome, (p + j)->nome) > 0)
            {
                PRODUTO temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
}

void gerar_relatorio(const char *nome, PRODUTO *produtos, int quantidade)
{
    FILE *saida = fopen(nome, "w");
    ordenar(produtos, quantidade);
    PRODUTO *p = produtos;
    for (int i = 0; i < quantidade; i++)
    {
        fprintf(saida, "%s\n%s\n%d\n%.2f\n%s\n", p->codigo, p->nome, p->quantidade, p->preco, p->estado);
        p++;
    }
    fclose(saida);
}

void buscar_por_codigo(const char *codigo, PRODUTO *produtos, int quantidade)
{
    PRODUTO *p = produtos;
    for (int i = 0; i < quantidade; i++)
    {
        if (strcmp((p + i)->codigo, codigo) == 0)
        {
            exibir_produto(p + i);
            break;
        }
    }
}

void buscar_menor_quantidade(PRODUTO *produtos, int quantidade)
{
    PRODUTO *menor = produtos;
    for (int i = 0; i < quantidade; i++)
    {
        if (produtos[i].quantidade < menor->quantidade)
            menor = produtos + i;
    }
    exibir_produto(menor);
}

void buscar_por_estado(const char *estado, PRODUTO *produtos, int quantidade)
{
    ordenar(produtos, quantidade);
    for (int i = 0; i < quantidade; i++)
        if (strcmp(produtos[i].estado, estado) == 0)
            exibir_produto(produtos + i);
}

void buscar_menor_quantidade_por_estado(const char *estado, PRODUTO *produtos, int quantidade)
{
    PRODUTO *menor;
    for (int i = 0; i < quantidade; i++)
        if (strcmp(produtos[i].estado, estado) == 0)
        {
            menor = produtos + i;
            break;
        }

    for (int i = 0; i < quantidade; i++)
        if (strcmp(produtos[i].estado, estado) == 0 && produtos[i].quantidade < menor->quantidade)
            menor = produtos + i;

    exibir_produto(menor);
}

void calcular_quantidade_total(PRODUTO *produtos, int quantidade)
{
    unsigned int total = 0;
    PRODUTO *p = produtos;
    for (int i = 0; i < quantidade; i++)
        total += (p + i)->quantidade;
    printf("%u\n", total);
}

int main(int argc, char const *argv[])
{
    PRODUTO produtos[1000];
    const char *nome = argv[1];
    int quantidade = ler_produtos(nome, produtos);
    int funcao = atoi(argv[2]);
    const char *parametro = argc == 4 ? argv[3] : NULL;
    switch (funcao)
    {
    case 1:
        gerar_relatorio(parametro, produtos, quantidade);
        break;
    case 2:
        buscar_por_codigo(parametro, produtos, quantidade);
        break;
    case 3:
        buscar_menor_quantidade(produtos, quantidade);
        break;
    case 4:
        buscar_por_estado(parametro, produtos, quantidade);
        break;
    case 5:
        buscar_menor_quantidade_por_estado(parametro, produtos, quantidade);
        break;
    case 6:
        calcular_quantidade_total(produtos, quantidade);
        break;
    default:
        break;
    }
    return EXIT_SUCCESS;
}
