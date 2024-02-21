#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#define N_MESES 3

struct info_produto{
    char nome[200];
    int vendasMes[N_MESES];
    int vmd; //VENDA MEDIA DIARIA
    int tr; //TEMPO DE REPOSIÇÃO
    int eMinimo; //ESTOQUE MINIMO
    int lr; //LOTE DE REPOSIÇÃO
    int eMaximo; //ESTOQUE MAXIMO
    int ea; //ESTOQUE ATUAL
    int decisao; //COMPRAR OU NAO COMPRAR
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

    fflush(stdin);
    printf("Informe o NOME do produto: ");
    gets(produto[id].nome);

    fflush(stdin);

    for(i=0;i<N_MESES;i++){
        printf("Informe o NÚMERO DE VENDAS do %iº mês: ",i+1);
        scanf("%i",&produto[id].vendasMes[i]);
        soma += produto[id].vendasMes[i];
    }
    
    produto[id].vmd = soma/N_MESES; //VENDA MEDIA DIARIA

    printf("Informe o TEMPO DE REPOSIÇÃO (DIAS):");
    scanf("%i",&produto[id].tr);

    produto[id].eMinimo = produto[id].tr * produto[id].vmd; //ESTOQUE MINIMO

    printf("Informe o LOTE DE REPOSIÇÃO:");
    scanf("%i",&produto[id].lr);

    produto[id].eMaximo = produto[id].eMinimo + produto[id].lr;
    
    printf("Informe o ESTOQUE ATUAL:");
    scanf("%i",&produto[id].ea);

}

void exibirProdutos(struct info_produto produto[],int qtd){

    int i;

    printf("==== PRODUTOS CADASTRADOS ====\n");
    printf("\nNOME  |  ESTOQUE  | STATUS");
    for(i=0;i<qtd;i++){
        printf("\n%s | %d",produto[i].nome,produto[i].ea);
        produto[i].ea<produto[i].eMinimo?printf(" | COMPRAR"):printf(" | NÃO COMPRAR");
    }
    printf("\n");
}


int main(){

    struct info_produto produto[200];
    int opcao,nCadastrados=0,continuar;

    setlocale(LC_ALL,"portuguese");

    do{
        opcao = menu();
        switch(opcao){
            
            case 0:
                break;
            case 1:
                exibirProdutos(produto,nCadastrados);
                break;
            default:
                cadastrarProduto(produto,nCadastrados);
                nCadastrados ++;
                break;
        printf("");
        scanf("%i",&continuar);
        }
    }while(opcao!=0);



    return 0;
}