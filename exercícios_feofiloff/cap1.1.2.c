/*escrever a documentação correta do vetor*/


#include <stdio.h>
/*essa função recebe um inteiro n e um vetor v, e devolve a soma de todos os elementos de v[0, ... , n-1]*/
int soma(int n, int v[]){
    int i, x=0;
    for (i = 0; i<n; i++) x += v[i];
    return x;
}
int main(){
    int v[]={1,2,3,4,15,6}, j, n;
    n=6;
    j = soma(n,v);
    printf("%d", j);
    return 0;}