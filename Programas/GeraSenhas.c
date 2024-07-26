//programa simples que gera uma senha com o tamanho solicitado
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// tamanho minimo ideal de senha
//#define MIN_TAM_S 8


char especiais[] = {'!','@', '#', '$', '%', '.','&','*','(', ')', '-', '_', '+','=',
                    '[', ']', '{', '}', '?', ':', ';', '<', '>'};

char numeros[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char letras[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x',
                    'y','z'};

void mostrarOpcoes(){
    printf("Digite o Tamanho da senha(0 - Sair): ");
}

void gerarSenha(int tamanhoS);

char senhas[50];

int main(void){
    
    int tamanhoSenha, escolha;
    srand(time(NULL));
    printf("Seja bem vindo ao gerador de senhas\n");
    printf("Caracteres padrao ASCII\n");

    do{
        mostrarOpcoes();
        scanf("%d", &tamanhoSenha);
        gerarSenha(tamanhoSenha);
        senhas[tamanhoSenha] = '\0';
        printf("%s\n", senhas);
    }while(tamanhoSenha != 0);
    

    return 0;
}

void gerarSenha(int tamanhoS){
    int i, c;
    for (i=0;i<tamanhoS;i++){
        c = rand() % 10 + 1;
        // 1-2 para especiais[], 3-4 para numeros[], 5-10 para letras[]
        if(c <= 2){
            senhas[i] = especiais[rand() % sizeof(especiais)];
        }
        else if(c > 2 && c <= 4){
            senhas[i] = numeros[rand() % sizeof(numeros)];
        }
        else{
            //decide se sera minuscula ou maiuscula
            c = rand() % 2;
            //maiuscula
            if(!c){
                senhas[i] = toupper(letras[rand() % sizeof(letras)]);
            }
            //minuscula
            else{
                senhas[i] = letras[rand() % sizeof(letras)];
            }
        }
        
    }
    
}
