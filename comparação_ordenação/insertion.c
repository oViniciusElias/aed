//Vinícius de Oliveira Elias - 197552 - InsertionSort


#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

#define TAM 400000 //constante que determina o tamanho do vetor


/*Essa função recebe um vetor de tamanho TAM e ordena esse vetor diretamente na memória, não retornando nada*/
void insertion (int v[TAM]) { 
   int i, x, j; 
   for (i = 1; i < TAM; i++) { 
       x = v[i]; 
       j = i-1; 
       while (j >= 0 && v[j] > x) { 
           v[j+1] = v[j]; 
           j = j-1; 
       } 
       v[j+1] = x; 
   } 
} 

int main(){
    clock_t t; 
    int vetor[TAM];
    int a;
    
    
    srand((unsigned)time(NULL) );

    //geração aleatória dos valores do vetor
    for(a = 0; a < TAM; a++)
        vetor[a] = (rand() % (a + 1)) + TAM;

    
    t = clock(); 
    insertion(vetor);
    t = clock() - t; 
    
    printf("Tempo (ms):\n%.0lf\n", ((double)t * 1000)/CLOCKS_PER_SEC);
}
