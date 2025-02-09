/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 3163
*/

#define MAX_AVIOES 1000

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char* T_Info;

struct fila {
    T_Info* elementos;
    int tamanho;
    int ultimo;
};

typedef struct fila* T_Fila;

T_Fila inicializar(int max_tamanho);
void destruir(T_Fila fila);
bool cheia(T_Fila fila);
bool vazia(T_Fila fila);
bool enfileirar(T_Fila fila, T_Info elemento);
bool desenfileirar(T_Fila fila, T_Info* elemento);

int main() {
    T_Fila leste, oeste, sul, norte, avioes;
    T_Info aviao;
    
    leste = inicializar(MAX_AVIOES);
    oeste = inicializar(MAX_AVIOES);
    sul = inicializar(MAX_AVIOES);
    norte = inicializar(MAX_AVIOES);
    avioes = inicializar(MAX_AVIOES * 4);
    
    int posicao;
    char aviao_id[100];
    
    while (scanf("%d", &posicao) != EOF) {
        if (posicao == 0) {
            break;
        }
        
        scanf("%s", aviao_id);
        aviao = aviao_id;
        
        switch (posicao) {
            case -4:  // Leste
                enfileirar(leste, aviao);
                break;
            case -3:  // Norte
                enfileirar(norte, aviao);
                break;
            case -2:  // Sul
                enfileirar(sul, aviao);
                break;
            case -1:  // Oeste
                enfileirar(oeste, aviao);
                break;
            default:
                break;
        }
    }
    
    while (!vazia(leste) || !vazia(norte) || !vazia(sul) || !vazia(oeste)) {
        if (!vazia(oeste)) {
            desenfileirar(oeste, &aviao);
            enfileirar(avioes, aviao);
        }
        if (!vazia(norte)) {
            desenfileirar(norte, &aviao);
            enfileirar(avioes, aviao);
        }
        if (!vazia(sul)) {
            desenfileirar(sul, &aviao);
            enfileirar(avioes, aviao);
        }
        if (!vazia(leste)) {
            desenfileirar(leste, &aviao);
            enfileirar(avioes, aviao);
        }
    }

    while (!vazia(avioes)) {
        desenfileirar(avioes, &aviao);
        printf("%s", aviao);
        if (!vazia(avioes)) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    destruir(leste);
    destruir(oeste);
    destruir(sul);
    destruir(norte);
    destruir(avioes);
    
    return 0;
}

T_Fila inicializar(int max_tamanho) {
    if (max_tamanho < 1) {
        return NULL;
    }

    T_Fila fila = malloc(sizeof(struct fila));
    if (fila != NULL) {
        fila->ultimo = -1;
        fila->tamanho = max_tamanho;
        fila->elementos = malloc(sizeof(T_Info) * fila->tamanho);
        if (fila->elementos == NULL) {
            free(fila);
            fila = NULL;
        }
    }

    return fila;
}

void destruir(T_Fila fila) {
    for (int i = 0; i <= fila->ultimo; i++) {
        free(fila->elementos[i]);
    }
    free(fila->elementos);
    free(fila);
}

bool cheia(T_Fila fila) {
    if (fila != NULL)
        return fila->ultimo == fila->tamanho - 1;
    else
        return false;
}

bool vazia(T_Fila fila) {
    if (fila != NULL)
        return fila->ultimo == -1;
    else
        return false;
}

bool enfileirar(T_Fila fila, T_Info elemento) {
    if (fila == NULL) {
        return false;
    }
    if (cheia(fila)) {
        return false;
    }

    fila->ultimo += 1;
    fila->elementos[fila->ultimo] = malloc(strlen(elemento) + 1);
    if (fila->elementos[fila->ultimo] == NULL) {
        return false;
    }
    strcpy(fila->elementos[fila->ultimo], elemento);
    return true;
}

bool desenfileirar(T_Fila fila, T_Info* elemento) {
    if (fila == NULL) {
        return false;
    }
    if (vazia(fila)) {
        return false;
    }

    *elemento = fila->elementos[0];

    for (int i = 0; i < fila->ultimo; i++) {
        fila->elementos[i] = fila->elementos[i + 1];
    }
    fila->ultimo -= 1;

    return true;
}