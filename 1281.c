/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1281
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    double valorTotal, precosProdutos[100];
    int numCasos, qtdProdutos, qtdCompras, quantidadeItem;
    char produto[50], listaProdutos[100][50];

    scanf("%d", &numCasos);

    for (int caso = 0; caso < numCasos; ++caso)
    {
        scanf("%d", &qtdProdutos);

        for (int i = 0; i < qtdProdutos; ++i)
        {
            scanf("%s %lf\n", listaProdutos[i], &precosProdutos[i]);
        }

        scanf("%d", &qtdCompras);
        valorTotal = 0.0;

        for (int i = 0; i < qtdCompras; ++i)
        {
            scanf("%s %d\n", produto, &quantidadeItem);

            for (int j = 0; j < qtdProdutos; ++j)
            {
                if (strcmp(produto, listaProdutos[j]) == 0)
                {
                    valorTotal += quantidadeItem * precosProdutos[j];
                    break;
                }
            }
        }

        printf("R$ %.2lf\n", valorTotal);
    }

    return 0;
}
