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

//ITERATIVO
int contar(celula *cabeça){
    int contador = 0;
    celula *atual = cabeça;
    
    while (atual != NULL)
    {
        contador++;
        atual = atual->prox;
    };
    
    return contador;

};

//RECURSIVO
int contar2(celula *comeco){
    
    if (comeco==NULL)
        return 0;
    return 1 + contar2(comeco->prox);

};

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
        
    printf("iterativo %d, recursivo %d", contar(n1), contar2(n1));
    
    return 0;

}