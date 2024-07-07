//exercicio 1024 do beecrowd
#include<stdio.h>
#include<string.h>
int main(void){
	int N, i, j, tam;
	char Mensagem[1000], aux;
	scanf("%d", &N); //Input dos casos de teste
	while(N--)
	{
	    scanf(" %999[^\n]", Mensagem);
	    tam = strlen(Mensagem);
	    //primeira passada(mover letras maiusculas e minusculas para a direita 3 posiçoes de acordo com a tabela ascii)
	    for (i=0; i<tam; i++){
		    if (Mensagem[i] != ' ' && ((Mensagem[i] > 64 && Mensagem[i] < 91) || (Mensagem[i] > 96 && Mensagem[i] < 123))){
			    Mensagem[i] += 3;
		    }
	    }
	    //segunda passada(inverter a string)
	    for (i=0; i< (tam/2); i++){
	        aux = Mensagem[i];
	        Mensagem[i] = Mensagem[tam - i - 1];
	        Mensagem[tam- i - 1] = aux;
	    }
	    Mensagem[tam] = '\0';
	    //terceira passada - inverter todo caractere da metade da string em diante
	    for (i = tam/2; i < tam; i++){
	        Mensagem[i] = Mensagem[i] - 1;
	    }
	    puts(Mensagem);
	}
}
