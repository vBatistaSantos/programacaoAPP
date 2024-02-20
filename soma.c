#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define N_MESES 3

struct info_produto{
    char nome[200];
    int vendasMes[N_MESES];
    int vmd; //VENDA MEDIA DIARIA
    int tr; //TEMPO DE REPOSI��O
    int eMinimo; //ESTOQUE MINIMO
    int lr; //LOTE DE REPOSI��O
    int eMaximo; //ESTOQUE MAXIMO
    int ea; //ESTOQUE ATUAL
};


int menu(){

    int opcao;

    printf("====== MENU ======\n");
    printf("\n1 - EXIBIR PRODUTOS\n");
    printf("2 - CADASTRAR PRODUTO\n");
    printf("0 - SAIR\n");
    scanf("%d",&opcao);

    return opcao;
}

void cadastrarProduto(struct info_produto produto[],int id){

    int i, soma=0;

    printf("Informe o NOME do produto: ");
    gets(produto[id].nome);

    fflush(stdin);

    for(i=0;i<N_MESES;i++){
        printf("Informe o N�MERO DE VENDAS do %i� m�s: ",i+1);
        scanf("%i",&produto[id].vendasMes[i]);
        soma += produto[id].vendasMes[i];
    }
    
    produto[id].vmd = soma/N_MESES; //VENDA MEDIA DIARIA

    printf("Informe o TEMPO DE REPOSI��O:");
    scanf("%i",&produto[id].tr);

    produto[id].eMinimo = produto[id].tr * produto[id].vmd; //ESTOQUE MINIMO

    printf("Informe o LOTE DE REPOSI��O:");
    scanf("%i",&produto[id].lr);

    produto[id].eMaximo = produto[id].eMinimo + produto[id].lr;
    
    printf("Informe o ESTOQUE ATUAL");
    scanf("%i",&produto[id].ea);

}

void exibirProdutos(struct info_produto produto[],int qtd){

    int i;

    printf("==== PRODUTOS CADASTRADOS ====\n");
    printf("\nNOME | ESTOQUE");
    for(i=0;i<qtd;i++){
        printf("\n%s | %d",produto[i].nome,produto[i].ea);
    }
    printf("\n");
}


int main(){

    struct info_produto produto[200];
    int opcao,nCadastrados=0;

    setlocale(LC_ALL,"portuguese");

    do{
        opcao = menu();

    

        switch(opcao){
            
            case 0:
                break;
            default:
                cadastrarProduto(produto,nCadastrados);
                nCadastrados ++;
                break;
            

        }
    }while(opcao!=0);



    return 0;
}