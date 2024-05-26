//questão de prova antiga de algoritmos
#include<stdio.h>
#define tam 10
int main(void){
    int armazem[tam][tam], i, j, soma=0, maior=0, n=0;
    for (i=0; i<tam; i++){
        for (j=0; j<tam; j++){
            printf("\nDigite para o armazem[%d] a qtd do %do produto: ", i+1, j+1);
            scanf("%d", &armazem[i][j]);
            soma += armazem[i][j];
            if (j==1){
                if (maior<armazem[i][j]){
                    maior = armazem[i][j];
                    n = i+1;
                }
            }
        }
        printf("\nO armazem[%d], contem %d itens\n", i+1, soma);
        soma = 0;
    }
    printf("\nO armazem com maior quantidade do produto 2 eh o armazem[%d] com %d unidades do produto 2", n, maior);
}