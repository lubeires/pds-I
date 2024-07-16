#include <stdio.h>
#define TAM_STR 100

typedef struct
{
    int dia;
    enum
    {
        JAN = 1,
        FEV,
        MAR,
        ABR,
        MAI,
        JUN,
        JUL,
        AGO,
        SET,
        OUT,
        NOV,
        DEZ
    } mes;
    int ano;
} DATA;

typedef struct
{
    char nome[TAM_STR];
    char local[TAM_STR];
    DATA data;
} EVENTO;

void cadastrar_eventos(EVENTO agenda[], int n)
{
    for (int i = 0; i < n; i++)
    {
        EVENTO *e = agenda + i;
        scanf("%s %s %d %d %d", e->nome, e->local, &(e->data.dia), &(e->data.mes), &(e->data.ano));
    }
}

void imprimir_eventos(EVENTO agenda[], DATA d, int n)
{
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        EVENTO *e = agenda + i;
        if (e->data.dia == d.dia && e->data.mes == d.mes && e->data.ano == d.ano)
        {
            printf("%s %s\n", e->nome, e->local);
            cont++;
        }
    }
    if (!cont)
        printf("Nenhum evento encontrado!\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    EVENTO agenda[n];
    cadastrar_eventos(agenda, n);
    DATA data;
    scanf("%d %d %d", &(data.dia), &(data.mes), &(data.ano));
    imprimir_eventos(agenda, data, n);
    return 0;
}
