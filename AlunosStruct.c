#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Nreg 5

/*fazer um registro de alunos*/

typedef struct{
    char nome[100], nascimento[10];
    float CR;
    unsigned long int CPF, matricula;
}Alunos;

/* ---declarando as funções que iremos usar---*/
void InicializaVet (Alunos *vetor);
void Imprimir_A_Pos (Alunos *vetor, unsigned int);
void Imprimir_A_CPF (Alunos *vetor, unsigned long int );

/*>>>Função principal main<<<*/
int main(void){
    Alunos A[Nreg];
    unsigned int i;
    unsigned long int cpf;
    InicializaVet(A);
    printf("\nPosicao Desejada do registro do aluno a ser mostrada: ");
    scanf("%u", &i);
    Imprimir_A_Pos(A, i);
    printf("\nCPF do registro que deseja buscar: ");
    scanf("%lu", &cpf);
    Imprimir_A_CPF(A, cpf);
}

/*<<<Função para inicializar um vetor de registros de um aluno>>>*/
void InicializaVet(Alunos *A){
    int i;
    for (i=0; i < Nreg; i++){
        printf("\n\n=-=-=-=-=-=-= Registro de N[%d] =-=-=-=-=-=\n", i+1);
        printf("\nDigite seu nome: ");
        scanf(" %99[^\n]", A[i].nome);
        printf("\nData de nascimento(DD/MM/AA): ");
        scanf(" %s", A[i].nascimento);
        printf("\nCPF(apenas numeros): ");
        scanf("%lu", &A[i].CPF);
        printf("\nMatricula: ");
        scanf("%lu", &A[i].matricula);
        printf("\nSeu CR: ");
        scanf("%f", &A[i].CR);
    }
    printf("\n=-=-=-=-=-=-=   <<<<FIM>>>>   =-=-=-=-=-=-=\n");
}

/*<<<Função que retorna um registro de acordo com a posição solicitada na Main>>>*/
void Imprimir_A_Pos(Alunos *A, unsigned int i){
    if (i > Nreg || !i){
        printf("\nERRO!, a posicao eh inválida!");
        exit(1);
    }else{
        printf("\n->->->Iprimindo Registro do Aluno %d...\n", i);
        printf("\nNome do Aluno[%d]: %s\n", i, A[i-1].nome);
        printf("Data de Nascimento: %s\n", A[i-1].nascimento);
        printf("CPF: %lu\n", A[i-1].CPF);
        printf("Numero da Matricula: %lu\n", A[i-1].matricula);
        printf("Coeficiente de Rendimento(CR): %.2f\n", A[i-1].CR);
        printf("\n<<<< FIM >>>>\n");
    }
}

/*<<<Função que retorna um registro de acordo com o cpf fornecido na main,
 é claro se o cpf fizer parte de algum dos alunos registrados>>>*/
void Imprimir_A_CPF(Alunos *A, unsigned long int cpf){
    int i, ver;
    for (i=0; i<Nreg; i++){
        if(A[i].CPF == cpf){
            ver = i;
            break;
        }
    }
    if(i==Nreg){
        printf("\nO CPF digitado não foi encontrado em nossos registros\n"); 
        exit(1); 
    }else{
        printf("\n->->->Iprimindo Registro do Aluno...\n");
        printf("\nNome do Aluno: %s\n", A[ver].nome);
        printf("Data de Nascimento: %s\n", A[ver].nascimento);
        printf("Numero da Matricula: %lu\n", A[ver].matricula);
        printf("Coeficiente de Rendimento(CR): %.2f\n", A[ver].CR);
        printf("\n<<<< FIM >>>>\n");
    }
}