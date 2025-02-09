/*
Escreva uma função que conte o número de células de uma lista encadeada.
Faça duas versões: uma iterativa e uma recursiva.*/



#include <stdio.h>
#include <stdlib.h>


struct reg
    {
        int conteudo;
        struct reg *prox;        
    };

typedef struct reg celula;

int profundidade(celula *comeco, celula *qual){
    int prof = 0;
    celula *atual = comeco;

    while (atual != NULL){
        if (atual == qual){
            return prof;
        }
        prof++;
        atual = atual->prox;
    }
    return -1;
}


int main (){

    celula *n1 = malloc(sizeof(celula));
    celula *n2 = malloc(sizeof(celula));
    celula *n3 = malloc(sizeof(celula));
    celula *n4 = malloc(sizeof(celula));

    n1 -> prox = n2; n2 -> prox = n3; n3 -> prox = n4; n4 -> prox = NULL;

    n1->conteudo = 1;
    n2->conteudo = 4;
    n3->conteudo = 7;
    n4->conteudo = 9;
        
    printf("%d", profundidade(n1,n3));
    
    return 0;

}