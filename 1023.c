/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int principal()
{
    long long moradores, casas, agua;
    long long totalMoradores, totalAgua;
    int cidade = 0;
    int listaConsumo[201];
    double consumoMedio;
    int consumoMedioInteiro;
    int primeiro;

    while (1)
    {
        scanf("%lld", &casas);
        if (casas == 0) break;

        totalMoradores = 0;
        totalAgua = 0;
        for (int i = 0; i <= 200; ++i) {
            listaConsumo[i] = 0;
        }

        printf("\n");
        for (long long i = 0; i < casas; ++i)
        {
            scanf("%lld %lld", &moradores, &agua);
            totalMoradores += moradores;
            totalAgua += agua;

            if (moradores > 0 && agua / (double)moradores <= 200) {
                listaConsumo[agua / moradores] += moradores;
            }
        }

        printf("Cidade# %d:\n", ++cidade);
        primeiro = 1;
        for (int i = 0; i <= 200; ++i)
        {
            if (listaConsumo[i] > 0)
            {
                if (!primeiro)
                    printf(" ");
                primeiro = 0;
                printf("%d-%d", listaConsumo[i], i);
            }
        }
        printf("\n");
        consumoMedio = (double)totalAgua / totalMoradores;
        consumoMedioInteiro = (int)(consumoMedio * 100);
        consumoMedio = consumoMedioInteiro / 100.0;
        printf("Consumo medio: %.2lf m3.\n", consumoMedio);
    }

    return 0;
}