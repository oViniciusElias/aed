/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 3357
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void leParticipantes(char **matriz, int quantidade);
void liberaMemoria(char **matriz, int quantidade);
char **criaMatriz(int linhas, int colunas);

int main() {
    char **participantes;
    double volumeGarrafa, volumeCuia, resto;
    int quantidade, contador, indice;

    scanf("%d %lf %lf", &quantidade, &volumeGarrafa, &volumeCuia);
    getchar();
    
    participantes = criaMatriz(quantidade, 13);
    leParticipantes(participantes, quantidade);

    resto = volumeGarrafa;
    contador = -1;
    while (1) {
        contador++;
        if (resto - volumeCuia <= 0) {
            break;
        } else {
            resto = round((resto - volumeCuia) * 10.0) / 10.0;
        }
    }
    
    printf("%s %.1lf\n", participantes[contador % quantidade], resto);
    liberaMemoria(participantes, quantidade);
    return 0;
}

char **criaMatriz(int linhas, int colunas) {
    char **matriz;
    int i;
 
    matriz = (char **)malloc(sizeof(char *) * linhas);
    for (i = 0; i < linhas; i++) {
        matriz[i] = (char *)malloc(sizeof(char) * colunas);
    }
    return matriz;
}

void liberaMemoria(char **matriz, int quantidade) {
    int i;
    for (i = 0; i < quantidade; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void leParticipantes(char **matriz, int quantidade) {
    int i;
    for (i = 0; i < quantidade; i++) {
        scanf("%s", matriz[i]);
    }
}
