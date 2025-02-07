/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_N 10005 

int comparaNumeros(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int numeroCaso = 1;
    
    while (1) {
        int qtdMarmores, qtdConsultas;
        scanf("%d %d", &qtdMarmores, &qtdConsultas);
        
        if (qtdMarmores == 0 && qtdConsultas == 0) break;
        
        int colecao[MAX_N];
        for (int i = 0; i < qtdMarmores; i++) {
            scanf("%d", &colecao[i]);
        }
        
        qsort(colecao, qtdMarmores, sizeof(int), comparaNumeros);
        
        printf("CASE# %d:\n", numeroCaso++);
        
        for (int i = 0; i < qtdConsultas; i++) {
            int consulta;
            scanf("%d", &consulta);
            
            int encontrado = 0;
            int posicao = -1;
            
            for (int j = 0; j < qtdMarmores; j++) {
                if (colecao[j] == consulta) {
                    encontrado = 1;
                    posicao = j + 1; 
                    break;
                }
            }
            
            if (encontrado) {
                printf("%d found at %d\n", consulta, posicao);
            } else {
                printf("%d not found\n", consulta);
            }
        }
    }
    
    return 0;
}