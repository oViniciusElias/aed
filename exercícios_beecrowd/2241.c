/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 2241
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAX 501

int tabuleiro[TAMANHO_MAX][TAMANHO_MAX];
int prefixo_preto[TAMANHO_MAX][TAMANHO_MAX];
int prefixo_branco[TAMANHO_MAX][TAMANHO_MAX];

int obter_soma(int matriz[TAMANHO_MAX][TAMANHO_MAX], int x1, int y1, int x2, int y2) {
    return matriz[x2+1][y2+1] - matriz[x1][y2+1] - matriz[x2+1][y1] + matriz[x1][y1];
}

int main() {
    int tamanho, pecas;
    scanf("%d %d", &tamanho, &pecas);
    memset(tabuleiro, 0, sizeof(tabuleiro));
    memset(prefixo_preto, 0, sizeof(prefixo_preto));
    memset(prefixo_branco, 0, sizeof(prefixo_branco));
    for (int i = 0; i < pecas; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        tabuleiro[r][c] = 1; 
    }
    for (int i = 0; i < pecas; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        tabuleiro[r][c] = 2; 
    }
    for (int i = 1; i <= tamanho; i++) {
        for (int j = 1; j <= tamanho; j++) {
            prefixo_preto[i][j] = prefixo_preto[i-1][j] + prefixo_preto[i][j-1] - prefixo_preto[i-1][j-1] + (tabuleiro[i][j] == 1 ? 1 : 0);
            prefixo_branco[i][j] = prefixo_branco[i-1][j] + prefixo_branco[i][j-1] - prefixo_branco[i-1][j-1] + (tabuleiro[i][j] == 2 ? 1 : 0);
        }
    }
    int contagem_preta = 0;
    int contagem_branca = 0;
    
    for (int tamanho = 1; tamanho <= tamanho; tamanho++) {
        for (int i = 0; i <= tamanho - tamanho; i++) {
            for (int j = 0; j <= tamanho - tamanho; j++) {
                int soma_preta = obter_soma(prefixo_preto, i, j, i + tamanho - 1, j + tamanho - 1);
                int soma_branca = obter_soma(prefixo_branco, i, j, i + tamanho - 1, j + tamanho - 1);
                if (soma_preta > 0 && soma_branca == 0) {
                    contagem_preta++;
                } else if (soma_branca > 0 && soma_preta == 0) {
                    contagem_branca++;
                }
            }
        }
    }
    printf("%d %d\n", contagem_preta, contagem_branca);
    return 0;
}