#include <stdio.h>
#define NL 7
#define NC 4
int main(void){
    float matriz[NL][NC];
    int i,j;

    for (i=0; i<7; i++){
        for (j=0; j<NC; j++){
            printf("\nDigite um valor para a matriz[%d][%d]: ",i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }

    for (i=0;i<NL;i++){
        printf("\n|");
        for (j=0; j<NC;j++){
            printf("%10.2f", matriz[i][j]);
        }
        printf(" |");
    }
}