/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1340
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NoPilha {
    int valor;
    struct NoPilha* abaixo;
};

struct Pilha {
    int tamanho;
    struct NoPilha* topo;
};

void inicializaPilha(struct Pilha* p) {
    p->tamanho = 0;
    p->topo = NULL;
}

void empilha(struct Pilha* p, int valor) {
    p->tamanho += 1;
    struct NoPilha* novoTopo = (struct NoPilha*) malloc(sizeof(struct NoPilha));
    novoTopo->valor = valor;
    novoTopo->abaixo = p->topo;
    p->topo = novoTopo;
}

void desempilha(struct Pilha* p) {
    if(p->tamanho > 0) {
        p->tamanho -= 1;
        struct NoPilha* velhoTopo = p->topo;
        p->topo = velhoTopo->abaixo;
        free(velhoTopo);
    }
}

int topoPilha(struct Pilha* p) {
    return p->topo->valor;
}

int tamanhoPilha(struct Pilha* p) {
    return p->tamanho;
}

int pilhaVazia(struct Pilha* p) {
    return p->tamanho == 0;
}

void destroiPilha(struct Pilha* p) {
    while(!pilhaVazia(p)) {
        desempilha(p);
    }
}

struct NoFila {
    int valor;
    struct NoFila* proximo;
};

struct Fila {
    int tamanho;
    struct NoFila *frente, *tras;
};

void inicializaFila(struct Fila* f) {
    f->tamanho = 0;
    f->frente = NULL;
    f->tras = NULL;
}

void enfileira(struct Fila* f, int valor) {
    f->tamanho += 1;
    struct NoFila* novoNo = (struct NoFila*) malloc(sizeof(struct NoFila));
    novoNo->valor = valor;
    novoNo->proximo = NULL;

    if(f->frente == NULL) {
        f->frente = novoNo;
    } else {
        f->tras->proximo = novoNo;
    }
    f->tras = novoNo;
}

void desenfileira(struct Fila* f) {
    if(f->tamanho > 0) {
        f->tamanho -= 1;
        struct NoFila* velhaFrente = f->frente;
        f->frente = velhaFrente->proximo;
        free(velhaFrente);
    }
}

int frenteFila(struct Fila* f) {
    return f->frente->valor;
}

int tamanhoFila(struct Fila* f) {
    return f->tamanho;
}

int filaVazia(struct Fila* f) {
    return f->tamanho == 0;
}

void destroiFila(struct Fila* f) {
    while(!filaVazia(f)) {
        desenfileira(f);
    }
}

int compara(int a, int b) {
    return a - b;
}

struct NoFilaDePrioridade {
    int valor;
    struct NoFilaDePrioridade *pai, *esq, *dir;
};

struct FilaDePrioridade {
    int tamanho;
    struct NoFilaDePrioridade *topo, *ultimo;
};

void inicializaFilaDePrioridade(struct FilaDePrioridade *fp) {
    fp->tamanho = 0;
    fp->topo = NULL;
    fp->ultimo = NULL;
}

void destroiNoFilaDePrioridade(struct NoFilaDePrioridade *fpn) {
    if(fpn->esq != NULL) {
        destroiNoFilaDePrioridade(fpn->esq);
    }
    if(fpn->dir != NULL) {
        destroiNoFilaDePrioridade(fpn->dir);
    }
    free(fpn);
}

void destroiFilaDePrioridade(struct FilaDePrioridade *fp) {
    fp->tamanho = 0;
    if(fp->topo != NULL) {
        destroiNoFilaDePrioridade(fp->topo);
    }
}

void corrigeSubindo(struct NoFilaDePrioridade *fpn) {
    if(fpn->pai == NULL) {
        return;
    }
    
    struct NoFilaDePrioridade *pai = fpn->pai;
    if(compara(pai->valor, fpn->valor) < 0) {
        int temp = pai->valor;
        pai->valor = fpn->valor;
        fpn->valor = temp;
        corrigeSubindo(pai);
    }
}

void enfileiraPrioridade(struct FilaDePrioridade *fp, int valor) {
    fp->tamanho += 1;

    struct NoFilaDePrioridade* novoNo = (struct NoFilaDePrioridade*)malloc(sizeof(struct NoFilaDePrioridade));
    novoNo->valor = valor;
    novoNo->esq = NULL;
    novoNo->dir = NULL;

    if(fp->topo == NULL) {
        novoNo->pai = NULL;
        fp->topo = novoNo;
    } else {
        if(fp->ultimo->pai != NULL && fp->ultimo->pai->dir == NULL) {
            novoNo->pai = fp->ultimo->pai;
            fp->ultimo->pai->dir = novoNo;
        } else {
            novoNo->pai = fp->ultimo;
            fp->ultimo->esq = novoNo;
        }
    }
    fp->ultimo = novoNo;
    
    corrigeSubindo(novoNo);
}

void corrigeDescendo(struct NoFilaDePrioridade *fpn) {
    if(fpn->esq != NULL) {
        struct NoFilaDePrioridade *esq = fpn->esq;
        if(compara(fpn->valor, esq->valor) < 0) {
            int temp = fpn->valor;
            fpn->valor = esq->valor;
            esq->valor = temp;
            corrigeDescendo(esq);
        }
    }
    
    if(fpn->dir != NULL) {
        struct NoFilaDePrioridade *dir = fpn->dir;
        if(compara(fpn->valor, dir->valor) < 0) {
            int temp = fpn->valor;
            fpn->valor = dir->valor;
            dir->valor = temp;
            corrigeDescendo(dir);
        }
    }
}

void desenfileiraPrioridade(struct FilaDePrioridade *fp) {
    if(fp->tamanho == 0) {
        return;
    }
    
    fp->tamanho -= 1;
    
    struct NoFilaDePrioridade* velhoUltimo = fp->ultimo;
    if(velhoUltimo == fp->topo) {
        fp->topo = NULL;
    } else {
        int temp = fp->topo->valor;
        fp->topo->valor = velhoUltimo->valor;
        velhoUltimo->valor = temp;
        
        if(velhoUltimo->pai != NULL && velhoUltimo->pai->esq != NULL && velhoUltimo->pai->esq != velhoUltimo) {
            velhoUltimo->pai->dir = NULL;
            fp->ultimo = velhoUltimo->pai->esq;
        } else {
            if(velhoUltimo->pai != NULL) {
                velhoUltimo->pai->esq = NULL;
            }
            fp->ultimo = velhoUltimo->pai;
        }
    }
    free(velhoUltimo);
    
    if(fp->topo != NULL) {
        corrigeDescendo(fp->topo);
    }
}

int topoFilaDePrioridade(struct FilaDePrioridade *fp) {
    return fp->topo->valor;
}

int filaDePrioridadeVazia(struct FilaDePrioridade *fp) {
    return fp->tamanho == 0;
}

int main() {
    int i, n, opcao, elemento;
    struct Pilha p;
    struct Fila f;
    struct FilaDePrioridade fp;

    while(scanf("%d\n", &n) != EOF) {
        inicializaPilha(&p);
        inicializaFila(&f);
        inicializaFilaDePrioridade(&fp);

        int pilha = 1, fila = 1, filaDePrioridade = 1;
        for(i = 0; i < n; ++i) {
            scanf("%d %d\n", &opcao, &elemento);

            if(opcao == 1) {
                if(pilha) {
                    empilha(&p, elemento);
                }
                if(fila) {
                    enfileira(&f, elemento);
                }
                if(filaDePrioridade) {
                    enfileiraPrioridade(&fp, elemento);
                }
            } else {
                if(pilha) {
                    if(pilhaVazia(&p) || topoPilha(&p) != elemento) {
                        pilha = 0;
                    } else {
                        desempilha(&p);
                    }
                }
                if(fila) {
                    if(filaVazia(&f) || frenteFila(&f) != elemento) {
                        fila = 0;
                    } else {
                        desenfileira(&f);
                    }
                }
                if(filaDePrioridade) {
                    if(filaDePrioridadeVazia(&fp) || topoFilaDePrioridade(&fp) != elemento) {
                        filaDePrioridade = 0;
                    } else {
                        desenfileiraPrioridade(&fp);
                    }
                }
            }
        }

        if(pilha + fila + filaDePrioridade > 1) {
            printf("not sure\n");
        } else if(pilha) {
            printf("stack\n");
        } else if(fila) {
            printf("queue\n");
        } else if(filaDePrioridade) {
            printf("priority queue\n");
        } else {
            printf("impossible\n");
        }

        destroiPilha(&p);
        destroiFila(&f);
        destroiFilaDePrioridade(&fp);
    }

    return 0;
}
