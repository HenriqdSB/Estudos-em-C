//Deus-serpente M'boi e as Cataratas do Iguaçu
#include<stdio.h>

int main(void){
    int Vkmh, i, hsaida = 19, horas, flag = 1;
    unsigned long int extensaoRio;
    int minutos;
    scanf("%lu", &extensaoRio);
    scanf("%d", &Vkmh);

    horas = extensaoRio/Vkmh;
    horas += hsaida;
    
    if(Vkmh<10){
        if(extensaoRio%Vkmh == 0){
            minutos = extensaoRio%Vkmh;
            minutos = (minutos*60)/10;
        }
        else{
            minutos = extensaoRio/Vkmh;
            minutos ++;
            minutos = (minutos*60)/100;
        }
    }
    else{
        minutos = extensaoRio%Vkmh;
        minutos = (minutos*60)/10;
    }

    while (flag){
        flag = 0;
        if (horas >= 24)
        {
            horas-=24;
            flag = 1;
        }
        
    }
    
    if(minutos > 60){
        minutos -= 59;
    }
    printf("%02d:%02d\n", horas, minutos);
    return 0;
}