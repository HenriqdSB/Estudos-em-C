#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int inf;
  struct node * next;
}Node;

typedef Node * PILHA_ENC;
void criarPilha (PILHA_ENC *);
int its_empty (PILHA_ENC ); // retorna 1 se vazio, 0 se nao
void push (PILHA_ENC *, int ); // coloca elementos na pilha
int top (PILHA_ENC ); // retorna o valor do "topo" da pilha
void pop (PILHA_ENC *); // retira elemento do topo da pilha
int top_pop (PILHA_ENC *);
void destroy (PILHA_ENC );

int main(void)
{
  Node *pilha;
  int n, valor;
  criarPilha(&pilha);
  
  printf("n: ");
  while(scanf("%d", &n), n)
  {
    printf("Digite um valor: ");
    scanf("%d", &valor);
    printf("n: ");
  }
  destroy(pilha);

  return 0;
}

void criarPilha(PILHA_ENC *P)
{
  *P = NULL;
}

int its_empty (PILHA_ENC stack){
  return(!stack);
}

void push (PILHA_ENC *stackptr, int val)
{
  Node *new;
  new = (Node *)malloc(sizeof(Node));
  if(!new){printf("\nErro ao alocar memoria\n");exit(1);}
  new->inf = val;
  new->next = *stackptr;
  *stackptr = new;
}

int top(PILHA_ENC stack)
{
  return (stack->inf);
}

void pop (PILHA_ENC *stackptr)
{
  if(!(*stackptr))
  {
    printf("\nErro, pilha vazia\n");
    exit(2);
  }
  else
  {
    Node *aux = *stackptr;
    *stackptr = (*stackptr)->next;
    free(aux);
  }
}

int top_pop (PILHA_ENC *stack)
{
  if(!(*stack))
  {
    printf("\nErro, pilha vazia\n");
    exit(3);
  }
  else
  {
    int v = (*stack)->inf;
    Node *aux = *stack;
    *stack = (*stack)->next;
    free(aux);
    return (v);
  }
}

void destroy (PILHA_ENC stack)
{
  PILHA_ENC aux;
  while (stack)
  {
    aux = stack;
    stack = stack->next;
    free(aux);
  }
}

