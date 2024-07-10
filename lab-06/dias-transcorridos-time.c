#include <stdio.h>
#include <time.h>

const int DIA_FINAL = 17;
const int MES_FINAL = 9;
const int ANO_FINAL = 2020;

unsigned long int calcular_dias_transcorridos(int dia, int mes, int ano)
{
    struct tm inicio = {.tm_year = ano - 1900, .tm_mon = mes - 1, .tm_mday = dia};
    struct tm fim = {.tm_year = ANO_FINAL - 1900, .tm_mon = MES_FINAL - 1, .tm_mday = DIA_FINAL};

    return ((difftime(mktime(&fim), mktime(&inicio)) / (60 * 60 * 24)) + 1);
}

int main()
{
    int dia, mes, ano;
    while (scanf("%d %d %d", &dia, &mes, &ano) != EOF)
        printf("%lu\n", calcular_dias_transcorridos(dia, mes, ano));
    return 0;
}