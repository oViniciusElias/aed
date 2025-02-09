// Esta função recebe um vetor v[0..n-1]
// e um índice k tal que 0 <= k < n.
// Ela devolve v[k] e remove esse
// elemento do vetor.
#include <stdio.h>

int remo (int k, int n, int v[])
{
   int x = v[k];
   for (int j = k+1; j < n; ++j)  
      v[j-1] = v[j];
   return x;
}
int main(){
    int v[]={1,2,3,4,15,6}, n, x, j;
    n=6;
    x = 3;
    j = remo(x,n,v);
    printf("%d\n", j);
    
    for(int l=0;l<n-1;l++) printf("%d", v[l]);
    return 0;}