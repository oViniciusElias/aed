/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 2848
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenacaoSelecao(int vetor[], int tamanho);
void lerVetor(int vetor[], int tamanho);
int contarNumero(int vetor[], int tamanho, int numero);
void copiarVetor(int vetorOrigem[], int vetorDestino[], int tamanhoDestino, int limiteInferior);

int main() {
    int tamanhoVetor, numeroRodadas;
    int limiteInferior, limiteSuperior, kesimoMenor, pontuacaoGuga, pontuacaoDabriel;
    int *vetorPrincipal, *vetorIntervalo;
    int iterador;

    scanf("%d %d", &tamanhoVetor, &numeroRodadas);
    vetorPrincipal = (int*) malloc(tamanhoVetor * sizeof(int));
    lerVetor(vetorPrincipal, tamanhoVetor);
    
    for(iterador = 0; iterador < numeroRodadas; iterador++) {
        scanf("%d %d %d %d %d", &limiteInferior, &limiteSuperior, &kesimoMenor, &pontuacaoGuga, &pontuacaoDabriel);

        int tamanhoIntervalo = limiteSuperior - limiteInferior + 1;
        vetorIntervalo = (int*) malloc(tamanhoIntervalo * sizeof(int));
        copiarVetor(vetorPrincipal, vetorIntervalo, tamanhoIntervalo, limiteInferior - 1);

        ordenacaoSelecao(vetorIntervalo, tamanhoIntervalo);
        int menor = vetorIntervalo[kesimoMenor - 1];
        int contKEsimo = contarNumero(vetorIntervalo, tamanhoIntervalo, menor);

        int difGuga = abs(contKEsimo - pontuacaoGuga);
        int difDabri = abs(contKEsimo - pontuacaoDabriel);

        char result = 'E';
        if(difGuga < difDabri) { result = 'G'; }
        else if(difDabri < difGuga) { result = 'D'; }

        printf("%d %d %c\n", menor, contKEsimo, result);
        free(vetorIntervalo);
    }

    free(vetorPrincipal);
    return 0;
}

int contarNumero(int vetor[], int tamanho, int numero) {
    int i, cont = 0;
    for(i = 0; i < tamanho; i++) {
        if(vetor[i] == numero) {
            cont++;
        }
    }
    return cont;
}

void ordenacaoSelecao(int vetor[], int tamanho) {
    int i, j;
    for (i = 0; i < tamanho - 1; i++) {
        int minimo = i;
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[minimo]) {
                minimo = j;
            }
        }
        int temporario = vetor[i];
        vetor[i] = vetor[minimo];
        vetor[minimo] = temporario;
    }
}

void copiarVetor(int vetorOrigem[], int vetorDestino[], int tamanhoDestino, int limiteInferior) {
    int i, j;
    for(i = 0, j = limiteInferior; i < tamanhoDestino; i++, j++) {
        vetorDestino[i] = vetorOrigem[j];
    }
}

void lerVetor(int vetor[], int tamanho) {
    int i;
    for(i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
}
