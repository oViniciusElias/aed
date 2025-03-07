
/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1110
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdlib.h>
#include <stdio.h>

struct dequeNo{
    int valor;
    struct dequeNo *anterior, *proximo;
};

struct deque{
    int tamanho;
    struct dequeNo *frente, *tras;
};

void push_front(struct deque* d, int valor){
    d->tamanho += 1;
    struct dequeNo* novoNo = (struct dequeNo*) malloc(sizeof(struct dequeNo));
    novoNo->valor = valor;
    novoNo->anterior = NULL;
    novoNo->proximo = d->frente;

    if(d->frente != NULL){
        d->frente->anterior = novoNo;
    }
    d->frente = novoNo;

    if(d->tras == NULL){
        d->tras = novoNo;
    }
}

void push_back(struct deque* d, int valor){
    d->tamanho += 1;
    struct dequeNo* novoNo = (struct dequeNo*) malloc(sizeof(struct dequeNo));
    novoNo->valor = valor;
    novoNo->anterior = d->tras;
    novoNo->proximo = NULL;

    if(d->tras != NULL){
        d->tras->proximo = novoNo;
    }
    d->tras = novoNo;

    if(d->frente == NULL){
        d->frente = novoNo;
    }
}

void pop_front(struct deque* d){
    if(d->tamanho > 0){
        d->tamanho -= 1;
        struct dequeNo* velhaFrente = d->frente;
        d->frente = velhaFrente->proximo;
        free(velhaFrente);
    }
}

void pop_back(struct deque* d){
    if(d->tamanho > 0){
        d->tamanho -= 1;
        struct dequeNo* velhoTras = d->tras;
        d->tras = velhoTras->anterior;
        free(velhoTras);
    }
}

int front(struct deque* d){
    return d->frente->valor;
}

int back(struct deque* d){
    return d->tras->valor;
}

int size(struct deque* d){
    return d->tamanho;
}

int empty(struct deque* d){
    return d->tamanho == 0;
}

void inicializa(struct deque* d){
    d->tamanho = 0;
    d->frente = NULL;
    d->tras = NULL;
}

void destroi(struct deque* d){
    while(!empty(d)){
        pop_front(d);
    }
}

int main()
{
    int n, first;
    struct deque cartas;

    while (scanf("%d", &n))
    {
        if (!n)
            break;

        inicializa(&cartas);

        for (int i = 1; i <= n; ++i)
        {
            push_back(&cartas, i);
        }

        first = 1;
        printf("Discarded cards: ");
        while (size(&cartas) > 1)
        {
            if (!first)
                printf(", ");
            else
                first = 0;

            printf("%d", front(&cartas));

            pop_front(&cartas);
            push_back(&cartas, front(&cartas));
            pop_front(&cartas);
        }
        printf("\nRemaining card: %d\n", front(&cartas));

        destroi(&cartas);
    }

    return 0;
}