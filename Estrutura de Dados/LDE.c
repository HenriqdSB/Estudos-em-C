/*AED: LISTA DUPLAMENTE ENCADEADA AULA 7*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int inf; // informação a ser guardada, neste caso um numero inteiro
    struct nodo *ant; // aponta pro nodo anterior (NULL, caso seja o primeiro)
    struct nodo *prox; // aponta pro próximo nodo (NULL, caso seja o ultimo elemento) 
}NODO;

typedef NODO *ListaDE; //Lista Duplamente Encadeada

// funcao que cria lista
void criarLista(ListaDE *lista)
{
    *lista = NULL;
}

// funcao para saber se a lista é vazia ou nao
int eh_vazia(ListaDE lista)
{
    return (!lista); // retorna 1 se a lista é vazia e 0 se ela tem algum elemento
}

// funcao que retorna o tamanho da lista
int tam(ListaDE lista)
{
    int cont = 0; // variavel contadora
    if(!lista) // se a lista é vazia
        return 0;
    while(lista) // lista tem algum elemento
    {
        lista = lista->prox;
        cont++;
    }
    return cont;
}

// funcao para inserir um nodo na lista
void inserir(ListaDE *lista, int pos, int valor)
{
    ListaDE aux;
    NODO *novoNodo;
    // verificar se a posicao eh valida
    if (pos < 1 || pos > tam(*lista)+1)
    {
        printf("Posicao invalida para insercao\n\n");
        exit(2);
    }
    // alocar memoria pro nodo
    novoNodo = (NODO *)malloc(sizeof(NODO));
    // caso a memoria nao seja alocada
    if(!novoNodo)
    {
        printf("Erro, memoria indisponivel\n\n");
        exit(3);
    }
    // caso contrario o codigo segue
    // atribuir o valor ao nodo
    novoNodo->inf = valor;
    /*4 casos a seguir: 1 e 2- Primeiro elemento de uma lista,
    um caso ela é vazia(1) e o outro ja havia pelo menos
    um elemento nela(2);
    caso 3 - O ultimo elemento, que seria n+1 onde n é o numero de nodos da lista, posicoes[1...n];
    caso 4 - "o resto"*/
    if(pos == 1)
    {
        novoNodo->ant = NULL; // o anterior do primeiro elemento sempre é nulo nessa lista
        novoNodo->prox = (*lista); // prox do novo nodo recebe o endereço do antigo primeiro nodo ou Null se a lista for vazia.
        *lista = novoNodo; // lista aponta para o novoNodo
        if((*lista)->prox) // Caso 2
        {
            (*lista)->prox->ant = novoNodo;
        }
    }
    else
    {
        for(aux = *lista; pos > 2; pos--, aux=aux->prox); // movendo a variavel auxliar ate o elemento anterior a posicao que quero inserir
        novoNodo->prox = aux->prox; // o proximo do novo nodo será o o elemento que estava naquela posicao antes, ou null caso seja o ultimo
        novoNodo->ant = aux; // novo tambem aponta pro anterior
        aux->prox = novoNodo; // o proximo do anterior vai ser o novo nodo
        if(novoNodo->prox) // Caso 4
        {
            novoNodo->prox->ant = novoNodo; // acessa o ant do elemento posterior e atribui a ele o endereço do novo nodo
        }
    }
}

// funcao para recuperar um valor
int recupera(ListaDE lista, int pos)
{
    // verifica se a posicao eh valida
    if(pos < 1 || pos > tam(lista))
    {
        printf("Erro consulta invalida\n\n");
        exit(4);
    }
    // percorrer ate a posicao desejada
    for(; pos > 1; lista = lista->prox, pos--);
    return (lista->inf);
}

// funcao para retirar um nodo da lista
void retira(ListaDE *lista, int pos)
{
    ListaDE aux;
    if(pos < 1 || pos > tam(*lista))
    {
        printf("Posicao invalida\n\n");
        exit(5);
    }
    
    /*Caso 1: Primeiro e unico elemento
      Caso 2: Primeiro elemento, mas com outros elementos na lista
      Caso 3: Ultimo elemento da lista
      Caso 4: Um nodo que tem um nodo anterior e um nodo sucessor na lista*/
    if(pos == 1) // caso 1 e 2
    {
        aux = *lista;
        *lista = aux->prox;
        if(*lista) // caso 2
            (*lista)->ant = NULL;
        free(aux);
    }
    else // caso 3 e 4
    {
        // mover ate a posicao que desejo retirar o nodo
        for(aux = *lista; pos>1; aux=aux->prox, pos--);
        aux->ant->prox = aux->prox;
        if(aux->prox) // caso 4
            aux->prox->ant = aux->ant;
        free(aux);
    }
}

// funcao que apaga a lista
void destruir(ListaDE lista)
{
    ListaDE aux;
    while(lista)
    {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

// implementar um funcao para inverter a lista
void inverte(ListaDE *lista)
{
    int t;
    ListaDE aux;
    aux = *lista;
    t = tam(*lista);
    if(*lista)
    {
       for (;t > 1; aux = aux->prox, t--);
        *lista = aux;
        while(aux)
        {
            aux->prox = aux->ant;
            aux->ant = aux->prox;
            aux = aux->prox;
        } 
    }
}

void mostrarLista(ListaDE lista){
    ListaDE l = lista;

    do{
        printf("%3d -> ", l->inf);
        l = l->prox;
    }while(l);

    printf(".\n");
}

// main
int main(void){
    ListaDE lista;

    criarLista(&lista);
    inserir(&lista, 1, 1);
    inserir(&lista, 2, 2);
    inserir(&lista, 3, 3);
    inserir(&lista, 4, 4);
    
    mostrarLista(lista);

    inverte(&lista);

    mostrarLista(lista);

    return 0;
}