//aluno: Vinícius de Oliveira Elias
//RA: 176552
//Exercício AED Sudoku




#include <stdio.h>



#define tamanho 9  // isso vai garantir que o tamanho da matriz é correto

int veri_linha(int matriz[tamanho][tamanho], int linha) {
    int numeros[tamanho + 1] = {0};  
    // isso vai ler os números encontrados na linha
    for (int coluna = 0; coluna < tamanho; coluna++) {
        int numero = matriz[linha][coluna];
        // varifica se o numero é repetido
        if (numero < 1 || numero > 9 || numeros[numero])
            return 0;
        numeros[numero] = 1;
    }
    return 1;
}

// função para verificar se a coluna possui todos os numeros 
int verificar_coluna(int matriz[tamanho][tamanho], int coluna) {
    int numeros[tamanho + 1] = {0};  // guardar os números encontrados na coluna
    for (int linha = 0; linha < tamanho; linha++) {
        int numero = matriz[linha][coluna];
        if (numero < 1 || numero > 9 || numeros[numero])
            return 0; 
        numeros[numero] = 1;
    }
    return 1;  // retorna 1 apenas se a coluna está correta
}

// função para verificar se cada uma das matrizes internas possuem os todos os numeros
int verificar_submatriz(int matriz[tamanho][tamanho], int linha_inicio, int coluna_inicio) {
    int numeros[tamanho + 1] = {0};  // guardar os numeros encontrados
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int numero = matriz[linha_inicio + i][coluna_inicio + j];
            // verifica se é repetido
            if (numero < 1 || numero > 9 || numeros[numero])
                return 0; 
            numeros[numero] = 1; 
        }
    }
    return 1;  // somente retorna 1 se for correto
}

// Função para verificar a matriz completa e as submatrizes 
int verificar_sudoku(int matriz[tamanho][tamanho]) {
    // verifica todas as linhas e colunas
    for (int i = 0; i < tamanho; i++) {
        if (!veri_linha(matriz, i) || !verificar_coluna(matriz, i))
            return 0;  // retorna 0 se algo estiver incorreto
    }
    // verifica as matrizes internas
    for (int linha = 0; linha < tamanho; linha += 3) {
        for (int coluna = 0; coluna < tamanho; coluna += 3) {
            if (!verificar_submatriz(matriz, linha, coluna))
                return 0; 
        }
    }
    return 1;  // retorna 1 se a matriz é uma solução correta para o sudoku
}


//função principal
int main() {
    int numero_matriz;
    scanf("%d", &numero_matriz);  // le o numero de matrizes

    // processa cada matriz de Sudoku
    for (int instancia = 1; instancia <= numero_matriz; instancia++) {
        int matriz[tamanho][tamanho];
        
        // lê os dados da matriz completa
        for (int linha = 0; linha < tamanho; linha++) {
            for (int coluna = 0; coluna < tamanho; coluna++) {
                scanf("%d", &matriz[linha][coluna]);
            }
        }

        // imprime o número da matirz atual
        printf("Instancia %d\n", instancia);
        // verifica se a matriz atual é uma solução
        if (verificar_sudoku(matriz))
            printf("SIM\n");  // imprime "SIM" se for solução
        else
            printf("NAO\n");  // imprime "NAO" não for solução

        printf("\n");  // linha em branco entre as instâncias
    }

    return 0;
}
