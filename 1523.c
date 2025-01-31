/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1523
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

typedef struct pilha {
    int topo;
    int chegada[MAX];
    int saida[MAX];
} Pilha;

Pilha* criar_pilha();
void liberar_pilha(Pilha* p);
int pilha_vazia(Pilha* p);
int pilha_cheia(Pilha* p, int vagas);
int empilhar(Pilha* p, int chegada, int saida, int vagas);
int desempilhar(Pilha* p);

int main(){
    int vagas, num_carros, chegada, saida;
    int i;
    while(1){
        scanf("%d %d", &num_carros, &vagas);
        if(vagas == 0 && num_carros == 0) break;
        Pilha* p = criar_pilha();
        int possivel = 1;
        for(i = 0; i < num_carros; i++){
            scanf("%d %d", &chegada, &saida);
            if(possivel){
                if(pilha_vazia(p)){
                    empilhar(p, chegada, saida, vagas);
                    possivel = 1;
                } else {
                    while(chegada >= p->saida[p->topo-1]){
                        desempilhar(p);
                        if(pilha_vazia(p)) break;
                    }
                    if(pilha_cheia(p, vagas)){
                        possivel = 0;
                    } else {
                        empilhar(p, chegada, saida, vagas);
                        if(p->topo > 1){
                            if(p->chegada[p->topo-1] > p->chegada[p->topo-2] && p->saida[p->topo-1] < p->saida[p->topo-2]){
                                possivel = 1;
                            }else{
                                possivel = 0;
                            }
                        } else {
                            possivel = 1;
                        }
                    }
                }
            }
        }
        if(possivel) printf("Sim\n");
        else printf("Nao\n");
        liberar_pilha(p);
    }
}

Pilha* criar_pilha(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

void liberar_pilha(Pilha* p){
    free(p);
}

int pilha_vazia(Pilha* p){
    if (p->topo == 0) return 1;
    else return 0;
}

int pilha_cheia(Pilha* p, int vagas){
    if (p->topo == vagas) return 1;
    else return 0;
}

int empilhar(Pilha* p, int chegada, int saida, int vagas){
    if (!pilha_cheia(p, vagas)){
        p->chegada[p->topo] = chegada;
        p->saida[p->topo] = saida;
        p->topo++;
        return 1;
    } else {
        return 0;
    }
}

int desempilhar(Pilha* p){
    if(!pilha_vazia(p)){
        p->topo--;
        return 1;
    } else {
        return 0;
    }
}