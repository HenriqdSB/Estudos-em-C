#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node * father; // N� pai ou raiz
    struct node * left; // N� filho � esquerda
    struct node * right; // N� filho � direita
}NODE;

typedef NODE * ARV_BIN_ENC;

void maketree (ARV_BIN_ENC *, int); // Cria a arvore
void setleft (ARV_BIN_ENC , int); // Seta um n� filho � esquerda
void setright (ARV_BIN_ENC , int); // Seta um n� filho � direita
int info (ARV_BIN_ENC); // Retorna um valor de um n�
ARV_BIN_ENC left (ARV_BIN_ENC); // Retorna o endere�o do n� a esquerda
ARV_BIN_ENC right (ARV_BIN_ENC); // Retorna o endere�o do n� � direita
ARV_BIN_ENC father (ARV_BIN_ENC); // Retorna o n� pai
ARV_BIN_ENC brother (ARV_BIN_ENC); // Retorna o endere�o do n� irm�o, caso n�o haja n� irm�o, retorna NULL
int isleft (ARV_BIN_ENC); // Retorna 1 se o n� � um filho a esquerda
int isrigth (ARV_BIN_ENC); // Retorna 1 se o n� for um filho a direita

int main (void) {

    return 0;
}

void maketree (ARV_BIN_ENC *t, int v)
{
    *t = (ARV_BIN_ENC)malloc(sizeof(NODE));
    if(!(*t)){printf("ERRO, memoria insuficiente.\n");exit(1);}
    (*t)->info = v;
    (*t)->father = NULL; // Como estamos criando basicamente a raiz, ela n�o ter� o n� pai
    (*t)->left = NULL;
    (*t)->right = NULL;
}

void setleft (ARV_BIN_ENC t, int v)
{
    t->left = (ARV_BIN_ENC) malloc (sizeof(NODE));
    if(!(t->left)){printf("ERRO, memoria insuficiente.\n");exit(2);}
    t->left->info = v;
    t->left->right = NULL;
    t->left->left = NULL;
    t->left->father = t;
}

void setright (ARV_BIN_ENC t, int v)
{
    t->right = (ARV_BIN_ENC) malloc (sizeof(NODE));
    if(!(t->right)){printf("ERRO, memoria insuficiente.\n");exit(2);}
    t->right->info = v;
    t->right->left = NULL;
    t->right->right = NULL;
    t->right->father = t;
}

int info (ARV_BIN_ENC t)
{
    return (t->info);
}

ARV_BIN_ENC left (ARV_BIN_ENC t)
{
    return (t->left);
}

ARV_BIN_ENC right (ARV_BIN_ENC t)
{
    return t->right;
}

ARV_BIN_ENC father (ARV_BIN_ENC t)
{
    return t->father;
}

ARV_BIN_ENC brother (ARV_BIN_ENC t)
{
    if (father(t))
    {
        if (isleft(t)) // if t->father->left == t
            return (t->father->right);
        else
            return (t->father->right);
    }
    return NULL;
}

int isleft (ARV_BIN_ENC t)
{
    if(!(t->father)) // verificando se h� um n� pai
        return 0;
    if (t->father->left == t)
        return 1;
    return 0;
}

int isright (ARV_BIN_ENC t)
{
    if(t->father)
        return (!isleft(t));
    return 0;
}