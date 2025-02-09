/*A documentação deve sempre explicar o que entra, oq sai e o que é feito com os valores. Por ex:*/

/*Função abaixo pega um valor inteiro n>=1 e um vetor v e devolve o valor do elemento maximo de v.*/
#include <stdio.h>

int Max(int v[], int n){
    int j, x = v[0];
    for (j=1; j<n; j++)
        if (x<v[j]) x=v[j];
    return x;
}
int main(){
    int v[]={1,2,3,4}, j, n;
    n=4;
    j = Max(v,n);
    printf("%d", j);
    return 0;
}

//a documentação deve explicar todos os valores das funções