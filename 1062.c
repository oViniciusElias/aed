/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1062
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct NoEmpilhavel {
    int valor;
    struct NoEmpilhavel* proximo;
};

struct PilhaVagoes {
    int quantidade;
    struct NoEmpilhavel* topo;
};

void empilhar(struct PilhaVagoes* p, int valor) {
    p->quantidade += 1;
    struct NoEmpilhavel* novoTopo = (struct NoEmpilhavel*) malloc(sizeof(struct NoEmpilhavel));

    novoTopo->valor = valor;
    novoTopo->proximo = p->topo;
    p->topo = novoTopo;
}

void desempilhar(struct PilhaVagoes* p) {
    if(p->quantidade > 0){
        p->quantidade -= 1;
        struct NoEmpilhavel* velhoTopo = p->topo;
        p->topo = p->topo->proximo;
        free(velhoTopo);
    }
}

int consultarTopo(struct PilhaVagoes* p) {
    return p->topo->valor;
}

int tamanho(struct PilhaVagoes* p) {
    return p->quantidade;
}

int vazia(struct PilhaVagoes* p) {
    return p->quantidade == 0;
}

void inicializa(struct PilhaVagoes* p) {
    p->quantidade = 0;
    p->topo = NULL;
}

void destroi(struct PilhaVagoes* p) {
    while(!vazia(p)){
        desempilhar(p);
    }
}

int main(){
    int N, x;
    struct PilhaVagoes A, estacao, B;

    while(scanf("%d", &N) != EOF){
        if(!N)  break;

        while(scanf("%d", &x)){
            if(!x){
                printf("\n");
                break;
            }

            inicializa(&A);
            inicializa(&estacao);
            inicializa(&B);

            empilhar(&A, x);
            empilhar(&B, 1);
            for(int i = 2; i <= N; ++i){
                scanf("%d", &x);
                empilhar(&A, x);
                empilhar(&B, i);
            }

            while(!vazia(&A) || !vazia(&estacao) || !vazia(&B)){
                if(!vazia(&A) && !vazia(&B) && consultarTopo(&A) == consultarTopo(&B)){
                    desempilhar(&A);
                    desempilhar(&B);
                }else if(!vazia(&estacao) && !vazia(&B) && consultarTopo(&estacao) == consultarTopo(&B)){
                    desempilhar(&estacao);
                    desempilhar(&B);
                }else if(!vazia(&A)){
                    empilhar(&estacao, consultarTopo(&A));
                    desempilhar(&A);
                }else{
                    break;
                }
            }

            if(vazia(&A) && vazia(&estacao) && vazia(&B)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }

            destroi(&A);
            destroi(&estacao);
            destroi(&B);
        }
    }

    return 0;
}