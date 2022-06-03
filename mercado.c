#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 500
#include "mercado.h"
#include <time.h>

void logo(void)
{
    printf("\n");
    printf("    =============================================================================================");
    printf("\n");
    printf("\n");
    printf("    *             #     # ####### ######   #####     #    ######  #######                       * \n");
    printf("    *             ##   ## #       #     # #     #   # #   #     # #     #                       * \n");
    printf("    *             # # # # #       #     # #        #   #  #     # #     #                       *\n");
    printf("    *             #  #  # #####   ######  #       #     # #     # #     #                       * \n");
    printf("    *             #     # #       #   #   #       ####### #     # #     #                       * \n");
    printf("    *             #     # #       #    #  #     # #     # #     # #     #                       * \n");
    printf("    *             #     # ####### #     #  #####  #     # ######  #######                       * \n");
    printf("    *                                                                                           *\n");
    printf("    *                                                                                           *\n");
    printf("    *         TTTTTTT   AAA   BBBBB     AAA       JJJ   AAA   RRRRRR    AAA                     * \n");
    printf("    *           TTT    AAAAA  BB   B   AAAAA      JJJ  AAAAA  RR   RR  AAAAA                    * \n");
    printf("    *           TTT   AA   AA BBBBBB  AA   AA     JJJ AA   AA RRRRRR  AA   AA                   * \n");
    printf("    *           TTT   AAAAAAA BB   BB AAAAAAA JJ  JJJ AAAAAAA RR  RR  AAAAAAA                   * \n");
    printf("    *           TTT   AA   AA BBBBBB  AA   AA  JJJJJ  AA   AA RR   RR AA   AA                   * \n");
    printf("    *                                                                                           *\n");
    printf("    *                                                                Desenvolvido por:          *\n");
    printf("    *                                                                      Eduardo Araujo       *\n");
    printf("    *                                                                      Rafael Felipe        *\n");
    printf("    *                                                                      Ramias Lopes         *\n");
    printf("    =============================================================================================");
    printf("\n");
    printf("\n");
    system("color 1");
}

void data(void)
{
    char ds[7][4] = {"Dom", "Seg", "Ter", "Qua", "Qui", "Sex", "Sab"};
    struct tm tempo;
    time_t tempoSeg;

    time(&tempoSeg);
    tempo = *localtime(&tempoSeg);

    struct dataAtual dataDeCadastro;

    dataDeCadastro.dia = tempo.tm_mday;
    dataDeCadastro.mes = tempo.tm_mon + 1;
    dataDeCadastro.ano = tempo.tm_year + 1900;
    dataDeCadastro.h = tempo.tm_hour;
    dataDeCadastro.m = tempo.tm_min;
    dataDeCadastro.s = tempo.tm_sec;

    printf("\t\t\t     Dia %02d/%02d/%d (%s) %02d:%02d:%02d Horas \n\n", dataDeCadastro.dia, dataDeCadastro.mes, dataDeCadastro.ano, ds[tempo.tm_wday], dataDeCadastro.h, dataDeCadastro.m, dataDeCadastro.s);
}

void salvarDataDeCadastroNoVetorProdutos(Produto *p[], int posicao)
{
    // GERAR DATA E HORA ATUAL
    struct tm tempo;
    time_t tempoSeg;
    time(&tempoSeg);
    tempo = *localtime(&tempoSeg);
    struct dataAtual minhaData;
    minhaData.dia = tempo.tm_mday;
    minhaData.mes = tempo.tm_mon + 1;
    minhaData.ano = tempo.tm_year + 1900;
    minhaData.h = tempo.tm_hour;
    minhaData.m = tempo.tm_min;
    minhaData.s = tempo.tm_sec;

    // SALVAR DATA NO VETOR DE PRODUTOS
    p[posicao]->dataDeCadastro = minhaData;
}

void inicializar(Produto *p[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        p[i] = NULL;
    }
}

void cadastrar(Produto *p[], int posicao)
{
    p[posicao] = (Produto *)malloc(sizeof(struct produto));
    printf("\n\tDigite Codigo Produto:      ");
    scanf("%d", &p[posicao]->codigo);
    fflush(stdin);
    printf("\tDigite Descricao Produto:   ");
    scanf("%[^\n]", p[posicao]->descricao);
    fflush(stdin);
    printf("\tDigite Nome Fornecedor:     ");
    scanf("%[^\n]", p[posicao]->fornecedor);
    fflush(stdin);
    printf("\tDigite Preco:               ");
    scanf("%lf", &p[posicao]->preco);
    fflush(stdin);
    salvarDataDeCadastroNoVetorProdutos(p, posicao);
    printf("\n");
    printf("\n\t\t\t\t     CADASTRO REALIZADO! \n");
    data();
    printf("\n");
}


void listar(Produto *p[], int posicao)
{
    if (posicao != 0){
        for (int i = 0; i < posicao; i++)
        {
            printf("\n\t\tCADASTRO NUMERO :      # %d \n", i + 1);
            printf("\t\tCodigo do Produto:       %d \n", p[i]->codigo);
            printf("\t\tDescricao do Produto:    %s \n", p[i]->descricao);
            printf("\t\tFornecedor do Produto:   %s \n", p[i]->fornecedor);
            printf("\t\tPreco do Produto:        %.2lf \n", p[i]->preco);
            printf("\t\tQuantidade no Estoque:   %d\n", p[i]->estoque);
            printf("\n");
            printf("\t\tCADASTRO REALIZADO NO DIA %02d/%02d/%d %02d:%02d:%02d HORAS \n", p[i]->dataDeCadastro.dia, p[i]->dataDeCadastro.mes, p[i]->dataDeCadastro.ano, p[i]->dataDeCadastro.h, p[i]->dataDeCadastro.m, p[i]->dataDeCadastro.s);
            printf("\t\t***************************************************\n");
            printf("\n");

        }
    }else{
    system("color 4");
    printf("\n\t\t\t        NENHUM REGISTRO ENCONTRADO!!! \n\n");
    }
}


void encontrar(Produto *p[], int codigoProduto, int posicao)
{
    for (int i = 0; i < posicao; i++)
    {
        if (codigoProduto == p[i]->codigo)
        {
            printf("\n\t\tCADASTRO NUMERO:       # %d \n", i + 1);
            printf("\t\tCodigo do Produto:       %d \n", p[i]->codigo);
            printf("\t\tDescricao do Produto:    %s \n", p[i]->descricao);
            printf("\t\tFornecedor do Produto:   %s \n", p[i]->fornecedor);
            printf("\t\tPreco do Produto:        %.2lf \n", p[i]->preco);
            printf("\t\tQuantidade no Estoque:   %d\n", p[i]->estoque);
            printf("\n");
            printf("\t\tCADASTRO REALIZADO NO DIA %02d/%02d/%d %02d:%02d:%02d HORAS \n", p[i]->dataDeCadastro.dia, p[i]->dataDeCadastro.mes, p[i]->dataDeCadastro.ano, p[i]->dataDeCadastro.h, p[i]->dataDeCadastro.m, p[i]->dataDeCadastro.s);
            printf("\t\t***************************************************\n");
            printf("\n");
            return;
        }
    }
    system("color 4");
    printf("\n\t\t\t\t    REGISTRO NAO ENCONTRADO!!! \n\n");
}

void comprar(Produto *p[], int codigoProduto, int posicao, int compra)
{


    for (int i = 0; i < posicao; i++)
    {
        if (codigoProduto == p[i]->codigo)
        {

            p[i]->estoque += compra ;

            printf("\n\t\tCodigo Produto:                      %s\n", p[i]->descricao);
            printf("\t\tValor final da compra:        %.2lf \n", p[i]->preco * compra);
            printf("\t\tQuantidade final do estoque:  %.2d \n", p[i]->estoque);
            printf("\n");
            printf("\t\t**************************************\n");
            printf("\n");
            printf("\t                              COMPRA EFETUADA              \n  ");
            return;
        }
    }
    system("color 4");
    printf("\n\n\t\t\t\t  PRODUTO NAO ENCONTRADO!!!\n\n");
}

void vender(Produto *p[], int codigoProduto, int posicao, int venda)
{
    for (int i = 0; i < posicao; i++)
    {
        if (codigoProduto == p[i]->codigo)
        {
            if (venda > p[i]->estoque)
            {
                system("color 4"),
                printf("\n\t\t\t\t  QUANTIDADE SOLICITADA SEM ESTOQUE\n\n");

                printf("\t\t  ESTOQUE ATUAL:   %.2d \n\n", p[i]->estoque);
                return;
            }
            else
            {
                p[i]->estoque -= venda;
                printf("\n\t\tCodigo Produto                      %s\n", p[i]->descricao);
                printf("\t\tValor final da venda:         %.2lf \n", (p[i]->preco * 0.30 + p[i]->preco) * venda); // lucro de 30%
                printf("\t\tQuantidade final do estoque:  %.2d \n", p[i]->estoque);
                printf("\n");
                printf("\t\t**************************************\n");
                printf("\n");
                printf("\t                              VENDA EFETUADA              \n  ");
                return;
            }
        }
    }
    system("color 4");
    printf("\n\n\t\t\t\t  PRODUTO NAO ENCONTRADO!!!\n\n");
}


