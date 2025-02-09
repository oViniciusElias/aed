/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 2428
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int areas[4];

    for (int i = 0; i < 4; i++) {
        scanf("%d", &areas[i]);
    }

    qsort(areas, 4, sizeof(int), comparar);

    if (areas[0] * areas[3] == areas[1] * areas[2]) {
        printf("S\n");
    } else {
        printf("N\n");
    }

    return 0;
}