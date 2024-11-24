/*exercício para testar boa documentação, formatação e for*/

#include <stdio.h>

/*esse algoritimo recebe um valor inteiro e devolve os seis proximos numeros impares*/
int main(){
 
    int X;
    scanf("%d", &X);
    if (X % 2 !=0){
        X--;}

    for(int i=6; i>0; i--){
        printf("%d\n",X+1);
        X=X+2;}
            
    return 0;

}
