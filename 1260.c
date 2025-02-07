/* Vinícius de Oliveira Elias
    RA: 176552
    Universidade Federal de São Paulo
    Exercício AED 
    Beecrowd exercício 1260
    */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define TAM_MAX_NOME 31
    #define TAM_MAX_ESPECIES 10000

    typedef struct {
        char nome[TAM_MAX_NOME];
        int quantidade;
    } Especie;

    void trocar(Especie *a, Especie *b) {
        Especie temp = *a;
        *a = *b;
        *b = temp;
    }

    void ordenacaoRapida(Especie arr[], int esquerda, int direita) {
        if (esquerda >= direita)
            return;

        int indicePivo = esquerda + (direita - esquerda) / 2;
        Especie pivo = arr[indicePivo];
        int i = esquerda;
        int j = direita;

        while (i <= j)
        {
            while (strcmp(arr[i].nome, pivo.nome) < 0) i++;

            while (strcmp(arr[j].nome, pivo.nome) > 0) j--;

            if (i <= j) {
                trocar(&arr[i], &arr[j]);
                i++;
                j--;
            }
        }

        if (esquerda < j)
            ordenacaoRapida(arr, esquerda, j);
        if (i < direita)
            ordenacaoRapida(arr, i, direita);
    }

    int main() {
        int casosTeste;
        char buffer[TAM_MAX_NOME];
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &casosTeste);

        fgets(buffer, sizeof(buffer), stdin);

        while (casosTeste--) {
            Especie listaEspecies[TAM_MAX_ESPECIES];
            int contagemEspecies = 0;
            int totalArvores = 0;

            for (int i = 0; i < TAM_MAX_ESPECIES; i++) {
                listaEspecies[i].quantidade = 0;
                listaEspecies[i].nome[0] = '\0';
            }

            while (fgets(buffer, sizeof(buffer), stdin)) {
                buffer[strcspn(buffer, "\n")] = '\0';

                if (strlen(buffer) == 0)
                    break;

                int encontrado = 0;
                for (int i = 0; i < contagemEspecies; i++) {
                    if (strcmp(listaEspecies[i].nome, buffer) == 0) {
                        listaEspecies[i].quantidade++;
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    strcpy(listaEspecies[contagemEspecies].nome, buffer);
                    listaEspecies[contagemEspecies].quantidade = 1;
                    contagemEspecies++;
                }

                totalArvores++;
            }

            ordenacaoRapida(listaEspecies, 0, contagemEspecies - 1);

            for (int i = 0; i < contagemEspecies; i++) {
                double porcentagem = (listaEspecies[i].quantidade * 100.0) / totalArvores;
                printf("%s %.4lf\n", listaEspecies[i].nome, porcentagem);
            }

            if (casosTeste > 0)
                printf("\n");
        }

        return 0;
    }