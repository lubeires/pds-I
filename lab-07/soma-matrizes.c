#include <stdio.h>
#define TAM 5

int main()
{
    FILE *arquivo;
    char nome[10];
    long unsigned int elemento, matriz[TAM][TAM] = {};
    scanf("%s", nome);
    arquivo = fopen(nome, "rb");

    for (int cont = 0; cont < 2; cont++)
        for (int i = 0; i < TAM; i++)
            for (int j = 0; j < TAM; j++)
            {
                fscanf(arquivo, "%lu", &elemento);
                matriz[i][j] += elemento;
            }

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
            printf("%lu ", matriz[i][j]);
        printf("\n");
    }

    fclose(arquivo);
    return 0;
}