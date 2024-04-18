#define TAM 50
#include <stdio.h>

int main()
{
    int matriz[TAM][TAM], lin, col, maior;
    scanf("%d %d", &lin, &col);
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matriz[i][j]);
            if ((i == 0 && j == 0) || (matriz[i][j] > maior))
                maior = matriz[i][j];
        }
    }
    printf("%d", maior);
}
