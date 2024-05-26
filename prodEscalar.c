#include<stdio.h>
//Programa para calcular o produto escalar entre dois vetores de duas coordenadas
int main(void){
    int A[2], B[2], i, soma=0;//aqui declaro vetor A e B ambos com duas coordenadas cada
    for (i=0; i<2; i++){
        //aqui vamos ler os valores para A e B
        printf("\nDigite a coordenada para A%d e para B%d: ", i+1, i+1);
        scanf("%d %d", &A[i], &B[i]);
        soma = soma + (A[i]*B[i]);//aqui a variavel soma vai somando os resultados dos produtos entre as coordenadas
    }
    printf("\nProduto escalar entre A(%d, %d) e B(%d, %d)= %d", A[0], A[1], B[0], B[1],soma);
}