#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 400000

/*Essa função recebe um vetor de tamanho TAM e ordena esse vetor diretamente na memória, não retornando nada*/
void insertion(int v[TAM]) {
    int i, x, j;
    for (i = 1; i < TAM; i++) {
        x = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > x) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = x;
    }
}

/*Essa função recebe vetores crescentes v[l...m-1] e v[m..r-1] e ordena v[l..r-1] em ordem crescente*/
void merge(int l, int m, int r, int v[]) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    if (!L || !R) {
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < n1; i++)
        L[i] = v[l + i];

    for (j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(int v[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(l, m, r, v);
    }
}

void troca(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int part(int vetor[], int baixo, int alto) {
    int pivo = vetor[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[alto]);
    return (i + 1);
}

void quick_sort(int vetor[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = part(vetor, baixo, alto);
        quick_sort(vetor, baixo, pi - 1);
        quick_sort(vetor, pi + 1, alto);
    }
}


void gerar_numeros(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 1000000; 
    }
}

double tempo_insertion(void (*algoritmo)(int[]), int vetor[]) {
    clock_t comeco, fim;
    comeco = clock();
    algoritmo(vetor);
    fim = clock();
    return ((double)(fim - comeco)) / CLOCKS_PER_SEC;
}

double tempo_outros(void (*algoritmo)(int[], int, int), int vetor[], int N) {
    clock_t comeco, fim;
    comeco = clock();
    algoritmo(vetor, 0, N - 1);
    fim = clock();
    return ((double)(fim - comeco)) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL));
    FILE *arquivo = fopen("resultados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    fprintf(arquivo, "Tamanho,Insertion Sort,Merge Sort,Quick Sort\n");

    for (int N = 20000; N <= TAM; N += 20000) {
        int *vetor_original = (int *)malloc(N * sizeof(int));
        int *vetor_aux = (int *)malloc(N * sizeof(int));

        gerar_numeros(vetor_original, N);

        double soma_insertion = 0.0, soma_merge = 0.0, soma_quick = 0.0;

        for (int rodada = 0; rodada < 3; rodada++) {
            copiar_vetor(vetor_original, vetor_aux, N);
            soma_insertion += tempo_insertion(insertion, vetor_aux);

            copiar_vetor(vetor_original, vetor_aux, N);
            soma_merge += tempo_outros(mergeSort, vetor_aux, N);

            copiar_vetor(vetor_original, vetor_aux, N);
            soma_quick += tempo_outros(quick_sort, vetor_aux, N);
        }

        double media_insertion = soma_insertion / 3.0;
        double media_merge = soma_merge / 3.0;
        double media_quick = soma_quick / 3.0;

        fprintf(arquivo, "%d,%.6f,%.6f,%.6f\n", N, media_insertion, media_merge, media_quick);

        free(vetor_original);
        free(vetor_aux);
    }

    fclose(arquivo);
    printf("Resultados gravados em 'resultados.txt'.\n");

    return 0;
}
