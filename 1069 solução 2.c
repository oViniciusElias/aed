/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1069
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noElemento {
    char simbolo;
    struct noElemento* proximo;
} noElemento;

typedef struct estruturaPilha {
    int quantidade;
    noElemento* primeiro;
} estruturaPilha;

void destruir(estruturaPilha* monte);
int vazia(estruturaPilha* monte);
char topo(estruturaPilha* monte);
int tamanho(estruturaPilha* monte);

void empilhar(estruturaPilha* monte, char simbolo) {
    monte->quantidade += 1;
    noElemento* novoPrimeiro = (noElemento*)malloc(sizeof(noElemento));

    novoPrimeiro->simbolo = simbolo;
    novoPrimeiro->proximo = monte->primeiro;
    monte->primeiro = novoPrimeiro;
}

void desempilhar(estruturaPilha* monte) {
    if(monte->quantidade > 0) {
        monte->quantidade -= 1;
        noElemento* antigoPrimeiro = monte->primeiro;
        monte->primeiro = monte->primeiro->proximo;
        free(antigoPrimeiro);
    }
}

void iniciar(estruturaPilha* monte) {
    monte->quantidade = 0;
    monte->primeiro = NULL;
}

char topo(estruturaPilha* monte) {
    return monte->primeiro->simbolo;
}

int tamanho(estruturaPilha* monte) {
    return monte->quantidade;
}

int vazia(estruturaPilha* monte) {
    return monte->quantidade == 0;
}

void destruir(estruturaPilha* monte) {
    while(!vazia(monte)) {
        desempilhar(monte);
    }
}

int main() {
    char sequencia[1001];
    int numeroTestes, contador, indice;
    
    scanf("%d", &numeroTestes);
    
    for(indice = 0; indice < numeroTestes; indice++) {
        scanf("%s", sequencia);
        
        if (strchr(sequencia, '<') == NULL && strchr(sequencia, '>') == NULL && 
            strchr(sequencia, ',') == NULL && strchr(sequencia, '.') == NULL) {
            return -1;
        } else {
            estruturaPilha monte;
            iniciar(&monte);
            contador = 0;
            
            char* caracterAtual = sequencia;
            while (*caracterAtual != '\0') {
                switch (*caracterAtual) {
                    case '<':
                        empilhar(&monte, '<');
                        break;
                    case '>':
                        if (!vazia(&monte) && topo(&monte) == '<') {
                            desempilhar(&monte);
                            contador++;
                        }
                        break;
                    default:
                        break;
                }
                caracterAtual++;
            }
            printf("%d\n", contador);
        }
    }
    return 0;
}