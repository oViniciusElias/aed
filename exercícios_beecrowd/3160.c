/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED
Exercício Beecrowd 3160
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
IDEIA: Lista encadeada. Busca elemento. Insere elementos novos antes do encontrado antes

*/

#define TAMANHO 100

// CRIAR TIPO
struct cell
{
    char conteudo;
    struct cell* prox;

};
typedef struct cell celula;

celula* criar(char nome)
{
    celula * novo = (celula*)malloc(sizeof(celula));
    novo->conteudo = nome;
    novo->prox = NULL;
    return novo;
}

void inserir(celula** cabeaca, int valor){
    celula* nova = criar(valor);
    nova->prox = *cabeaca;
    *cabeaca = nova;
}

void buscarEInserir(celula** cabeca, char valorBusca, char valorInserir) {
    celula* atual = *cabeca;
    celula* anterior = NULL;

    while (atual != NULL && atual->conteudo != valorBusca) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) { 
        celula* nova = criar(valorInserir);
        if (anterior == NULL) { 
            nova->prox = *cabeca;
            *cabeca = nova;
        } else { 
            anterior->prox = nova;
            nova->prox = atual;
        }
    } else {
        printf("Elemento %c não encontrado.\n", valorBusca);
    }
}

void imprimirLista(celula* cabeca) {
    celula* atual = cabeca;
    while (atual != NULL) {
        printf("%c -> ", atual->conteudo);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    celula* lista = NULL;

    inserir(&lista, 'A');
    inserir(&lista, 'B');
    inserir(&lista, 'C');

    printf("Lista original:\n");
    imprimirLista(lista);

    buscarEInserir(&lista, 'B', 'D');
    printf("Lista após inserção:\n");
    imprimirLista(lista);

    return 0;
}