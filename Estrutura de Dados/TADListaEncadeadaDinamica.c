#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int info;
    struct Nodo *next;
}NODO;

typedef NODO * LISTA_ENC;

// funcoes de lista encadeada:
void cria_lista (LISTA_ENC *); 
int eh_vazia (LISTA_ENC);
int tam (LISTA_ENC);
void insert (LISTA_ENC *pl, int pos, int val);
int recupera (LISTA_ENC list, int k);
void retira (LISTA_ENC *pl, int pos);
void destruir (LISTA_ENC );
int pertence (LISTA_ENC lista, int val);
int eh_ord (LISTA_ENC lista);
void gera_lista(LISTA_ENC *ptl, int m, int n);

// funcoes usando recursao:
void ins_rec (LISTA_ENC *pt_l, int pos, int val);
int tam_rec (LISTA_ENC lista);
void retira_rec (LISTA_ENC *pl, int pos);
int recupera_rec (LISTA_ENC list, int pos);
void destruir_rec (LISTA_ENC lista);
int pertence_rec (LISTA_ENC lista, int val);
int eh_ord_rec (LISTA_ENC lista);

int main(void)
{
  
}

void cria_lista(LISTA_ENC *List){
    *List = NULL;
}

int eh_vazia(LISTA_ENC list){
    return (list == NULL);
}

int tam (LISTA_ENC list){
    int cont;
    for(cont = 0; list != NULL; cont++)
    {
        list = list->next;
    }
    return cont;
}

void insert(LISTA_ENC *pl, int pos, int val)
{
    NODO *novoNodo;
    // verificar se a posicao eh valida
    if(pos < 1 || pos > tam(*pl) + 1){
        printf("ERRO\nPosicao Invalida\n\n");
        exit(1);
    }   
    novoNodo = (NODO *) malloc(sizeof(NODO));
    // espaço foi alocado corretamente?
    if(!novoNodo){
        printf("ERRO, nao foi possivel alocar memoria\n\n");
        exit(2);
    }
    novoNodo->info = val; 
    // caso for o primeiro nodo
    if(pos == 1){
        novoNodo->next = *pl;
        *pl = novoNodo;
    }
    else{
        LISTA_ENC aux;
        for (aux = *pl; pos > 2; aux = aux->next, pos--);
        novoNodo->next = aux->next;
        aux->next = novoNodo;
    }
}

int recupera(LISTA_ENC list, int k)
{
    if (k < 1 || k > tam(list)){
        printf("Erro ao consultar\n\n");
        exit(3);
    }

    for(;k>1; k--)
        list = list->next;
    return list->info;    
}

void retira(LISTA_ENC *pl, int pos)
{
    NODO *aux;
    if(pos < 1 || pos > tam(*pl))
    {
        printf("Erro, posicao invalida\n\n");
        exit(4);
    }

    // se for o primeiro nodo
    if(pos == 1){
        aux = *pl;
        *pl = aux->next;
        free(aux);
    }

    else
    {
        NODO *aux2;
        for (aux = *pl; pos > 2; pos--, aux = aux->next);
        aux2 = aux->next;
        aux->next = aux2->next;
        free(aux2);
    }
}

void destruir(LISTA_ENC lista)
{
    LISTA_ENC aux;
    while(lista)
    {
        aux = lista;
        lista = lista->next;
        free(aux);
    }
}

void ins_rec(LISTA_ENC *pt_l, int pos, int val)
{
    if(pos < 1 || pos > tam(*pt_l))
    {
        printf("Erro, posicao invalida\n\n");
        exit(5);
    }
    if(pos == 1)
    {
        NODO *novoNodo;
        novoNodo = (NODO *)malloc(sizeof(NODO));
        if(!novoNodo){printf("Erro, memoria nao foi alocada\n\n");exit(6);}
        novoNodo->info = val;
        novoNodo->next = *pt_l;
        *pt_l = novoNodo;
    }
    else
    {
        return(ins_rec(&((*pt_l)->next), pos-1, val));
    }
}

int tam_rec (LISTA_ENC lista)
{
    if(!lista) // se nao houver elementos na lista
    {
        return 0;
    }
    else
    {
        return (1 + tam_rec(lista->next));
    }
}

void retira_rec (LISTA_ENC *pl, int pos)
{
    
    if(pos < 1 || pos > tam(*pl)){printf("Erro, posicao invalida\n\n");
        exit(7);
    }
    
    if (pos == 1)
    {
        NODO *aux;
        aux = *pl;
        *pl = aux->next;
        free(aux);
    }

    else
    {
        return retira_rec(&((*pl)->next), pos-1);
    }
}

int recupera_rec (LISTA_ENC list, int pos)
{
    if (pos < 1 || pos > tam(list)) {
        printf("Erro, posicao invalida\n\n");
        exit(8);
    }

    if (pos == 1) {
        return list->info;
    }
    else {
        return(recupera_rec(list->next, pos-1));
    }
}

void destruir_rec(LISTA_ENC lista)
{
    if(lista){
        destruir_rec(lista->next);
        free(lista);
    }
}

int pertence (LISTA_ENC lista, int val)
{
    while(lista)
    {
        if(lista->info == val)
            return 1;
        lista = lista->next;
    }   
    return 0;
}

int pertence_rec (LISTA_ENC lista, int val)
{
    if (lista){    
        if(lista->info == val)
            return 1;
        return (pertence_rec(lista->next, val));
    }
    return 0;
}

int eh_ord (LISTA_ENC lista)
{
    if(eh_vazia(lista) || tam(lista) == 1)
        return 1;
    do
    { 
        if(lista->info > (lista->next)->info)
            return 0;
        lista = lista->next;
    }while(lista->next);
    return 1;
}

int eh_ord_rec (LISTA_ENC lista)
{
    if(!lista || (lista && !(lista->next)))
        return 1;
    if(lista->info > (lista->next)->info)
        return 0;
    return eh_ord_rec(lista->next);
}

void gera_lista(LISTA_ENC *ptl, int m, int n)
{
    if(m > n)
    {
        printf("Erro, intervalo invalido\n\n");
        exit(9);
    }
    if(m == n){
        cria_lista(ptl);
        insert(ptl, m, 1);
    }

    else{
        return (gera_lista(ptl, m+1, n));
        insert(ptl, m, 1);
    }

}
