#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int inf;
    struct node * next;
}Node; // estrutura basica do node
typedef struct 
{
    Node * Ini; // aponta para o inicio da fila
    Node * Fim; // aponta para o fim da fila
}Descritor; // no de cabeçalho da fila
typedef Descritor * FILA; //fila encadeada
void cria_fila(FILA *);
int eh_vazia(FILA );
void ins(FILA, int);
int cons(FILA );
void ret(FILA );
int cons_ret(FILA );
void destruir(FILA );

int main(void)
{


    return 0;

}

void cria_fila(FILA *Fila)
{
    *Fila = (Descritor *)malloc(sizeof(Descritor));
    if(!*Fila)
    {
        printf("Erro, memoria insuficiente\n\n");
        exit(1);
    }
    (*Fila)->Ini = NULL;
    (*Fila)->Fim = NULL;
}

int eh_vazia(FILA F)
{
    return (F->Ini == NULL);
}

void ins(FILA F, int V)
{
    Node *novo;
    novo = (Node *)malloc(sizeof(Node));
    if(!novo)
    {
        printf("Erro, memoria insuficiente\n\n");
        exit(2);
    }
    novo->inf = V;
    novo->next = NULL; // como na fila os elementos só são adicionados ao final, todo node novo apontará para NULL
    if(eh_vazia(F))
    {
        F->Ini = novo;
    }
    else
    {
        F->Fim->next = novo;
    }
    F->Fim = novo;
}

int cons(FILA F)
{
    if(eh_vazia(F))
    {
        printf("Erro, a lista eh vazia\n\n");
        exit(3);
    }
    return(F->Ini->inf);
}

void ret(FILA F)
{
    if(eh_vazia(F)){printf("Erro, a lista eh vazia\n\n");exit(4);}
    else
    {
        Node*aux=F->Ini;
        F->Ini=F->Ini->next;
        if(!F->Ini){F->Fim=NULL;}
        free(aux);
    }
}

int cons_ret(FILA F)
{
    if(eh_vazia(F))
    {
        printf("Erro, lista vazia\n\n");
        exit(5);
    }
    else
    {
        Node *aux = F->Ini;
        int v = F->Ini->inf;
        F->Ini = F->Ini->inf;
        if(!F->Ini){F->Fim=NULL;}
        free(aux);
        return(v);
    }
}

void destruir(FILA F)
{
    Node *aux;
    while(F->Ini)
    {
        aux = F->Ini;
        F->Ini = F->Ini->next;
        free(aux);
    }
    free(F);
}