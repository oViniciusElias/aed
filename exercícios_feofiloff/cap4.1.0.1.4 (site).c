//Tamanho de célula.  Compile e execute o seguinte programa:

#include <stdio.h>
#include <stdlib.h>

int main (){

    struct reg
    {
        int conteudo;
        struct reg *prox;        
    };
    typedef struct reg celula;

    
    printf ("sizeof (celula) = %d\n", 
            sizeof (celula));
    
    return 0;


}