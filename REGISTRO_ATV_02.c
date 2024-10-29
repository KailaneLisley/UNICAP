#include <stdio.h>
#include <string.h>

#define QTD_PRODUTOS 40

struct Produto {
    int codigo;
    char descricao[60];
    float valor_u;
    int qtd_estoque;
};

void lerStr(char *str, int tam);
void cadastrar_produto(struct Produto produtos[], int *num_produtos, int tam);
int busca_codigo(struct Produto produtos[], int num_produtos, int codigo);
void alterar_valor_u(struct Produto produtos[], int num_produtos, int codigo, float novo_valor);
float informar_valor_u(struct Produto produtos[], int num_produtos, int codigo);
int informar_qtd_estoque(struct Produto produtos[], int num_produtos, int codigo);
void realizar_venda(struct Produto produtos[], int num_produtos, int codigo, int quantidade_desejada);
void atualizar_estoque(struct Produto produtos[], int num_produtos, int codigo, int nova_quantidade);
void exibir_produtos(struct Produto produtos[], int num_produtos);
void exibir_produtos_estoque_zero(struct Produto produtos[], int num_produtos);

int main() {
    struct Produto produtos[QTD_PRODUTOS];
    int num_produtos = 0;

    int resposta, codigo;
    float novo_valor;

    do {
        printf("\nGerenciamento de Produtos em Estoque\n");
        printf("\n1 | Cadastrar um novo produto\n");
        printf("2 | Alterar valor unitário\n");
        printf("3 | Exibir valor unitário\n");
        printf("4 | Exibir quantidade do produto em estoque\n");
        printf("5 | Realizar venda\n");
        printf("6 | Atualizar estoque\n");
        printf("7 | Exibir todos os produtos\n");
        printf("8 | Exibir produtos com estoque zero\n");
        printf("0 | Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &resposta);

        switch (resposta) {
            case 0:
                printf("Obrigada por interagir!\n");
                break;

            case 1:
                cadastrar_produto(produtos, &num_produtos, QTD_PRODUTOS);
                break;

            case 2:
                printf("Digite o código do produto: ");
                scanf("%d", &codigo);
                printf("Digite o novo valor unitário para o produto %d: ", codigo);
                scanf("%f", &novo_valor);
                alterar_valor_u(produtos, num_produtos, codigo, novo_valor);
                break;

            case 3:
                printf("Digite o código do produto para exibir o valor unitário: ");
                scanf("%d", &codigo);
                float valor = informar_valor_u(produtos, num_produtos, codigo);
                if (valor != -1) {
                    printf("Valor unitário do produto %d: R$%.2f\n", codigo, valor);
                }
                break;

            case 4:
                printf("Digite o código do produto para exibir a quantidade em estoque: ");
                scanf("%d", &codigo);
                int qtd = informar_qtd_estoque(produtos, num_produtos, codigo);
                if (qtd != -1) {
                    printf("Quantidade em estoque do produto %d: %d unidades\n", codigo, qtd);
                }
                break;

            case 5:
                printf("Digite o código do produto para realizar a venda: ");
                scanf("%d", &codigo);
                int qtd_desejada;
                printf("Digite a quantidade desejada: ");
                scanf("%d", &qtd_desejada);
                realizar_venda(produtos, num_produtos, codigo, qtd_desejada);
                break;

            case 6:
                printf("Digite o código do produto para atualizar o estoque: ");
                scanf("%d", &codigo);
                int nova_qtd;
                printf("Digite a nova quantidade em estoque: ");
                scanf("%d", &nova_qtd);
                atualizar_estoque(produtos, num_produtos, codigo, nova_qtd);
                break;

            case 7:
                exibir_produtos(produtos, num_produtos);
                break;

            case 8:
                exibir_produtos_estoque_zero(produtos, num_produtos);
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

    } while (resposta != 0);

    return 0;
}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void cadastrar_produto(struct Produto produtos[], int *num_produtos, int tam) {
    if (*num_produtos >= tam) {
        printf("Ops! Capacidade máxima de produtos cadastrados.\n");
        return;
    }

    struct Produto novo_produto;
    printf("\nCódigo do Produto: ");
    scanf("%d", &novo_produto.codigo);
    getchar();
    if (novo_produto.codigo <= 0) {
        printf("Código inválido. Deve ser um número positivo.\n");
        return;
    }
    printf("Descrição do produto: ");
    lerStr(novo_produto.descricao, 60);
    printf("Valor Unitário: ");
    scanf("%f", &novo_produto.valor_u);
    getchar();
    if (novo_produto.valor_u < 0) {
        printf("Valor unitário inválido. Deve ser maior ou igual a zero.\n");
        return;
    }
    printf("Quantidade no estoque: ");
    scanf("%d", &novo_produto.qtd_estoque);
    if (novo_produto.qtd_estoque < 0) {
        printf("Quantidade de estoque inválida. Deve ser maior ou igual a zero.\n");
        return;
    }

    produtos[*num_produtos] = novo_produto;
    (*num_produtos)++;
    printf("\nPRODUTO CADASTRADO COM SUCESSO!\n");
}


int busca_codigo(struct Produto produtos[], int num_produtos, int codigo) {
    for (int i = 0; i < num_produtos; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void alterar_valor_u(struct Produto produtos[], int num_produtos, int codigo, float novo_valor) {
    int posicao = busca_codigo(produtos, num_produtos, codigo);
    if (posicao != -1) {
        produtos[posicao].valor_u = novo_valor;
        printf("Valor unitário alterado com sucesso!\n");
    } else {
        printf("Produto não encontrado.\n");
    }
}

float informar_valor_u(struct Produto produtos[], int num_produtos, int codigo) {
    int posicao = busca_codigo(produtos, num_produtos, codigo);
    if (posicao != -1) {
        return produtos[posicao].valor_u;
    } else {
        printf("Produto não encontrado.\n");
        return -1;
    }
}

int informar_qtd_estoque(struct Produto produtos[], int num_produtos, int codigo) {
    int posicao = busca_codigo(produtos, num_produtos, codigo);
    if (posicao != -1) {
        return produtos[posicao].qtd_estoque;
    } else {
        printf("Produto não encontrado.\n");
        return -1;
    }
}

void realizar_venda(struct Produto produtos[], int num_produtos, int codigo, int quantidade_desejada) {
    int posicao = busca_codigo(produtos, num_produtos, codigo);
    if (posicao == -1) {
        printf("Produto não encontrado.\n");
        return;
    }

    struct Produto *produto = &produtos[posicao];
    if (produto->qtd_estoque == 0) {
        printf("Produto sem estoque.\n");
    } else if (quantidade_desejada <= produto->qtd_estoque) {
        float valor_total = quantidade_desejada * produto->valor_u;
        produto->qtd_estoque -= quantidade_desejada;
        printf("Venda realizada! Valor total a pagar: R$%.2f\n", valor_total);
    } else {
        printf("Estoque insuficiente. Compra não realizada.\n");
    }
}

void atualizar_estoque(struct Produto produtos[], int num_produtos, int codigo, int nova_quantidade) {
    int posicao = busca_codigo(produtos, num_produtos, codigo);
    if (posicao != -1) {
        produtos[posicao].qtd_estoque = nova_quantidade;
        printf("Estoque atualizado com sucesso!\n");
    } else {
        printf("Produto não encontrado.\n");
    }
}

void exibir_produtos(struct Produto produtos[], int num_produtos) {
    printf("\nLISTA DOS PRODUTOS\n\n");
    for (int i = 0; i < num_produtos; i++) {
        printf(" Código: %d\n Descrição: %s\n Valor Unitário: R$%.2f\n Quantidade em Estoque: %d\n",
               produtos[i].codigo, produtos[i].descricao, produtos[i].valor_u, produtos[i].qtd_estoque);
    }
}

void exibir_produtos_estoque_zero(struct Produto produtos[], int num_produtos) {
    printf("\nProdutos com estoque zero:\n");
    int encontrou = 0;
    for (int i = 0; i < num_produtos; i++) {
        if (produtos[i].qtd_estoque == 0) {
            printf("Código: %d, Descrição: %s\n", produtos[i].codigo, produtos[i].descricao);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum produto com estoque zero.\n");
    }
}
