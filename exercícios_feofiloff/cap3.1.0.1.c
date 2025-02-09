// A função recebe x, n >= 0 e v e devolve
// um índice k em 0..n-1 tal que x == v[k]. 
// Se tal k não existe, devolve -1.

int busca(int x, int n, int v[])
{
   int k;
   k = n-1;
   while (k >= 0 && v[k] != x) 
      k -= 1;
   return k;
}
int main(){
    int v[]={1,2,3,4,15,6}, n, x, j;
    n=6;
    x = 8;
    j = busca(x,n,v);
    printf("%d", j);
    return 0;}