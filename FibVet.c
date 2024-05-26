#include <stdio.h>
// F(n) = F(n-1)+F(n-2)
int main(void){
    unsigned long long int Fib[64];//64bits
    unsigned int T, N[100];
    int i, aux=0;
    //a seguir os dois primeiros termos da sequencia de fibonacci que são 0 e 1
    Fib[0] = 0;
    Fib[1] = 1;
    
    for(i=2;i<64;i++){//for para guardar os F(n)s no vetor Fib 
        Fib[i] = Fib[i-1]+Fib[i-2];
    }
    
    scanf("%u", &T);//leitura dos casos de teste
    
    for (i=0; i<T; i++){
        scanf("%u", &N[i]);//for para guardar no vetor N os termos digitados
    }
    
    for (i=0; i<T; i++){
        aux = N[i];
        printf("Fib(%d) = %llu\n", N[i], Fib[aux]);
    }
}