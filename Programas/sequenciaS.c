/*
A sequência S é definida por recorrência por
1. S(1) = 1
2. S(n) = n * S(n-1) para n>=2

Construa um programa que receba uma lista de inteiros positivos,
representando posições de elementos na sequência e retorne na saída
padrão os respectivos valores da sequência. A lista de
posições será finalizada pelo valor zero. Não é
necessário validar as entradas.
Exemplo de entrada: Exemplo de saída:
4                  / 24
2                  / 2
0

*/
#include <stdio.h>

unsigned int Sequencia(unsigned int S);

int main(void){
    unsigned int n;
    do{
        printf("Entrada: ");
        scanf("%lu", &n);
        if(n){
            printf("\nSaida: %lu\n\n", Sequencia(n));
        }
    }while(n);
}

unsigned int Sequencia(unsigned int S){
    if(S == 1){
        return 1;
    }
    else
        return (S * Sequencia(S-1));
}