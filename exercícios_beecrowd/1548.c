/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1548
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{
    int casos, alunos, resultado;
    int notas_originais[1000], notas_ordenadas[1000];

    scanf("%d", &casos);

    for (int i = 0; i < casos; ++i)
    {
        scanf("%d", &alunos);

        for (int j = 0; j < alunos; ++j)
        {
            scanf("%d", &notas_originais[j]);
            notas_ordenadas[j] = notas_originais[j];
        }

        qsort(notas_ordenadas, alunos, sizeof(int), comparar);

        resultado = 0;
        for (int j = 0; j < alunos; ++j)
        {
            if (notas_originais[j] == notas_ordenadas[j])
                ++resultado;
        }

        printf("%d\n", resultado);
    }

    return 0;
}