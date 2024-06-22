#include <stdio.h>
#include <string.h>
#define TAM_ARR 5
#define TAM_STR 50

typedef struct
{
    char rua[TAM_STR];
    unsigned int numero;
    char estado[TAM_STR];
} endereco;

typedef struct
{
    char nome[TAM_STR];
    unsigned int idade;
    float salario;
    endereco endereco;
} pessoa;

pessoa pessoas[TAM_ARR];

void ler() {}

void inserir(int pos)
{
    if (pos < TAM_ARR)
    {
        pessoa *p = &pessoas[pos];
        scanf("%s %u %f %s %u %s", (*p).nome, &((*p).idade), &((*p).salario), (*p).endereco.rua, &((*p).endereco.numero), (*p).endereco.estado);
        printf("Registro %s %u %.2f %s %u %s inserido\n", (*p).nome, (*p).idade, (*p).salario, (*p).endereco.rua, (*p).endereco.numero, (*p).endereco.estado);
    }
    else
        printf("Espaco insuficiente\n");
}

pessoa *buscar(char *nome)
{
    int i = 0;
    for (; i < TAM_ARR; i++)
    {
        pessoa *p = &pessoas[i];
        if (strcmp((*p).nome, nome) == 0)
            return p;
    }
    return NULL;
}

void mostrar(char *nome)
{
    pessoa *p = buscar(nome);
    if (p)
        printf("Registro %s %u %.2f %s %u %s\n", (*p).nome, (*p).idade, (*p).salario, (*p).endereco.rua, (*p).endereco.numero, (*p).endereco.estado);
    else
        printf("Registro ausente\n");
}

void alterar()
{
    pessoa p_alt;
    scanf("%s %u %f %s %u %s", p_alt.nome, &p_alt.idade, &p_alt.salario, p_alt.endereco.rua, &p_alt.endereco.numero, p_alt.endereco.estado);
    pessoa *p = buscar(p_alt.nome);
    if (p)
    {
        *p = p_alt;
        printf("Registro %s %u %.2f %s %u %s alterado\n", (*p).nome, (*p).idade, (*p).salario, (*p).endereco.rua, (*p).endereco.numero, (*p).endereco.estado);
    }
    else
        printf("Registro ausente para alteracao\n");
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
        else if (strcmp(operacao, "alterar") == 0)
            alterar();
        else
            continue;
    }

    return 0;
}
