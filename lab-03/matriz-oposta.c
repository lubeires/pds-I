#define TAM 50
#include <stdio.h>

int main()
{
    int matriz[TAM][TAM], lin, col, elemento;
    scanf("%d %d", &lin, &col);
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &elemento);
            matriz[i][j] = -elemento;
        }
    }
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    return 0;
}