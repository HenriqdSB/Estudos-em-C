#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct
{
    int top;
    int val[MAX];
}PilhaSeq;

void criaPilha (PilhaSeq *); // cria a pilha
int ehVazia (PilhaSeq *); // verifica se é vazia
void push (PilhaSeq *, int ); // empilha um valor
int top (PilhaSeq *); // retorna o valor do topo
void pop (PilhaSeq *); // retira um valor da pilha
int topPop (PilhaSeq *); // retorna o valor do topo e retira ele

int main(){

    return 0;
}

void criaPilha (PilhaSeq *stack)
{
    stack->top = -1;
}

int ehVazia (PilhaSeq *stack)
{
    return(stack->top == -1);
}

void push (PilhaSeq *stack, int v)
{
    if (stack->top == MAX-1)
    {
        printf("\nErro, estouro na pilha\n");
        exit(1);
    }
    stack->val[++(stack->top)] = v;
}

int top (PilhaSeq *stack)
{
    if (ehVazia(stack))
    {
        printf("Erro, consulta indisponivel\nmotivo: pilha vazia.\n\n");
        exit(2);
    }
    return(stack->val[stack->top]);
}

void pop (PilhaSeq *stack)
{
    if (ehVazia(stack))
    {
        printf("Erro! Pilha vazia.\n\n");
        exit(3);
    }
    stack->top--;
}

int topPop (PilhaSeq *stack)
{
    if (ehVazia(stack))
    {
        printf("Erro! Pilha vazia\n\n");
        exit(4);
    }
    else
    {
        int va = stack->val[stack->top];
        stack->top--;
        return(va);
    }
}