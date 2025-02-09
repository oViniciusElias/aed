/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1897
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct NoFila {
    int num;
    int ops;
    struct NoFila* prox;
} NoFila;

typedef struct Fila {
    NoFila* frente;
    NoFila* tras;
} Fila;

#define TAMANHO_HASH 10007

typedef struct NoHash {
    int num;
    struct NoHash* prox;
} NoHash;

NoHash* tabelaHash[TAMANHO_HASH];

void inicializaTabelaHash() {
    for (int i = 0; i < TAMANHO_HASH; i++) {
        tabelaHash[i] = NULL;
    }
}

void insereHash(int num) {
    int indice = (num % TAMANHO_HASH + TAMANHO_HASH) % TAMANHO_HASH; 
    
    NoHash* atual = tabelaHash[indice];
    while (atual != NULL) {
        if (atual->num == num) return; 
        atual = atual->prox;
    }
    
    NoHash* novoNo = (NoHash*)malloc(sizeof(NoHash));
    novoNo->num = num;
    novoNo->prox = tabelaHash[indice];
    tabelaHash[indice] = novoNo;
}

int contemHash(int num) {
    int indice = (num % TAMANHO_HASH + TAMANHO_HASH) % TAMANHO_HASH;
    
    NoHash* atual = tabelaHash[indice];
    while (atual != NULL) {
        if (atual->num == num) return 1;
        atual = atual->prox;
    }
    return 0;
}

void liberaTabelaHash() {
    for (int i = 0; i < TAMANHO_HASH; i++) {
        NoHash* atual = tabelaHash[i];
        while (atual != NULL) {
            NoHash* temp = atual;
            atual = atual->prox;
            free(temp);
        }
        tabelaHash[i] = NULL;
    }
}

void enfileira(Fila* f, int num, int ops) {
    NoFila* novoNo = (NoFila*)malloc(sizeof(NoFila));
    novoNo->num = num;
    novoNo->ops = ops;
    novoNo->prox = NULL;
    
    if (f->tras == NULL) {
        f->frente = f->tras = novoNo;
    } else {
        f->tras->prox = novoNo;
        f->tras = novoNo;
    }
}

NoFila* desenfileira(Fila* f) {
    if (f->frente == NULL) return NULL;
    
    NoFila* temp = f->frente;
    f->frente = f->frente->prox;
    
    if (f->frente == NULL) {
        f->tras = NULL;
    }
    
    return temp;
}

int filaVazia(Fila* f) {
    return f->frente == NULL;
}

int resolve(int N, int M) {
    Fila f = {NULL, NULL};
    inicializaTabelaHash();
    
    enfileira(&f, N, 0);
    insereHash(N);
    
    while (!filaVazia(&f)) {
        NoFila* atual = desenfileira(&f);
        int num_atual = atual->num;
        int ops_atuais = atual->ops;
        
        if (num_atual == M) {
            free(atual);
            while (!filaVazia(&f)) {
                NoFila* temp = desenfileira(&f);
                free(temp);
            }
            liberaTabelaHash();
            return ops_atuais;
        }
        
        int proximos_valores[] = {
            num_atual * 2,
            num_atual * 3,
            num_atual / 2,
            num_atual / 3,
            num_atual + 7,
            num_atual - 7
        };
        
        for (int i = 0; i < 6; i++) {
            int prox_num = proximos_valores[i];
            if (!contemHash(prox_num)) {
                enfileira(&f, prox_num, ops_atuais + 1);
                insereHash(prox_num);
            }
        }
        
        free(atual);
    }
    
    liberaTabelaHash();
    return -1;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    printf("%d\n", resolve(N, M));
    return 0;
}