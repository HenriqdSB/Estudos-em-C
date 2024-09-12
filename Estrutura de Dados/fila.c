#include <stdio.h>
#include <stdlib.h>
#define MAX 25
typedef struct fila
{
    int N; // N é o tamanho da lista
    int inicio;
    int fim; 
    int val[MAX];
}filaSeq;

void criar_fila(filaSeq *);
int eh_vazia(filaSeq *);
int tam(filaSeq *);
void ins(filaSeq *, int);
int cons(filaSeq *);
void ret(filaSeq *);
int cons_ret (filaSeq *);
void gerarFila(filaSeq *F, int m, int n);

int main(void)
{

    return 0;
}

void criar_fila(filaSeq *F)
{
    F->N = F->inicio = 0;
    F->fim = -1;    
}

int eh_vazia(filaSeq *F)
{
    return(F->N == 0);
}

int tam(filaSeq *F)
{
    return (F->N);
}

void ins(filaSeq *Fila, int val)
{
    if(Fila->N == MAX){
        printf("Impossivel inserir, lista cheia\n\n"); exit(1);
    }
    Fila->fim = ((Fila->fim)+1) % MAX;
    Fila->val[Fila->fim] = val;
    Fila->N++;
}

int cons(filaSeq *Fila)
{
    if(eh_vazia(Fila))
    {
        printf("Operacao invalida, fila vazia\n\n");
        exit(2);
    }
    return(Fila->val[Fila->inicio]);
}

void ret(filaSeq *F)
{
    if(eh_vazia(F))
    {
        printf("Erro, fila vazia\n\n");
        exit(3);
    }
    F->inicio = ((F->inicio)+1)%MAX;
    F->N--;
}

int cons_ret(filaSeq *F)
{
    if(eh_vazia(F))
    {
        printf("Erro, lista vazia\n\n");
        exit(4);
    }
    else
    {
        int valor = F->val[F->inicio];
        F->inicio = ((F->inicio)+1)%MAX;
        F->N--;
        return valor;
    }
}

void gerarFila(filaSeq *F, int m, int n)
{
    if(n > m)
    {
        printf("ERRO, intervalo invalido\n\n");
        exit(5);
    }
    else
    {
        if(m==n)
        {
            criar_fila(F);
            ins(F, m);
        }
        else
        {
            geraFila(F, m, n-1);
            ins(F, n);
        }
    }
}