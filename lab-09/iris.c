#include <stdio.h>
#include <math.h>
#include <string.h>
#define TAM_STR 50

typedef struct
{
    float comprimento_sepala, largura_sepala, comprimento_petala, largura_petala;
    char tipo[50];
} IRIS;

void classificar(IRIS nao_identificada, IRIS registros_identificados[], int n)
{
    char identificacao[TAM_STR];
    float menor_distancia_euclidiana;
    for (int j = 0; j < n; j++)
    {
        IRIS *i = registros_identificados + j;
        float soma = pow(i->comprimento_sepala - nao_identificada.comprimento_sepala, 2) + pow(i->largura_sepala - nao_identificada.largura_sepala, 2) + pow(i->comprimento_petala - nao_identificada.comprimento_petala, 2) + pow(i->largura_petala - nao_identificada.largura_petala, 2);
        float distancia_euclidiana = sqrt(soma);
        printf("%f\n", distancia_euclidiana);
        if (j == 0 || distancia_euclidiana < menor_distancia_euclidiana)
        {
            menor_distancia_euclidiana = distancia_euclidiana;
            strcpy(identificacao, i->tipo);
        }
    }
    printf("%s\n", identificacao);
}

int main()
{
    int n;
    scanf("%d", &n);
    IRIS identificadas[n];
    for (int j = 0; j < n; j++)
    {
        IRIS *i = identificadas + j;
        scanf("%f %f %f %f %s", &(i->comprimento_sepala), &(i->largura_sepala), &(i->comprimento_petala), &(i->largura_petala), i->tipo);
    }
    IRIS i;
    scanf("%f %f %f %f", &(i.comprimento_sepala), &(i.largura_sepala), &(i.comprimento_petala), &(i.largura_petala));
    classificar(i, identificadas, n);
    return 0;
}