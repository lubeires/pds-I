#include <stdio.h>
#include <string.h>

int main()
{
    int qtd_jogos, tam, qtd_jogadas, x, y, quadrados_revelados = 0, quadrados_sem_mina = 0;
    char campo_minado[100][100], resultado[20];

    scanf("%d", &qtd_jogos);
    while (qtd_jogos--)
    {
        strcpy(resultado, "FALTOU TERMINAR");
        scanf("%d", &tam);
        for (int i = 0; i < tam; i++)
            for (int j = 0; j < tam; j++)
            {
                scanf(" %c", &campo_minado[i][j]);
                if (campo_minado[i][j] == 'x')
                    quadrados_sem_mina++;
            }
        scanf("%d", &qtd_jogadas);

    proxima_jogada:
        while (qtd_jogadas--)
        {
            scanf("%d %d", &x, &y);
            if (strcmp(resultado, "PERDEU") != 0)
            {
                if (campo_minado[x][y] == 'b')
                    strcpy(resultado, "PERDEU");
                else if (campo_minado[x][y] == 'x')
                {
                    for (int i = -1; i < 2; i++)
                        if (x + i >= 0 && x + i < tam)
                            for (int j = -1; j < 2; j++)
                                if (y + j >= 0 && y + j < tam)
                                {
                                    if (campo_minado[x + i][y + j] == 'b')
                                    {
                                        campo_minado[x][y] = 'o';
                                        quadrados_revelados++;
                                        goto proxima_jogada;
                                    }
                                }

                    for (int i = -1; i < 2; i++)
                        if (x + i >= 0 && x + i < tam)
                            for (int j = -1; j < 2; j++)
                                if (y + j >= 0 && y + j < tam)
                                    if (campo_minado[x + i][y + j] == 'x')
                                    {
                                        campo_minado[x + i][y + j] = 'o';
                                        quadrados_revelados++;
                                    }
                }
            }
        }

        if (quadrados_revelados == quadrados_sem_mina)
            strcpy(resultado, "GANHOU");
        printf("%s\n", resultado);
    }

    return 0;
}