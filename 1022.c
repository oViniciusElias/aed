/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int cima;
    int baixo;
} Fracao;

int maximoDivisorComum(int valor1, int valor2) {
    while (valor2 != 0) {
        int auxiliar = valor2;
        valor2 = valor1 % valor2;
        valor1 = auxiliar;
    }
    return valor1;
}

void reduzir(Fracao *fracao) {
    int divisor = maximoDivisorComum(fracao->cima, fracao->baixo);
    fracao->cima /= divisor;
    fracao->baixo /= divisor;
    
    if (fracao->baixo < 0) {
        fracao->cima = -fracao->cima;
        fracao->baixo = -fracao->baixo;
    }
}

Fracao somar(Fracao frac1, Fracao frac2) {
    Fracao resposta;
    resposta.cima = frac1.cima * frac2.baixo + frac2.cima * frac1.baixo;
    resposta.baixo = frac1.baixo * frac2.baixo;
    return resposta;
}

Fracao subtrair(Fracao frac1, Fracao frac2) {
    Fracao resposta;
    resposta.cima = frac1.cima * frac2.baixo - frac2.cima * frac1.baixo;
    resposta.baixo = frac1.baixo * frac2.baixo;
    return resposta;
}

Fracao multiplicar(Fracao frac1, Fracao frac2) {
    Fracao resposta;
    resposta.cima = frac1.cima * frac2.cima;
    resposta.baixo = frac1.baixo * frac2.baixo;
    return resposta;
}

Fracao dividir(Fracao frac1, Fracao frac2) {
    Fracao resposta;
    resposta.cima = frac1.cima * frac2.baixo;
    resposta.baixo = frac2.cima * frac1.baixo;
    return resposta;
}

void mostrarResultado(Fracao original, Fracao reduzida) {
    printf("%d/%d = %d/%d\n", original.cima, original.baixo, reduzida.cima, reduzida.baixo);
}

int main() {
    int quantidadeTestes;
    scanf("%d", &quantidadeTestes);

    for (int indice = 0; indice < quantidadeTestes; indice++) {
        Fracao fracao1, fracao2, resultado;
        char operador;
        scanf("%d / %d %c %d / %d", &fracao1.cima, &fracao1.baixo, &operador, &fracao2.cima, &fracao2.baixo);

        switch (operador) {
            case '+':
                resultado = somar(fracao1, fracao2);
                break;
            case '-':
                resultado = subtrair(fracao1, fracao2);
                break;
            case '*':
                resultado = multiplicar(fracao1, fracao2);
                break;
            case '/':
                resultado = dividir(fracao1, fracao2);
                break;
        }

        Fracao reduzida = resultado;
        reduzir(&reduzida);
        mostrarResultado(resultado, reduzida);
    }

    return 0;
}