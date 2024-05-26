/*Leia a hora inicial, minuto inicial, hora final e minuto final de um jogo. A seguir calcule a duração do jogo.

Obs: O jogo tem duração mínima de um (1) minuto e duração máxima de 24 horas.

Entrada
Quatro números inteiros representando a hora de início e fim do jogo.

Saída
Mostre a seguinte mensagem: “O JOGO DUROU XXX HORA(S) E YYY MINUTO(S)” .*/
#include<stdio.h>
int main(void){
    int Hi, Hf, Mi, Mf, SaidaHoras, SaidaMinutos;
    scanf("%d %d %d %d", &Hi, &Mi, &Hf, &Mf);
    if(Hi==Hf){
        SaidaHoras=0;
        if(Mi==Mf){
            SaidaMinutos = 0;
            SaidaHoras = 24;
        }
        else{
            if(Mi>Mf){
                SaidaHoras=23;
                SaidaMinutos = Mi - Mf;
                SaidaMinutos = 60 - SaidaMinutos;
            }
            else{
                SaidaMinutos = Mf - Mi;
            }
        }
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", SaidaHoras, SaidaMinutos);
    }
    else{
        if(Hi>Hf){
            SaidaHoras = Hi - Hf;
            SaidaHoras = 24 - SaidaHoras;
            if(Mi==Mf){
                SaidaMinutos = 0;
            }
            else{
                if(Mi>Mf){
                    SaidaMinutos = Mi-Mf;
                    SaidaMinutos = 60 - SaidaMinutos;
                    SaidaHoras = SaidaHoras - 1;//linha adicionada só depois que percebi que havia erro em alguns casos
                }
                else{
                    SaidaMinutos = Mf-Mi;
                }
            }
        }
        else{
            SaidaHoras = Hf-Hi;
            if(Mi==Mf){
                //SaidaHoras+=1; erro nessa parte
                SaidaMinutos = 0;
            }
            else{
                if(Mi>Mf){
                    SaidaMinutos = Mi-Mf;
                    SaidaMinutos = 60-SaidaMinutos;
                    SaidaHoras = SaidaHoras - 1;
                }
                else{
                    SaidaMinutos = Mf-Mi;
                    
                    
                }
            }
        }
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", SaidaHoras, SaidaMinutos);
    }
}