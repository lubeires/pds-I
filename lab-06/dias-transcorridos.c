#include <stdio.h>

const int QTD_DIAS_MES[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int DIA_FINAL = 17;
const int MES_FINAL = 9;
const int ANO_FINAL = 2020;

int calcular_dias_transcorridos(int dia, int mes, int ano)
{
    int bissextos = 0, dias_transcorridos;
    for (int i = ano; i <= ANO_FINAL; i++)
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
            bissextos++;
    dias_transcorridos = (ANO_FINAL - ano) * 365 + bissextos;

    if (mes < MES_FINAL)
        for (int i = mes; i < MES_FINAL; i++)
            dias_transcorridos += QTD_DIAS_MES[i - 1];

    else if (mes > MES_FINAL)
        for (int i = MES_FINAL; i < mes; i++)
            dias_transcorridos -= QTD_DIAS_MES[i - 1];

    dias_transcorridos += DIA_FINAL - dia + 1;

    return dias_transcorridos;
}

int main()
{
    int dia, mes, ano;
    while (scanf("%d %d %d", &dia, &mes, &ano) != EOF)
        printf("%d\n", calcular_dias_transcorridos(dia, mes, ano));
    return 0;
}