#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados_cliente
{
    char nome[200];
    char cpf[200];
    int idade;
};

struct dados_loja
{
    int opcao;
    int compra;

    int stockUm;
    int stockDois;
    int stockTres;

    int qVendas;
    float vendas;

    float desconto;
};

typedef struct dados_cliente dados_cliente;
typedef struct dados_loja dados_loja;

int main()
{

    dados_cliente cliente;
    dados_loja loja;

    int cadastro;

    loja.stockUm = 26;
    loja.stockDois = 29;
    loja.stockTres = 14;
    loja.qVendas = 0;

    printf("==------ +Magalhaes Eletronicos+ ------==\n \n");
    printf("Para acessar os produtos e necessario fazer um Cadastro\n");
    printf("\nDeseja fazer o Cadastro (1 Sim /2 Nao): ");
    scanf("%d", &cadastro);

    system("cls");

    if (cadastro == 1)
    {

        printf("           -CADASTRO-\n");

        printf("\nDigite seu Nome: ");
        fflush(stdin);
        gets(cliente.nome);

        printf("Digite seu CPF: ");
        fflush(stdin);
        gets(cliente.cpf);

        printf("Digite seu idade: ");
        scanf("%d", &cliente.idade);
        fflush(stdin);
    }
    else
    {
        printf("Voce nao podera seguir sem um cadastro");

        return 0;
    }

    system("cls");

    if (cliente.idade >= 18)
    {

        printf("\nCadastro Finalizado");
        printf("\nDeseja ver nosso catalogo (1 Sim / 2 Nao): ");
        scanf("%d", &loja.opcao);
    }
    else
    {
        printf("Cadastro nao efetuado ( Idade nao alcancada )\n");

        return 0;
    }

    do
    {
        switch (loja.opcao)
        {
        case 1:

            system("cls");
            printf("==============    <Menu>   ============== \n");
            printf(" 1 | Mouse G.  | R$: 165,60 | Stock: %d | \n", loja.stockUm);
            printf(" 2 | Cadeira G.| R$: 100,60 | Stock: %d | \n", loja.stockDois);
            printf(" 3 | Teclado G.| R$: 70,60  | Stock: %d | \n", loja.stockTres);
            printf("=================== <:> ==================\n");
            printf("\n");
            printf("Escolha um produto com base no numero correspondente: ");
            scanf("%d", &loja.compra);

            switch (loja.compra)
            {
            case 1:
                if (loja.stockUm == 0)
                {
                    printf("Sem stock do produto... \n");
                }
                else
                {

                    loja.stockUm = loja.stockUm - 1;
                    loja.vendas = loja.vendas + 165.60;
                    loja.qVendas++;
                }
                break;
            case 2:

                if (loja.stockDois == 0)
                {
                    printf("Sem stock do produto... \n");
                }
                else
                {
                    loja.stockDois = loja.stockDois - 1;
                    loja.vendas = loja.vendas + 100.00;
                    loja.qVendas++;
                }
                break;
            case 3:
                if (loja.stockDois == 0)
                {
                    printf("Sem stock do produto... \n");
                }
                else
                {
                    loja.stockTres = loja.stockTres - 1;
                    loja.vendas = loja.vendas + 70.00;
                    loja.qVendas++;
                }
                break;
            default:
                break;
            }

        default:
            break;
        }
        system("cls");

        printf("Deseja realizar mais uma compra ? (1 Sim / 2 Nao): ");
        scanf("%d", &loja.opcao);

        system("cls");

    } while (loja.opcao == 1);

    if (loja.vendas > 76.00)
    {
        printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<=======++=======>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("Voce tera um desconto de DEZ PORCENTO por compras acima de R$ 76.00 \n");
        printf("E para compras a partir de R$ 200.00, voce tera um desconto de 25 PORCENTO\n");
        printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<=======++=======>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("\n");

        if (loja.vendas > 76.00)
        {
            loja.desconto = loja.vendas / 1.10;
        }
        else if (loja.vendas > 200.00)
        {
            loja.desconto = loja.vendas / 1.25;
        }
    }

    printf("===============================================\n");
    printf("-------------------------------------------\n");
    printf("Dados do Usuario e compra:\n");
    printf("Nome: %s \n", cliente.nome);

    printf("Nome: %s \n", cliente.cpf);
    printf("-------------------------------------------\n");
    printf("===============================================\n");
    printf("-------------------------------------------\n");

    printf("Numero de produtos no carrinho: %d \n", loja.qVendas);
    printf("-------------------------------------------\n");
    printf("Preco Total: %.2f \n", loja.vendas);
    printf("-------------------------------------------\n");

    if (loja.vendas > 76.00)
    {

        printf("Preco Total com Desconto Aplicado: %.2f \n", loja.desconto);
        printf("-------------------------------------------\n");
        printf("===============================================\n");
    }
    else if (loja.vendas > 200.00)
    {

        printf("Preco Total com Desconto Aplicado: %.2f \n", loja.desconto);
        printf("-------------------------------------------\n");
        printf("===============================================\n");
    }
    else
    {

        printf("Valor total insuficiente para receber os descontos..\n");
        printf("-------------------------------------------\n");
        printf("===============================================\n");
    }

    return 0;
}