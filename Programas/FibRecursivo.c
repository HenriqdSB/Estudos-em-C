#include <stdio.h>

int Fibonacci(int n){
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else{
        return Fibonacci(n-1)+Fibonacci(n-2);
    }
    
}

int main(){
    int n;
    do{
        printf("\nFibonacci de: ");
        scanf("%d", &n);
        printf("\nO fibonacci de %d eh %d\n\n", n, Fibonacci(n));
    }while(n);
}