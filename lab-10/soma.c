#include <stdio.h>
#include <stdlib.h>

void preencher_vetor(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", vetor + i);
}

void somar_vetores(int *v1, int *v2, int *v_soma, int n)
{
    for (int i = 0; i < n; i++)
        v_soma[i] = v1[i] + v2[i];
}

int main()
{
    int n;
    scanf("%d", &n);
    int *v1 = (int *)malloc(n * sizeof(int));
    int *v2 = (int *)malloc(n * sizeof(int));
    int *v_soma = (int *)malloc(n * sizeof(int));
    preencher_vetor(v1, n);
    preencher_vetor(v2, n);
    somar_vetores(v1, v2, v_soma, n);
    for (int i = 0; i < n; i++)
        printf("%d\n", v_soma[i]);
    free(v1);
    free(v2);
    free(v_soma);
    return 0;
}