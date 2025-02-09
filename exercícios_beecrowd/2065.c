/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 2065
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int T_Info;

struct fila {
    T_Info* elementos;
    int tamanho;
    int ultimo;
    int frente;
};

typedef struct fila* T_Fila;

T_Fila inicializar(int tamanho_max);
void destruir(T_Fila fila);
bool cheia(T_Fila fila);
bool vazia(T_Fila fila);
bool enfileirar(T_Fila fila, T_Info elemento);
bool desenfileirar(T_Fila fila, T_Info* elemento);

int main(){
    int i, qtd_caixas, qtd_clientes;
    
    scanf("%d", &qtd_caixas);
    int tempos_caixas[qtd_caixas];
    scanf("%d", &qtd_clientes);
    int tempos_clientes[qtd_clientes];

    T_Fila caixas = inicializar(qtd_caixas);
    T_Fila clientes = inicializar(qtd_clientes);

    for(i = 0; i < qtd_caixas; i++) {
        scanf("%d", &tempos_caixas[i]);
        enfileirar(caixas, tempos_caixas[i]);
    }

    for(i = 0; i < qtd_clientes; i++) {
        scanf("%d", &tempos_clientes[i]);
        enfileirar(clientes, tempos_clientes[i]);
    }

    int tempos_processamento[qtd_caixas];
    int t = 0;
    while(t < qtd_clientes) {
        if(t < qtd_caixas) {
            int tempo_cliente;
            desenfileirar(clientes, &tempo_cliente);
            tempos_processamento[t] = tempo_cliente * tempos_caixas[t];
            t++;
        }
        else {
            int tempo_cliente;
            desenfileirar(clientes, &tempo_cliente);

            int menor_tempo = tempos_processamento[0];
            int indice_menor = 0;
            for(i = 0; i < qtd_caixas; i++)
                if(menor_tempo > tempos_processamento[i]) {
                    menor_tempo = tempos_processamento[i];
                    indice_menor = i;
                }
            tempos_processamento[indice_menor] += tempo_cliente * tempos_caixas[indice_menor];

            t++;
        }
    }

    int maior_tempo = tempos_processamento[0];
    for(i = 0; i < qtd_caixas; i++) {
        if(maior_tempo < tempos_processamento[i])
            maior_tempo = tempos_processamento[i];
    }

    printf("%d\n", maior_tempo);

    destruir(caixas);
    destruir(clientes);

    return 0;
}

T_Fila inicializar(int tamanho_max) {
    if(tamanho_max < 1) {
        return NULL;
    }

    T_Fila fila = malloc(sizeof(struct fila));
    if(fila != NULL) {
        fila->ultimo = -1;
        fila->frente = 0;
        fila->tamanho = tamanho_max;
        fila->elementos = malloc(sizeof(T_Info) * fila->tamanho);
        if(fila->elementos == NULL) {
            free(fila);
            fila = NULL;
        }
    }

    return fila;
}

void destruir(T_Fila fila) {
    free(fila->elementos);
    free(fila);
}

bool cheia(T_Fila fila) {
    if(fila != NULL)
        return fila->ultimo == fila->tamanho - 1;
    else
        return false;
}

bool vazia(T_Fila fila) {
    if(fila != NULL)
        return fila->ultimo < fila->frente;
    else
        return false;
}

bool enfileirar(T_Fila fila, T_Info elemento) {
    if(fila == NULL)
        return false;
    if(cheia(fila))
        return false;

    fila->ultimo += 1;
    fila->elementos[fila->ultimo] = elemento;
    return true;
}

bool desenfileirar(T_Fila fila, T_Info* elemento) {
    if(fila == NULL)
        return false;
    if(vazia(fila))
        return false;

    *elemento = fila->elementos[fila->frente];
    fila->frente += 1;
    return true;
}