#include <stdio.h>
#include <stdlib.h>
//Algoritmo da Divisão ou Teorema da Divisão Euclidiana.
int main(void){
    int a, b, quociente, resto, eq;

    scanf("%d %d", &a, &b);
    if (b==0){
        break;
    }

    resto = a%b;

    if(resto < 0){
        eq = abs(b);
        resto = eq - abs(resto);
    }
    quociente = (a - resto)/b;
    printf("%d %d\n", quociente, resto);
}