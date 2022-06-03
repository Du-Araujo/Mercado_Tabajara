#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#define TAM 500
#include "mercado.h"
#include <time.h>

int main()
{   // titulo
    system("title MERCADO TABAJARA");

    // Logo
    logo();
    data();

    // Variáveis
    int opcao = 0;
    int compra = 0, venda = 0;
    int posicao = 0, codigoProduto = 0;
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
        printf("\t\t\t\t  *   SISTEMA TABAJARA    *\n");
        printf("\n");
        printf("\t\t\t\t  1  -  CADASTRAR PRODUTO \n");
        printf("\t\t\t\t  2  -  LISTAR CADASTRO \n");
        printf("\t\t\t\t  3  -  ENCONTRAR PRODUTO \n");
        printf("\t\t\t\t  4  -  COMPRAR \n");
        printf("\t\t\t\t  5  -  VENDER \n");
        printf("\t\t\t\t  9  -  SAIR \n\n");
        printf("\t\t\t\t   DIGITE OPCAO DESEJADA: ");
        opcao = getch() - 48;                                        // Foi usado o get para leitura rapida de opcao
        system("cls");                                               // Limpeza de Tela
        printf("\n\n\t\t\t\t    OPCAO SELECIOANADA: %d\n\n", opcao); // Imprime a opcao selecionada
        switch (opcao)
        {
        case 1:
            system("color 3");
            // Exibir data atual
            data();
            printf("\t\t\t\t\t  CADASTRO\n");
            cadastrar(vetorProduto, posicao);
            posicao++;

            break;
        case 2:
            system("color 7");
            // Exibir data atual
            data();
            printf("\t\t\t\t       LISTAR PRODUTOS\n");
            listar(vetorProduto, posicao);
            // Exibir de cadastro do produto
            break;
        case 3:
            system("color 6");
            data();
            printf("\t\t\t\t     ENCONTRAR PRODUTOS\n");
            printf("\n\t\tDigite Codigo Produto:   ");
            scanf("%d", &codigoProduto);
            encontrar(vetorProduto, codigoProduto, posicao);
            break;
        case 4:
            system("color 3");
            data();
            printf("\t\t\t\t\t   COMPRAR\n");
            printf("\n\t\tDigite Codigo Produto:        ");
            scanf("%d", &codigoProduto);
            encontrar(vetorProduto, codigoProduto, posicao);
            printf("\n\t\tDigite Quantidade COMPRA:     ");
            scanf("%d", &compra);
            comprar(vetorProduto, codigoProduto, posicao, compra);
            data();
            printf("\n");
            break;
        case 5:
            system("color 2");
            data();
            printf("\t\t\t\t\t   VENDER\n");
            printf("\n\t\tDigite Codigo Produto:        ");
            scanf("%d", &codigoProduto);
            encontrar(vetorProduto, codigoProduto, posicao);
            printf("\n\t\tDigite Quantidade VENDA:      ");
            scanf("%d", &venda);
            vender(vetorProduto, codigoProduto, posicao, venda);
            data();
            break;
        case 9:
            system("color 9");
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
