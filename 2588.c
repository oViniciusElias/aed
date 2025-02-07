/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 2588
*/

#include <stdio.h>
#include <string.h>

#define TAMANHO_MAXIMO 1000

int minLetrasAdicionar(char sequencia[]) {
    int frequencia[26] = {0}; 
    int contadorImpar = 0; 
    
    for (int i = 0; i < strlen(sequencia); i++) {
        frequencia[sequencia[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (frequencia[i] % 2 != 0) {
            contadorImpar++;
        }
    }

    return (contadorImpar == 0) ? 0 : contadorImpar - 1;
}

int main() {
    char sequencia[TAMANHO_MAXIMO];

    while (scanf("%s", sequencia) != EOF) {
        printf("%d\n", minLetrasAdicionar(sequencia));
    }

    return 0;
}