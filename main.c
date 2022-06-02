#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#define TAM 500
#include "mercado.h"
#include <time.h>

int main()
{ // titulo
    system("title MERCADO TABAJARA");

    // Logo
    logo();
    data();
    // Vari�veis
    int opcao = 0;
    int compra = 0, venda = 0;
    int posicao = 0, codigoProduto = 0;
    int dataCompra;
    Produto *vetorProduto[TAM];
    inicializar(vetorProduto, TAM);
    void logo(void);

    // Imprimindo Menu
    do
    {

        fflush(stdin);
        printf("\n");
        printf("\n");
        system("color 7");
        printf("\t\t\t\t   *   SISTEMA TABAJARA    *\n");
        printf("\n");
        printf("\t\t\t\t   1  -  CADASTRAR PRODUTO \n");
        printf("\t\t\t\t   2  -  LISTAR CADASTRO \n");
        printf("\t\t\t\t   3  -  ENCONTRAR PRODUTO \n");
        printf("\t\t\t\t   4  -  COMPRAR \n");
        printf("\t\t\t\t   5  -  VENDER \n");
        printf("\t\t\t\t   9  -  SAIR \n\n");
        printf("\t\t\t\t    DIGITE OPCAO DESEJADA: ");

        opcao = getch() - 48;                                        // Foi usado o get para leitura rapida de op��o
        system("cls");                                               // Limpeza de Tela
        printf("\n\n\t\t\t\t    OPCAO SELECIOANADA: %d\n\n", opcao); // Imprime a op�ao selecionada
        switch (opcao)
        {
        case 1:
            system("color 3");
            data();
            cadastrar(vetorProduto, posicao);
            posicao++;

            break;
        case 2:
            system("color 5");
            // Exibir data atual
            data();
            listar(vetorProduto, posicao);
            // Exibir de cadastro do produto
            break;
        case 3:
            system("color 6");
            data();
            printf("\n\t\tDigite Codigo Produto:   ");
            scanf("%d", &codigoProduto);
            encontrar(vetorProduto, codigoProduto, posicao);

            //            printf("\t\tCompra Efetuada dia: %d", data());
            break;
        case 4:
            system("color 7");
            data();
            printf("\n\t\tDigite Codigo Produto:        ");
            scanf("%d", &codigoProduto);
            printf("\n\t\tDigite Quantidade COMPRA:     ");
            scanf("%d", &compra);
            comprar(vetorProduto, codigoProduto, posicao, compra);
            printf("O produto foi comprado: ");
            data();
            break;
        case 5:
            system("color 2");
            data();
            printf("\n\t\tDigite Codigo Produto:        ");
            scanf("%d", &codigoProduto);
            printf("\n\t\tDigite Quantidade VENDA:      ");
            scanf("%d", &venda);

            vender(vetorProduto, codigoProduto, posicao, venda);
            break;
        case 9:
            system("color 13");
            logo();
            data();
            printf("\n\n\n\t\t\t\t     SISTEMA FINALIZADO!   \n\n");
            break;
        default:
            system("color 4");
            printf("\t\t\t\t      OPCAO INVALIDA!!! \n\n");
        }

        system("pause");
        system("cls");
    } while (opcao != 9);
    return 0;
}
