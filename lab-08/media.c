#include <stdio.h>
#include <math.h>

void media(double vet[], int n, int *i)
{
    double soma = 0;
    for (int j = 0; j < n; j++)
        soma += vet[j];
    double media = soma / n;
    for (int j = 0; j < n; j++)
        if (fabs(vet[j] - media) < fabs(vet[*i] - media))
            *i = j;
}

int main()
{
    int n, i = 0;
    scanf("%d", &n);
    double vet[n];
    for (int j = 0; j < n; j++)
        scanf("%lf", &vet[j]);
    media(vet, n, &i);
    printf("%d\n", i);
    return 0;
}