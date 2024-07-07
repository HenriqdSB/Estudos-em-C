//programa para fatorial só que usando recursividade
#include <stdio.h>

int Fatorial(int num);//declarando a função mas sem desenvolve-la de fato, apenas para chamar na main e o compilador aceitar

int main(void){
    int num, n;//numero a ser feito o fatorial
    do{//fiz um do while apenas para digitar quantas vezes eu quisesse, com ele encerrando quando num = 0
        printf("Digite um numero [inteiro] para ser realizado o fatorial:\n");
        printf("N: ");
        scanf("%d", &num);
        printf("%d! = ",num);
        n = Fatorial(num);
        printf("%d\n", n);
    }while (num);
}

int Fatorial(int num){
    if(num == 0){
        return 1;
    }
    else{
        printf("%d ", num);
        if(num-1 == 0)
            printf("= ");
        else
            printf("x ");
        return(num * Fatorial(num-1));
    }
}

/*Creio que para ficar melhor, poderia ser usado um long int/unsigned long int
 porque pode haver números muito grandes, mas como é apenas para tentar entender
 um pouco melhor recursividade, optei por deixar o mais simples possível*/