/* ==============================================
    Ideia geral:
                                 
    1-Cadastrar produtos(cadastrar o cardápio)  
        -pode ser comida ou bebida              
    2-Visualisar o cardápio disponível com        
     o nome e o preço do produto
    3-Opção de retirar algum produto 
     do cardápio
    4-Comprar algo do cardápio
    5-Mostrar o que foi pedido e o total a 
     ser pago(pedir a conta)
        -posteriormente poder ter a opção 
        de dar algum desconto seria ideal
        (de preferencia um desconto fixo)
        que pode ser dado no final ou não
        -após mostrar o resultado é considerado
         pago e o pedido dos produtos devem ser
         excluidos da conta final
    6-Sair do programa e encerrar
   ==============================================
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


typedef struct Produto{
    char nome[45];
    char tipo;//Comida ou Bebida(C/B)
    float valor;//Em R$

}Produto;

const char nomeRestaurante[] = "RESTAURANTE";//Aqui colocamos o nome do restaurante

Produto *produtos = NULL;//Vetor de itens que constarão no cardápio
int quantia_produtos = 0;//Variavel para quantificar os produtos do cardápio(tam do vetor)
Produto *p_pedido = NULL;//Vetor para guardar os itens pedidos pelo cliente
int qtd_p = 0;//Variavel para quantificar os produtos pedidos pelo cliente(tam do vetor de pedidos)
//qtd_p pode ser > quantia_produtos

void MostrarCardapio();
void CadastroItems();
void ExcluirItem();
void PedirItem();
void MostrarTotalPedido();

int main(void){
    int escolha;

    printf("================================================\n");
    printf("\tSeja bem - vindo(a) ao %s\n", nomeRestaurante);
    printf("================================================\n\n");
    do{
        //Menu:
        printf("\n1 - Cadastrar algo para cardapio\n2 - Olhar cardapio\n3 - Excluir item do cardapio\n"
        "4 - Fazer pedido\n5 - Pedir a conta\n6 - Sair\n\n");
        printf("Escolha:\n");
        scanf("%d", &escolha);
        switch (escolha){
            case 1://cadastro
                CadastroItems();
                break;
            case 2://visualização dos itens do cardapio
                if(quantia_produtos){//verificar se tem algum item cadastrado
                    MostrarCardapio();
                }
                else{
                    printf("Sinto muito, o cardapio esta esgotado no momento\n");
                }
                break;
            case 3://excluir algum item do cardapio
                ExcluirItem();
                break;
            case 4://fazer um pedido
                PedirItem();
                break;    
            case 5://pedir a conta
                if(qtd_p){
                    MostrarTotalPedido();
                }
                else{
                    printf("Voce ainda nao fez um pedido, portanto nao tem nada a pagar\n\n");
                }
                break;
            case 6://sair
                printf("Saindo...\n");
                free(produtos);//free p/ liberar memoria, acredito não ser necessário nesse programa, mas usarei do mesmo jeito
                free(p_pedido);
                break;
            default://quando uma opção não for digitada corretamente, ele volta pro menu
                printf("\nEscolha Incorreta tente novamente!\n");
                break;
        }
    }while(escolha != 6);
}

void CadastroItems(){
    produtos = (Produto*)realloc(produtos,(quantia_produtos+1)*sizeof(Produto));
    if(!produtos){
        printf("Ops, algo deu errado");
        exit(1);
    }
    else{
        printf("Digite o nome do prato/bebida:\n");
        scanf(" %44[^\n]", produtos[quantia_produtos].nome);
        printf("Qual o tipo: (comida/bebida):\n");
        scanf(" %c", &produtos[quantia_produtos].tipo);
        produtos[quantia_produtos].tipo = toupper(produtos[quantia_produtos].tipo);
        printf("Preco:\n");
        scanf(" %f", &produtos[quantia_produtos].valor);
        quantia_produtos++;
    }
}

void MostrarCardapio(){
    int i;
    char categoria[45];
    for (i=0; i < quantia_produtos; i++){
        strcpy(categoria, produtos[i].tipo=='C'?"Comida":"Bebida");
        printf("[%d] - Nome: %s\tCategoria: %s\tPreco: %.2f R$\n", i+1, produtos[i].nome,categoria, produtos[i].valor);
    }
}   

void PedirItem(){
    int i;
    char nomeP[45];
    printf("O que deseja? (nome): ");
    scanf(" %44[^\n]", nomeP);
    //verificar se o item existe:
    for(i = 0; i < quantia_produtos; i++){
        if(!strcmp(nomeP, produtos[i].nome)){
            p_pedido = (Produto*)realloc(p_pedido,(qtd_p+1)*sizeof(Produto));
            if(!p_pedido){
                printf("Algo deu errado!\n");
                exit(2);
            }
            p_pedido[qtd_p] = produtos[i];
            qtd_p++;
            printf("\nPedido anotado!\n");
            break;
        }
    }
    if(i==quantia_produtos){
        printf("O pedido nao se encontra no nosso cardapio no momento\n");
    }
}

void ExcluirItem(){
    int i, j;
    char nomeE[45];
    printf("Informe o nome do item a ser excluido:\n");
    scanf(" %44[^\n]", nomeE);
    for (i = 0;i < quantia_produtos; i++){
        if(!strcmp(nomeE, produtos[i].nome)){
            for(j=i;j < quantia_produtos-1;j++){
                produtos[j] = produtos[j+1];
            }
            printf("Produto excluido com sucesso");
            quantia_produtos--;
            break;
        }
    }
    if(i == quantia_produtos){//i==quantia_produtos significa que ele verificou tudo e não achou o nome
        printf("O produto nao consta no cardapio no momento\n");
    }

}

void MostrarTotalPedido(){
    float soma = 0;
    int i;
    for (i = 0; i < qtd_p; i++){
        if(i == 0)
            printf("=================================\n");
        printf("\n- Nome: %s    Valor: %.2f", p_pedido[i].nome, p_pedido[i].valor);
        soma += p_pedido[i].valor;
        if(i+1 == qtd_p){
            printf("\nTotal: %.2f\n", soma);
            printf("=================================\n\n");
        }      
    }
    soma = 0;
    qtd_p = 0;
    free(p_pedido);
}