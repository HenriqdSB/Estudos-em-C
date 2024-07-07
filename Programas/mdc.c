/*Algoritmo de Euclides usando recursão*/

#include <stdio.h>

int mdc(int n_a, int n_b){//função que realizará o MDC dos numeros inteiros
    int resto;
    resto = n_a%n_b;//primeiro obtenho o resto da divisão
    if(resto){//se o resto for verdadeiro, ou seja, não for zero
        n_a = n_b;
        n_b = resto;//a passa a ser b e b vai receber o resto
        mdc(n_a,n_b);//novamente a função é chamada, para fazer a verificação ou determinação do mdc
    }
    else//se o resto = 0
        return n_a<n_b?n_a:n_b;//a expressão retorna o menor numero, que vai ser o mdc
}

int main(void){
    int a, b;
    printf("\n\n-=-=-=-=-=-=-=-=-=-=-=Bem-vindo a calculadora de MDC=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\nDigite dois numeros que deseja calcular o MDC: ");
    scanf("%d %d", &a, &b);
    printf("\nResultado:\tO MDC de %d e %d eh: %d\n\n", a,b,mdc(a,b));// no printf é chamada a função e o resultado é o MDC.
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
}

/*Um algoritmo mais simples ainda e sem muito enfeite:
#include <stdio.h>

// Função recursiva para calcular o MDC
int mdc(int a, int b) {
    if (b == 0) {
        return a; // Caso base: quando b for zero, a é o MDC
    } else {
        return mdc(b, a % b); // Chamada recursiva com b e o resto da divisão a por b
    }
}
int main() {
    int a, b;
    printf("Digite dois numeros para realizar o MDC: ");
    scanf("%d %d", &a, &b);
    printf("O MDC de %d e %d é %d\n", a, b, mdc(a, b));
    return 0;
}*/