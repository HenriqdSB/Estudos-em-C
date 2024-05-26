/*Cada piscada do corvo comunica um número em binário. Um olho aberto significa 1 e um olho 
fechado significa 0. 
O olho da esquerda é o mais significativo e o da direita é o menos significativo.
 A cada piscada, este número deve ser somado, e quando o corvo grita, essa soma é um resultado.*/
#include <stdio.h>
#include <string.h>

int main(void){

    int contador, i, soma;
    char cawcaw[10];

    soma = 0;
    contador=3;

    while (contador){
        scanf(" %[^\n]", cawcaw);

        if (strlen(cawcaw) > 3){
            printf("%d\n", soma);
            soma = 0;
            contador --;
        }
        else{
            for (i = 0; i < 3; i++){
                if (cawcaw[i] == '*'){
                    if (i == 0)
                        soma = soma + 4;
                    else if (i == 1)
                        soma = soma + 2;
                    else
                        soma = soma + 1;
                }
            }
        }
    }
}