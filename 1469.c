/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1469
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVERTICES 500 
#define CONECTADO 1
#define DESCONECTADO 0
#define ESTADO_INICIAL 0
#define ESTADO_PROCESSANDO 1
#define ESTADO_FINALIZADO 2
#define INVALIDO -1

int tempoAtual;
int idadeMinima;
char grafo[MAXVERTICES + 1][MAXVERTICES + 1];
int totalVertices;
int estado[MAXVERTICES + 1];
int descoberta[MAXVERTICES + 1];
int conclusao[MAXVERTICES + 1];
int anterior[MAXVERTICES + 1];
int idadeFuncionarios[MAXVERTICES + 1];

void visitaGrafo(int verticeAtual) {
    estado[verticeAtual] = ESTADO_PROCESSANDO;
    tempoAtual++;
    descoberta[verticeAtual] = tempoAtual;

    for(int proximo = 1; proximo <= totalVertices; proximo++) {
        if(grafo[verticeAtual][proximo] == CONECTADO) {
            if(estado[proximo] == ESTADO_INICIAL) {
                if (idadeFuncionarios[proximo] < idadeMinima) 
                    idadeMinima = idadeFuncionarios[proximo];
                anterior[proximo] = verticeAtual;
                visitaGrafo(proximo);
            }
        }
    }

    estado[verticeAtual] = ESTADO_FINALIZADO;
    tempoAtual++;
    conclusao[verticeAtual] = tempoAtual;
}

void buscaProfundidade(int inicial) {
    idadeMinima = 1000;
    
    for(int i = 1; i <= totalVertices; i++) {
        estado[i] = ESTADO_INICIAL;
        descoberta[i] = INVALIDO;
        conclusao[i] = INVALIDO;
        anterior[i] = INVALIDO;
    }

    tempoAtual = 0;
    
    if(estado[inicial] == ESTADO_INICIAL)
        visitaGrafo(inicial);
}

void inicializaGrafo() {
    memset(grafo, DESCONECTADO, sizeof(grafo));
}

void trocaPosicoes(int pos1, int pos2) {
    int temp;
    for (int i = 1; i <= totalVertices; i++) {
        temp = grafo[pos1][i];
        grafo[pos1][i] = grafo[pos2][i];
        grafo[pos2][i] = temp;
    }

    for (int i = 1; i <= totalVertices; i++) {
        temp = grafo[i][pos1];
        grafo[i][pos1] = grafo[i][pos2];
        grafo[i][pos2] = temp;
    }
}

int main() {
    int qtdPessoas, qtdRelacoes, qtdInstrucoes;
    int funcionarioAtual;
    
    while (scanf("%d %d %d", &qtdPessoas, &qtdRelacoes, &qtdInstrucoes) != EOF) {
        inicializaGrafo();
        totalVertices = qtdPessoas;

        for (int i = 1; i <= qtdPessoas; i++) {
            scanf("%d", &idadeFuncionarios[i]);
        }

        int superior, subordinado;
        for (int i = 1; i <= qtdRelacoes; i++) {
            scanf("%d %d", &superior, &subordinado);
            grafo[subordinado][superior] = CONECTADO;
        }

        char comando;
        for (int i = 1; i <= qtdInstrucoes; i++) {
            scanf(" %c", &comando);

            if (comando == 'P') {
                scanf("%d", &funcionarioAtual);
                buscaProfundidade(funcionarioAtual);
                printf("%d\n", idadeMinima == 1000 ? '*' : idadeMinima);
            }
            if (comando == 'T') {
                scanf("%d %d", &superior, &subordinado);
                trocaPosicoes(superior, subordinado);
            }
        }
    }
    return 0;
}