#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int **matriz = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matriz[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++)
            scanf("%d", &matriz[i][j]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    for (int i = 0; i < n; i++)
        free(matriz[i]);
    free(matriz);
    return 0;
}