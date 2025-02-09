//Vinícius de Oliveira Elias - 197552 - MergeSort



#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

#define TAM 400000 //constante que determina o tamanho do vetor


/*Essa função recebe vetores crescentes v[l...m-1] e v[m..r-1] e ordena v[l..r-1] em ordem crescente*/
void merge(int l, int m, int r, int v[])
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    
    if (!L || !R) {
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < n1; i++)
        L[i] = v[l + i];

    for (j = 0; j < n2; j++)
        R[j] = v[m + 1+ j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]){
            v[k] = L[i];
            i++; }
        else
        {v[k] = R[j];
        j++;    }
        k++;}

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        v[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(int v[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(l, m, r, v);
    }
}


int main(){
    clock_t t; 
    int *vetor = (int *)malloc(TAM * sizeof(int));
    int a;
    
    
    srand((unsigned)time(NULL) );

    //geração aleatória dos valores do vetor
    for(a = 0; a < TAM; a++)
        vetor[a] = (rand() % (a + 1)) + TAM;

    
    t = clock(); 
    mergeSort(vetor, 0, TAM-1);
    t = clock() - t; 
    
    printf("Tempo (ms):\n%.0lf\n", ((double)t * 1000)/CLOCKS_PER_SEC);
    free(vetor);
}
