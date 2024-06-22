#include <stdio.h>
#include <string.h>
#define TAM_ARR 4
#define TAM_STR 50

typedef struct
{
    char nome[TAM_STR];
    unsigned int idade;
    float salario;
} pessoa;

pessoa pessoas[TAM_ARR];

void inserir(int pos)
{
    if (pos < TAM_ARR)
    {
        pessoa *p = &pessoas[pos];
        scanf("%s %u %f", (*p).nome, &((*p).idade), &((*p).salario));
        printf("Registro %s %u %.2f inserido\n", (*p).nome, (*p).idade, (*p).salario);
    }
    else
        printf("Espaco insuficiente\n");
}

void mostrar(char *nome)
{
    int i = 0;
    for (; i < TAM_ARR; i++)
    {
        pessoa p = pessoas[i];
        if (strcmp(p.nome, nome) == 0)
        {
            printf("Registro %s %u %.2f\n", p.nome, p.idade, p.salario);
            break;
        }
    }
    if (i == TAM_ARR)
        printf("Registro ausente\n");
}

int main()
{
    char operacao[TAM_STR];
    int cont = 0;
    char nome[TAM_STR];
    while (scanf("%s", operacao) != EOF)
    {
        if (strcmp(operacao, "inserir") == 0)
            inserir(cont++);
        else if (strcmp(operacao, "mostrar") == 0)
        {
            scanf("%s", nome);
            mostrar(nome);
        }
        else
            continue;
    }

    return 0;
}
