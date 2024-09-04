/*AULA 08 - 09 - LISTA DUPLAMENTE ENCADEADA CIRCULAR COM NO DE CABEÇALHO*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int inf;
    struct nodo * prox;
    struct nodo * antes;
}NODO;

typedef NODO *LISTA;

void criarLista(LISTA *);
int ehVazia(LISTA );
int tamLista(LISTA );
void inserir(LISTA ,int ,int );
int recuperar(LISTA ,int );
void retirar(LISTA , int );
void destruir(LISTA);
void mostrarLista(LISTA);
void inverterLista(LISTA);

int main()
{
    NODO *lista;
    int p = 1, v = 1;
    criarLista(&lista);
    inserir(lista, 1, 15);
    inserir(lista, 2, 23);
    inserir(lista, 3, 5);
    inserir(lista, 4, 11);
    inserir(lista, 5, 67);
    inserir(lista, 6, 99);
    inserir(lista, 7, 87);
    mostrarLista(lista);

    return 0;
}

void criarLista(LISTA *lista)
{
    *lista = (LISTA)malloc(sizeof(NODO));
    if(!(*lista))
    {
        printf("Erro ao alocar memoria\n\n");
        exit(1);
    }
    (*lista)->inf = 0; // atribuindo o tamanho da lista ao nó cabeçalho
    (*lista)->antes = (*lista)->prox = *lista;
 // o proximo do nó cabeçalho aponta para ele mesmo, e o anterior aponta para ele mesmo também
}

int ehVazia(LISTA lista)
{
    return (!(lista->inf));
}

int tamLista(LISTA lista)
{
    return (lista->inf);
}

void inserir(LISTA lista, int posicao, int valor)
{
    NODO *novoNodo, *aux;
    int t = tamLista(lista);
    if(posicao < 1 || posicao > tamLista(lista)+1)
    {
        printf("Erro, posicao invalida\n\n");
        exit(2);
    }
    novoNodo = (LISTA)malloc(sizeof(NODO));
    if(!novoNodo)
    {
        printf("Erro ao alocar memoria\n\n");
        exit(3);
    }
    novoNodo->inf = valor;

    if(posicao <= (lista->inf)/2)
    {
        for(aux=lista;posicao>1;aux=aux->prox, posicao--);
        novoNodo->prox = aux->prox;
        novoNodo->antes = aux;
        aux->prox = novoNodo;
        novoNodo->prox->antes = novoNodo;
    }
    else
    {
        for(aux=lista;posicao <= lista->inf;aux=aux->antes, posicao++);
        novoNodo->antes = aux->antes;
        novoNodo->prox = aux;
        aux->antes = novoNodo;
        novoNodo->antes->prox = novoNodo;
    }
    
    lista->inf++;
}

int recuperar(LISTA lista, int posicao)
{
    int t = tamLista(lista);
    if(posicao < 1 || posicao > tamLista(lista))
    {
        printf("Erro, posicao digitada eh invalida\n\n");
        exit(4);
    }
    if(posicao <= t/2) 
        for(;posicao>0;posicao--,lista=lista->prox);
    else // se a posicao for maior que a metade da lista, se percorrer a lista a partir do ultimo node fica mais rapido
        for(;posicao <= t; posicao++, lista=lista->antes); /* posicao <= t por exemplo quando for o ultimo node
        ele vai mover uma vez o antecessor de NC que é o ultimo node e parar*/
    return(lista->inf);
}

void retirar(LISTA lista, int posicao)
{
    LISTA aux; // poderia ser NODO*
    int t = tamLista(lista);
    if(posicao < 1 || posicao > tamLista(lista))
    {
        printf("Posicao digitada eh invalida\n\n");
        exit(5);
    }
    /*Poderia ser usado a propria lista sem necessidade de uma variavel auxiliar, só
    seria preciso atualizar lista->inf antes de mover para o nó a ser retirado
    entao poderia ser por ex:
        lista->inf--;
        for(;posicao>0;posicao--,lista=lista->prox); */
    lista->inf--;
    if(posicao <= t/2)
    {
        for(aux = lista;posicao > 0;posicao--);
            aux = aux->prox;
    }
    else
    {
        for(aux = lista;posicao < t;posicao++);
            aux = aux->antes;
    }
    // as operações serão as mesmas para todos os casos
    aux->antes->prox = aux->prox;
    aux->prox->antes = aux->antes;
    free(aux); 
}

void destruir(LISTA lista)
{
    NODO *aux;
    int tam = lista->inf;
    do
    {
        aux = lista;
        lista = lista->prox;
        free(aux);
    } while (tam--);
    //free(lista);
    //lista->inf=0;
}

void mostrarLista(LISTA lista)
{
    int t = lista->inf;
    while(t--)
    { 
        lista = lista->prox;
        printf("%d -> ", lista->inf);
        
    }
    
}

void inverterLista(LISTA l)
{
    int t = tamLista(l);
    if (t > 1)
    {
        NODO *aux;
        for (t++; t; l = l->antes,t--)
        {
            aux = l->antes;
            l->antes = l->prox;
            l->prox = aux;
        }
    }
}