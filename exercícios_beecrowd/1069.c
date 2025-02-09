/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int verificar(char expressao[]){
    int contador;
    int a = strlen(expressao);
    for(int i=0; i < a;i++){
        if (expressao[i] == '('){
            contador++;
        }
        else if (expressao[i]==')'){
                contador--;
            }
            if (contador<0){
                return 0;
            }   
        }
    return contador == 0;
}



int main() {
    char n[1000];
    scanf("%s", n);
    int ver = verificar(n);
    if (ver==1){printf("correct");}
    else(printf("incorrect"));  


    return 0;
}
