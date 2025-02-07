/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1244
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamanho;
char listaPalavras[100][100];

int compararTamanho(char *a, char *b)
{
    return strlen(b) - strlen(a);
}

void ordenacaoInsercao()
{
    char temporario[100];
    
    for (int i = 1; i < tamanho; ++i)
    {
        int atual = i;
        int anterior = atual - 1;

        while (anterior > -1 && compararTamanho(listaPalavras[atual], listaPalavras[anterior]) < 0)
        {
            strcpy(temporario, listaPalavras[atual]);
            strcpy(listaPalavras[atual], listaPalavras[anterior]);
            strcpy(listaPalavras[anterior], temporario);
            --atual;
            --anterior;
        }
    }
}

int main()
{
    int N;
    char frase[10000], *ptr;

    scanf("%d\n", &N);

    for (int k = 0; k < N; ++k)
    {
        scanf("%[^\n]\n", frase);

        tamanho = 0;
        ptr = strtok(frase, " ");

        while (ptr != NULL)
        {
            strcpy(listaPalavras[tamanho++], ptr);
            ptr = strtok(NULL, " ");
        }

        ordenacaoInsercao();

        printf("%s", listaPalavras[0]);
        for (int i = 1; i < tamanho; ++i)
        {
            printf(" %s", listaPalavras[i]);
        }
        printf("\n");
    }

    return 0;
}