/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1063
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAGOES 26

typedef struct {
    char vagoes[MAX_VAGOES];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int estaCheia(Pilha *p) {
    return p->topo == MAX_VAGOES - 1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(Pilha *p, char c) {
    if (!estaCheia(p)) {
        p->vagoes[++(p->topo)] = c;
    }
}

char desempilhar(Pilha *p) {
    if (!estaVazia(p)) {
        return p->vagoes[(p->topo)--];
    }
    return '\0';
}

char topo(Pilha *p) {
    if (!estaVazia(p)) {
        return p->vagoes[p->topo];
    }
    return '\0';
}

int main() {
    int numVagoes;
    while (scanf("%d", &numVagoes) && numVagoes != 0) {
        char entrada[MAX_VAGOES + 1], saida[MAX_VAGOES + 1];

        for (int i = 0; i < numVagoes; i++) {
            scanf(" %c", &entrada[i]);
        }
        entrada[numVagoes] = '\0';

        for (int i = 0; i < numVagoes; i++) {
            scanf(" %c", &saida[i]);
        }
        saida[numVagoes] = '\0';

        Pilha pilha;
        inicializarPilha(&pilha);

        char resultado[2 * MAX_VAGOES * 2 + 1];
        int indiceResultado = 0;

        int indiceEntrada = 0, indiceSaida = 0;
        int possivel = 1;

        while (indiceSaida < numVagoes) {
            if (!estaVazia(&pilha) && topo(&pilha) == saida[indiceSaida]) {
                desempilhar(&pilha);
                resultado[indiceResultado++] = 'R';
                indiceSaida++;
            } else if (indiceEntrada < numVagoes) {
                empilhar(&pilha, entrada[indiceEntrada++]);
                resultado[indiceResultado++] = 'I';
            } else {
                possivel = 0;
                break;
            }
        }

        resultado[indiceResultado] = '\0';

        if (possivel && indiceSaida == numVagoes) {
            printf("%s\n", resultado);
        } else {
            printf("%s Impossible\n", resultado);
        }
    }

    return 0;
}