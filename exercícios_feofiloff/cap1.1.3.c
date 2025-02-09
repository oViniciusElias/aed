/*escrever a documentação correta do vetor*/


#include <stdio.h>
/*essa função recebe um inteiro n>0, um inteiro j e um vetor v, e devolve a posição do elemento j em v[0, ... , n-1]*/
int onde(int x, int v[], int n){
    int j=0;
    while (j < n && v[j] != x) j += 1;
    return j;
}
int main(){
    int v[]={1,2,3,4,15,6}, n, x, j;
    n=6;
    x = 3;
    j = onde(x,v,n);
    printf("%d", j);
    return 0;}