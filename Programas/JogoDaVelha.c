#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

//VERSAO PLAYER VS COMPUTADOR

char jogo[3][3];
const char JOGADOR = 'O';
const char COMPUTADOR = 'X';

void LimparJogo();
void MostrarJogo();
void Jogador();
void Computador();
char ChecarVencedor();
void MostrarVencedor(char);
int ChecarEspacosEmBranco(); 

int main(void){
    char op = ' ', w;
    srand(time(NULL));
    printf("\n");
    
    do{
        LimparJogo();
        MostrarJogo();
        do{
            Jogador();
            MostrarJogo();
            Computador();
            MostrarJogo();
            w = ChecarVencedor();

            if(w != ' '){
                MostrarVencedor(w);
            }

        }while(w == ' ' && ChecarEspacosEmBranco() != 0);

        if(w == ' '){
            printf("EMPATE! Ninguem ganhou\n");
        }

        printf("Deseja jogar novamente? [Y/N]: ");
        scanf(" %c", &op);
        op = toupper(op);
        printf("\n");

    }while(op == 'Y');
    printf("Valeu por jogar!\n\n");
    
    return 0;
}

void LimparJogo(){
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            jogo[i][j] = ' ';
        }
    }
}

void MostrarJogo(){
    printf(" %c | %c | %c \n", jogo[0][0], jogo[0][1], jogo[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", jogo[1][0], jogo[1][1], jogo[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", jogo[2][0], jogo[2][1], jogo[2][2]);
    printf("\n\n");
}

void Jogador(){
    int linha, coluna;
    
    do{
        printf("Forneca a coordenada para a linha[1-3]: ");
        scanf("%d", &linha);
        linha--;

        printf("Forneca a coordenada para a coluna[1-3]: ");
        scanf("%d", &coluna);
        coluna--;
        printf("\n");
        if(jogo[linha][coluna] != ' '){
            printf("Coordenada invalida, tente novamente!\n");
        }
        else{
            jogo[linha][coluna] = JOGADOR;
            break;
        }
    }while (jogo[linha][coluna] != ' ' && ChecarEspacosEmBranco() != 0);
}

void Computador(){
    int linha, coluna;
    
    if(ChecarEspacosEmBranco() > 0){
        do{
        linha = rand() % 3;
        coluna = rand() % 3;
    }while (jogo[linha][coluna] != ' ');

        jogo[linha][coluna] = COMPUTADOR;
        printf("\nComputador:\n\n");
    }
    else{
        return;
    }
}

int ChecarEspacosEmBranco(){
    int espacos = 9;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(jogo[i][j] != ' '){
                espacos--;
            }
        }
    }

    return espacos;
}

char ChecarVencedor(){
    int i, j;
    char c = ' ';

    //checando as linhas:
    for(i = 0; i < 3; i++){
        if(jogo[i][0] != ' ' && (jogo[i][0] == jogo[i][1] && jogo[i][0] == jogo[i][2])){
          c = jogo[i][0];
          break;  
        }
    }

    //checando as colunas:
    for(i = 0; i < 3; i++){
        if(jogo[0][i] != ' ' && (jogo[0][i] == jogo[1][i] && jogo[0][i] == jogo[2][i])){
          c = jogo[0][i];
          break;  
        }
    }

    //checando as diagonais:
    
    //checando diagonal principal:
    if(jogo[0][0] != ' ' && (jogo[0][0] == jogo[1][1] && jogo[0][0] == jogo[2][2])){
        c = jogo[1][1];
    }

    //checando diagonal secundaria:
    if(jogo[0][2] != ' ' && (jogo[0][2] == jogo[1][1] && jogo[0][2] == jogo[2][0])){
        c = jogo[1][1];
    }
    
    return c;
}

void MostrarVencedor(char ganhador){
    if(ganhador == COMPUTADOR){
        printf("Voce PERDEU!\n");
    }
    else{//(ganhador == JOGADOR)
        printf("Voce GANHOU!\n");
    }
}
