/* Lista Encadeada com Nó de cabeçalho */
#include <stdio.h>
#include <stdlib.h>

// struct do nodo
typedef struct nodo{
    int inf;
    struct nodo *next;
}NODO;

typedef NODO *LENC; // cria o tipo no de cabeçalho da lista

// Declaracao das funcoes a serem implementadas
void criaLista(LENC *); // funcao que cria a lista encadeada com no de cabeçalho
int ehVazia(LENC ); // retorna 1 se alista for vazia e 0 se houver algum elemento
int tamL(LENC ); // retorna o tamanho da lista encadeada
void inserir(LENC , int , int ); // lista, pos, valor | insere um elemento na lista, posicoes validas de 1...n(tamanho+1)
int recup(LENC , int); // lista, pos | recupera um valor de acordo com a posicao
void retiraDaLista(LENC, int ); // lista e posiçao do nó
void destruir(LENC ); // destruir a lista

// Funcao Main
int main(void)
{
    // testando a implementação de inserir e retirar da lista
    NODO *head, *headAux;
    criaLista(&head);

    inserir(head, 1, 1);
    inserir(head, 2, 2);
    inserir(head, 3, 3);
    headAux = head->next;
    while(headAux)
    {
        printf("%d -> ", headAux->inf);
        headAux = headAux->next;
    }
    printf("NULL");
    printf("\n");
    
    retiraDaLista(head, 2);

    headAux = head->next;
    while(headAux)
    {
        printf("%d -> ", headAux->inf);
        headAux = headAux->next;
    }
    printf("NULL"); // esse printf serve apenas para mostrar que o ultimo nodo aponta para nada(NULL)
    printf("\n");
    return 0;
}

// Corpo das funções

void criaLista(LENC *lista)
{
    /*Nesse tipo de lista(uma cabeça da lista), ela funciona como um nó, um nó que aponta para o primeiro nó por isso temos que alocar memoria para ela como se fosse um nó*/
    *lista = (NODO *)malloc (sizeof(NODO));
    if(!*lista)
    {
        printf("Erro ao alocar memoria\n\n");
        exit(2);
    }
    (*lista)->inf = 0; // aqui guardamos o tamanho da lista
    (*lista)->next = NULL; // endereço do proximo elemento da lista, como é a cabeça da lista, ela sempre aponta para o primeiro elemento da lista, ao criar a lista ela tem 0 elementos, logo ela aponta para NULL

}

int ehVazia(LENC lista)
{
    return (lista->inf == 0);
}

int tamL(LENC lista)
{
    return (lista->inf);
}

void inserir(LENC lista, int pos, int valor)
{
    NODO *aux, *novoNodo;
    if(pos < 1 || pos > tamL(lista)+1) // no lugar da funcao tamL poderia ser simplesmente lista->inf, ja que esta variavel guarda o tamanho da lista
    {
        printf("Erro, posicao invalida\n\n");
        exit(3);
    }

    novoNodo = (NODO *)malloc(sizeof(NODO));
    if(!novoNodo)
    {
        printf("Erro, memoria nao pode ser alocada para o nodo\n\n");
        exit(4);
    }

    novoNodo->inf = valor;

    for(aux = lista; pos > 1; pos--)
    {
        aux = aux->next;
    }
    novoNodo->next = aux->next;
    aux->next = novoNodo;
    lista->inf+=1;

}

int recup(LENC lista, int pos)
{
    if(pos < 1 || pos > tamL(lista))
    {
        printf("Erro, consulta invalida\n\n");
        exit(5);
    }
    for(;pos > 0; pos--)
        lista = lista->next;
    return lista->inf;
}

void retiraDaLista(LENC lista, int pos)
{
    if (pos < 1 || pos > tamL(lista))
    {
        printf("Err0, posicao nao eh valida\n\n");
        exit(6);
    }
    NODO *aux1, *aux2; // variaveis auxiliares
    aux1 = lista;
    for(;pos > 1; pos--) // movendo para o nó anterior ao nó que quero retirar
        aux1 = aux1->next;
    aux2 = aux1->next;
    aux1->next = aux2->next;
    free(aux2); // libero a memoria do nó

}

void destruir(LENC lista)
{
    LENC aux;
    while(lista)
    {
        aux = lista;
        lista = lista->next;
        free(aux);
    }
}
