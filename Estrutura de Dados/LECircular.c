/*Lista Encadeada Circular*/
#include <stdio.h>
#include <stdlib.h>

// struct do nó
typedef struct nodo{
    int inf;
    struct nodo *next;
}NODO;

// lista encadeada circular
typedef NODO *LEC;

// declaracao das funcoes a serem utilizadas:
void criaLista(LEC *); // funcao que cria a referencia externa para a lista
int ehVazia(LEC ); // funcao que retorna 1 se a lista é vazia e 0 se há algum elemento
int tamanho(LEC ); // funcao que retorna o tamanho da lista
void inserirNaLista(LEC *, int, int); // funcao para inserir os elementos na lista
int recuperar(LEC , int ); // funcao que retorna o valor do nodo desejado com base na posicao inserida
void retiraDaLista(LEC *, int ); // função que permite retirar um nodo da lista
void destruirLista(LEC *); // funcao para excluir a lista

// função principal MAIN
int main(void){
    
}

void criaLista(LEC *lista){
    *lista = NULL;
}

int ehVazia(LEC lista){
    return (!lista);
}

int tamanho(LEC lista){
    LEC aux;
    int contador;

    if(!lista){ // se a lista for vazia ja retorna de cara o valor 0
        return 0;
    }
    aux = lista->next; /* aqui aux recebe o primeiro elemento da lista, 
    ja que a lista aponta para o ultimo nodo e o ultimo nodo aponta para o primeiro*/
    for (contador = 1; aux != lista; contador++) // aqui o for só irá parar quando estiver no ultimo elemento
    {
        aux = aux->next;
    }
    return contador;
}

void inserirNaLista(LEC *lista, int pos, int valor){
    int tam = tamanho(*lista);
    NODO *novoNodo;
    // verificar se a posição é válida
    if(pos < 1 || pos > tam+1)
    {
        printf("Erro, a posicao nao eh valida\ntente um intervalo [1, tamanho+1]\n\n");
        exit(2);
    }
    // alocar memoria para o nodo
    novoNodo = (NODO *)malloc(sizeof(NODO));
    if(!novoNodo){
        printf("ERRO, memoria insuficiente\n\n");
        exit(3);
    }
    novoNodo->inf = valor;

    /*Serão 3 casos, primeiro: inserir elemento numa lista vazia; segundo: um 'novo ultimo' na lista,
    ou seja ja existe um elemento que é o ultimo e eu quero adicionar um elemento como ultimo que
    seria a posição k+1, sendo k = tamanho da lista; terceiro caso: um elemento no "meio", um
    elemento que nao será nem o ultimo nem o primeiro*/

    //caso 1:
    if(!*lista)
    {
        novoNodo->next = novoNodo;
        *lista = novoNodo;
    }
    else
    {
        NODO *aux;
        aux = *lista;
        // caso 2:
        if(pos == tam+1)
        {
            *lista = novoNodo;
        }
        //caso 3:
        else
        {
            for(;pos > 1; pos--)
                aux = aux->next; // poderia colocar dentro do for mesmo
        }
        novoNodo->next = aux->next;
        aux->next = novoNodo;
    }
}

int recuperar(LEC lista, int pos){
    if(pos < 1 || pos > tamanho(lista))
    {
        printf("Consulta invalida: posicao inserida nao esta no intervalo de posicoes correto\n\n");
        exit(4);
    }
    //percorre a lista até a posicao desejada
    for(; pos > 0; pos--)
        lista = lista->next;
    return lista->inf;
}

void retiraDaLista(LEC *lista, int pos){
    int tam = tamanho(*lista);
    if(pos < 1 || pos > tam)
    {
        printf("Consulta invalida: posicao inserida nao esta no intervalo de posicoes correto\n\n");
        exit(5);
    }

    /*Analogamente a funcao de inserir elementos, para retirar elementos tambem serão 3 casos
    caso 1: existe apenas um elemento na lista
    caso 2: retirar o ultimo elemento
    caso 3: elemento que não é o ultimo nem o unico da lista*/

    // caso 1
    if(tam == 1)
    {
        free(*lista);
        *lista = NULL;
    }
    else
    {
        NODO *aux, *aux2;
        int p = pos;
        aux = *lista;
        // percorre até a posição do node anterior ao que queremos retirar
        for(;p > 1; aux = aux->next, p--);
        // caso 2
        if(pos == tam)
            *lista = aux;
        // caso 3 e geral
        aux2 = aux->next;
        aux->next = aux2->next;
        free(aux2);
    }

}

void destruir(LEC *lista){ // pode ser LEC lista tambem
    if(*lista)
    {
        LEC aux;
        for (aux = (*lista)->next; aux!=*lista; aux = aux->next) // aux recebe o primeiro nodo e não o ultimo
        {
            free(aux); 
        }
        free(aux); // libera a memória do último nodo
        *lista = NULL; // ao final a lista está vazia apontando para NULL
    }
}