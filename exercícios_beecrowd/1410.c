/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1410
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int numAtacantes, numDefensores, posAtacantes[11], posDefensores[11];

    while (scanf("%d %d", &numAtacantes, &numDefensores)) {
        if (!numAtacantes && !numDefensores)
            break;

        for (int i = 0; i < numAtacantes; ++i) {
            scanf("%d", &posAtacantes[i]);
        }

        for (int i = 0; i < numDefensores; ++i) {
            scanf("%d", &posDefensores[i]);
        }

        qsort(posAtacantes, numAtacantes, sizeof(int), comparar);
        qsort(posDefensores, numDefensores, sizeof(int), comparar);

        int atacante = posAtacantes[0];
        int penultimo = posDefensores[1];

        printf("%c\n", atacante < penultimo ? 'Y' : 'N');
    }

    return 0;
}