#include <stdio.h>

const int QTD_DIAS_MES[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int DIA_FINAL = 17;
const int MES_FINAL = 9;
const int ANO_FINAL = 2020;

int bissexto(int ano)
{
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

unsigned long int calcular_dias_transcorridos(int dia, int mes, int ano)
{
    unsigned long int dias_transcorridos = 0;

    while (ano < ANO_FINAL || (ano == ANO_FINAL && mes < MES_FINAL) || (ano == ANO_FINAL && mes == MES_FINAL && dia < DIA_FINAL))
    {
        dia++;
        dias_transcorridos++;
        if (dia > QTD_DIAS_MES[mes - 1] + (mes == 2 ? bissexto(ano) : 0))
        {
            dia = 1;
            mes++;
            if (mes > 12)
            {
                mes = 1;
                ano++;
            }
        }
    }

    return dias_transcorridos + 1;
}

int main()
{
    int dia, mes, ano;
    while (scanf("%d %d %d", &dia, &mes, &ano) != EOF)
        printf("%lu\n", calcular_dias_transcorridos(dia, mes, ano));
    return 0;
}