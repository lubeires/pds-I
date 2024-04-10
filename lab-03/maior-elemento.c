#define TAM 50
#include <stdio.h>

int main()
{
    int matriz[TAM][TAM], lin, col, maior;
    scanf("%d %d", &lin, &col);
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
            scanf("%d", &matriz[i][j]);
    }
    maior = matriz[0][0];
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
            if (matriz[i][j] > maior)
                maior = matriz[i][j];
    }
    printf("%d", maior);
}