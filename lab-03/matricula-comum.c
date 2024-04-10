#define TAM 100
#include <stdio.h>

int main()
{
    int n_aeds, n_calc, aeds[TAM], calc[TAM];
    scanf("%d", &n_aeds);
    for (int i = 0; i < n_aeds; i++)
        scanf("%d", &aeds[i]);
    scanf("%d", &n_calc);
    for (int i = 0; i < n_calc; i++)
        scanf("%d", &calc[i]);
    for (int i = 0; i < n_aeds; i++)
    {
        for (int j = 0; j < n_calc; j++)
            if (aeds[i] == calc[j])
                printf("%d\n", aeds[i]);
    }
    return 0;
}