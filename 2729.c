/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    char elemento[21];
    struct lista *proximo;
} celula;

void imprimir(celula *lista) {
    celula *auxiliar;
    for(auxiliar = lista->proximo; auxiliar->proximo != NULL; auxiliar = auxiliar->proximo) {
        printf("%s ", auxiliar->elemento);
    }
    printf("%s\n", auxiliar->elemento);
}

void inserir(char c[21], celula *p) {
    celula *novo, *auxiliar;
    novo = (celula*)malloc(sizeof(celula));
    strncpy(novo->elemento, c, sizeof(novo->elemento));
    novo->elemento[sizeof(novo->elemento) - 1] = '\0';
    auxiliar = p;
    while(auxiliar->proximo != NULL && strcmp(novo->elemento, auxiliar->proximo->elemento) >= 0) {
        auxiliar = auxiliar->proximo;
    }
    novo->proximo = auxiliar->proximo;
    auxiliar->proximo = novo;
}

int comparar(char c[21], celula *lista) {
    celula *auxiliar = lista->proximo;
    while(auxiliar != NULL) {
        if(strcmp(c, auxiliar->elemento) == 0) {
            return 0;
        }
        auxiliar = auxiliar->proximo;
    }
    return 1;
}

int main() {
    int quantidade, i;
    char itens[21000], *palavra;
    celula *lista = (celula*)malloc(sizeof(celula)), *auxiliar;

    lista->proximo = NULL;

    scanf("%d", &quantidade);
    getchar();

    for(i = 0; i < quantidade; i++) {
        fgets(itens, sizeof(itens), stdin);
        palavra = strtok(itens, " \n");
        while(palavra != NULL) {
            if(comparar(palavra, lista) == 1) {
                inserir(palavra, lista);
            }
            palavra = strtok(NULL, " \n");
        }
        imprimir(lista);

        while(lista->proximo != NULL) {
            auxiliar = lista->proximo;
            lista->proximo = auxiliar->proximo;
            free(auxiliar);
        }
    }
    free(lista);
    return 0;
}