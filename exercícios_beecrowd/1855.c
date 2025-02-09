/* Vinícius de Oliveira Elias
RA: 176552
Universidade Federal de São Paulo
Exercício AED 
Beecrowd exercício 1897
*/

#include <stdio.h>

int main(){
    int largura, altura;
    char labirinto[100][100];
    int visitado[100][100];

    scanf("%d %d", &largura, &altura);
    for(int linha = 0; linha < altura; linha++) scanf("%s", labirinto[linha]);

    int posX = 0, posY = 0;
    int dirX = 0, dirY = 1; // Direção inicial (para a direita)

    while(1){
        // Verifica se saiu do labirinto
        if(posX < 0 || posX >= altura || posY < 0 || posY >= largura){
            printf("!\n");
            return 0;
        }

        // Verifica se já visitou
        if(visitado[posX][posY]){
            printf("!\n");
            return 0;
        }

        // Marca a posição como visitada
        visitado[posX][posY] = 1;

        // Verifica conteúdo
        if(labirinto[posX][posY] == '*'){
            printf("*\n");
            return 0;
        }

        // Comando a seguir
        switch(labirinto[posX][posY]){
            case '>':
                dirX = 0;
                dirY = 1;
                break;
            case '<':
                dirX = 0;
                dirY = -1;
                break;
            case 'v':
                dirX = 1;
                dirY = 0;
                break;
            case '^':
                dirX = -1;
                dirY = 0;
                break;
            case '.':
                break;
            default:
                printf("!\n");
                return 0;
        }
        posX += dirX;
        posY += dirY;
    }
    return 0;
}