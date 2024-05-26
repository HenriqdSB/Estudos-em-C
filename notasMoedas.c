#include <stdio.h>

int main(void)
{
    double dinheiro;
    int valorInt, moedasInt, notas=100;

    do
    {
        printf("Digite aqui o valor: ");
        scanf("%lf", &dinheiro);
    }while (dinheiro<0);

    valorInt = dinheiro;
    moedasInt = (dinheiro-valorInt)*100;
    if ((valorInt%100==1)||(valorInt%50==1)||(valorInt%20==1)||(valorInt%10==1)||(valorInt%5==1)||(valorInt%2==1)){
        moedasInt = moedasInt +100;
    }
    if ((valorInt%2==0)&&(valorInt%5!=0)){
        moedasInt = moedasInt+100;
    }
    printf("NOTAS:\n");
    do
    {
        printf("%d nota(s) de R$ %d.00\n", (valorInt/notas), notas);
        valorInt = valorInt%notas;
        notas /= 2;
        
        if (notas==25)
            notas = 20;
        if (notas==1){
            break;
        }
    } while (notas);
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", moedasInt/100);
    moedasInt = moedasInt%100;
    printf("%d moeda(s) de R$ 0.50\n", moedasInt/50);
    moedasInt = moedasInt%50;
    printf("%d moeda(s) de R$ 0.25\n", moedasInt/25);
    moedasInt = moedasInt%25;  
    printf("%d moeda(s) de R$ 0.10\n", moedasInt/10);
    moedasInt = moedasInt%10;
    printf("%d moeda(s) de R$ 0.05\n", moedasInt/5);
    moedasInt = moedasInt%5;
    printf("%d moeda(s) de R$ 0.01\n", moedasInt/1);
    return 0;
}