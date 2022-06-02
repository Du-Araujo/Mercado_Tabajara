#ifndef MERCADO_H_INCLUDED
#define MERCADO_H_INCLUDED

void logo(void);

struct dataAtual
{
    int dia, mes, ano;
    int h, m, s;
};

struct produto
{
    int codigo;
    char descricao[61];
    char fornecedor[61];
    int estoque;
    double preco;
    struct dataAtual dataDeCadastro;
};

void data(void);

void registro(void);

typedef struct produto Produto;

void inicializar(Produto *p[], int tam);

void cadastrar(Produto *p[], int posicao);

void listar(Produto *p[], int posicao);

void encontrar(Produto *p[], int codigoProduto, int posicao);

void comprar(Produto *p[], int codigoProduto, int posicao, int compra);

void vender(Produto *p[], int codigoProduto, int posicao, int venda);

#endif // MERCADO_H_INCLUDED
