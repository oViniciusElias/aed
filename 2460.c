/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 2460
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fila {
    int pessoa;
    int posicao;
};

void inicializar(struct fila *fila);
void adicionar(int pessoa, struct fila *fila);
void remover(int pessoa, struct fila *fila);
void mostrarFila(struct fila *fila);

int main() {
    int qtd_pessoas, pessoa, qtd_saidas;
    
    scanf("%d", &qtd_pessoas);
    
    struct fila fila[qtd_pessoas];
    inicializar(fila);
    
    for (int i = 0; i < qtd_pessoas; i++) {
        scanf("%d", &pessoa);
        adicionar(pessoa, fila);
    }
    
    scanf("%d", &qtd_saidas);
    
    for (int i = 0; i < qtd_saidas; i++) {
        scanf("%d", &pessoa);
        remover(pessoa, fila);
    }
    
    mostrarFila(fila);
    
    return 0;
}

void inicializar(struct fila *fila) {
    fila->posicao = 0;
}

void adicionar(int pessoa, struct fila *fila) {
    fila[fila->posicao].pessoa = pessoa;
    (fila->posicao)++;
}

void remover(int pessoa, struct fila *fila) {
    for (int i = 0; i < fila->posicao; i++) {
        if (pessoa == fila[i].pessoa) {
            for (int j = i; j < fila->posicao - 1; j++) {
                fila[j].pessoa = fila[j + 1].pessoa;
            }
            fila->posicao--;
            return;
        }
    }
}

void mostrarFila(struct fila *fila) {
    for (int i = 0; i < fila->posicao; i++) {
        if (i < fila->posicao - 1) {
            printf("%d ", fila[i].pessoa);
        } else {
            printf("%d\n", fila[i].pessoa);
        }
    }
}