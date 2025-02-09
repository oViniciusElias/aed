/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 3263
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char textoPrimeiro[1024], textoSegundo[1024];
    int quantidadeOperacoes, indice;

    scanf("%d\n%s\n%s\n", &quantidadeOperacoes, textoPrimeiro, textoSegundo);

    quantidadeOperacoes %= 2;

    if(!quantidadeOperacoes){
        if(!strcmp(textoPrimeiro, textoSegundo)){
            printf("Deletion succeeded\n");
        }else{
            printf("Deletion failed\n");
        }
    }else{
        for(indice = 0; indice < strlen(textoPrimeiro); ++indice){
            if(textoPrimeiro[indice] == textoSegundo[indice]){
                printf("Deletion failed\n");
                break;
            }
        }
        if(indice == strlen(textoPrimeiro))  printf("Deletion succeeded\n");
    }

    return 0;
}