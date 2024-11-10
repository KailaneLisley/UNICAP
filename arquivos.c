//ATIVIDADE DE ARQUIVOS
//ALUNA: KAILANE LSILEY DE ARAÚJO SILVA | RA:851345
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRODUTO_FILE "produtos.bin"
#define VENDA_FILE "vendas.bin"
#define MAX_DESC 50
#define MAX_PRODUTOS_VENDA 10

struct Produto{
    int id;
    char descricao[MAX_DESC];
    float preco;
    int quantidade;
};

struct Venda{
    int id;
    int produtos[MAX_PRODUTOS_VENDA];
    int qtd_produtos;
};

void cadastrarProduto(Produto *p);
void listarProdutos();
void atualizarProduto(int id, Produto *p);
void removerProduto(int id);
void cadastrarVenda(Venda *v);
void listarVendas();

int main() {
    int opcao;
    struct Produto produto;
    struct Venda venda;
    int id;

    do {
        printf("\n-----------MENU-----------\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Cadastrar Venda\n");
        printf("3. Listar Produtos\n");
        printf("4. Listar Vendas\n");
        printf("5. Atualizar Produto\n");
        printf("6. Remover Produto\n");
        printf("0. Sair\n");
        printf("------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(&produto);
                break;
            case 2:
                cadastrarVenda(&venda);
                break;
            case 3:
                listarProdutos();
                break;
            case 4:
                listarVendas();
                break;
            case 5:
                printf("ID do produto para atualizar: ");
                scanf("%d", &id);
                atualizarProduto(id, &produto);
                break;
            case 6:
                printf("ID do produto para remover: ");
                scanf("%d", &id);
                removerProduto(id);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
    return 0;
}

void cadastrarProduto(Produto *p) {
    FILE *prod = fopen(PRODUTO_FILE, "ab");
    if (!prod) {
        printf("Erro ao abrir o arquivo de produtos\n");
        return;
    }

    printf("ID do produto: ");
    scanf("%d", &p->id);
    printf("Descrição: ");
    scanf(" %s", p->descricao);
    printf("Preço: ");
    scanf("%f", &p->preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &p->quantidade);

    fwrite(p, sizeof(Produto), 1, prod);
    fclose(prod);
    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos() {
    FILE *prod = fopen(PRODUTO_FILE, "rb");
    if (!prod) {
        printf("Erro ao abrir o arquivo de produtos\n");
        return;
    }

    Produto p;
    int encontrado = 0;
    printf("Lista de Produtos:\n");
    while (fread(&p, sizeof(Produto), 1, prod)) {
        printf("ID: %d, Descrição: %s, Preço: %.2f, Quantidade: %d\n", p.id, p.descricao, p.preco, p.quantidade);
        encontrado = 1;
    }
    if (!encontrado) {
        printf("Nenhum produto cadastrado.\n");
    }
    fclose(prod);
}

void atualizarProduto(int id, Produto *p) {
    FILE *prod = fopen(PRODUTO_FILE, "r+b");
    if (!prod) {
        printf("Erro ao abrir o arquivo de produtos\n");
        return;
    }

    Produto temp;
    int encontrado = 0;
    while (fread(&temp, sizeof(Produto), 1, prod)) {
        if (temp.id == id) {
            encontrado = 1;
            printf("Nova descrição: ");
            scanf(" %s", temp.descricao);
            printf("Novo preço: ");
            scanf("%f", &temp.preco);
            printf("Nova quantidade: ");
            scanf("%d", &temp.quantidade);

            fseek(prod, -sizeof(Produto), SEEK_CUR);
            fwrite(&temp, sizeof(Produto), 1, prod);
            printf("Produto atualizado com sucesso.\n");
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
    fclose(prod);
}

void removerProduto(int id) {
    FILE *prod = fopen(PRODUTO_FILE, "rb");
    if (!prod) {
        printf("Erro ao abrir o arquivo de produtos\n");
        return;
    }

    FILE *temp = fopen("temp.bin", "wb");
    if (!temp) {
        printf("Erro ao abrir o arquivo temporário\n");
        fclose(prod);
        return;
    }

    Produto p;
    int achou = 0;
    while (fread(&p, sizeof(Produto), 1, prod)) {
        if (p.id != id) {
            fwrite(&p, sizeof(Produto), 1, temp);
        } else {
            achou = 1;
        }
    }

    fclose(prod);
    fclose(temp);

    if (achou) {
        remove(PRODUTO_FILE);
        rename("temp.bin", PRODUTO_FILE);
        printf("Produto removido com sucesso.\n");
    } else {
        remove("temp.bin");
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

void cadastrarVenda(Venda *v) {
    FILE *vend = fopen(VENDA_FILE, "ab");
    if (!vend) {
        printf("Erro ao abrir o arquivo de vendas\n");
        return;
    }

    printf("ID da venda: ");
    scanf("%d", &v->id);
    printf("Quantidade de produtos na venda: ");
    scanf("%d", &v->qtd_produtos);
    for (int i = 0; i < v->qtd_produtos; i++) {
        printf("ID do produto %d: ", i + 1);
        scanf("%d", &v->produtos[i]);
    }

    fwrite(v, sizeof(Venda), 1, vend);
    fclose(vend);
    printf("Venda cadastrada com sucesso!\n");
}

void listarVendas() {
    FILE *vend_venda = fopen(VENDA_FILE, "rb");
    FILE *prod_produto = fopen(PRODUTO_FILE, "rb");
    if (!vend_venda || !prod_produto) {
        printf("Erro ao abrir os arquivos\n");
        return;
    }

    Venda v;
    Produto p;
    int encontrado = 0;
    printf("Lista de Vendas:\n");
    while (fread(&v, sizeof(Venda), 1, vend_venda)) {
        printf("ID da Venda: %d\nProdutos:\n", v.id);
        for (int i = 0; i < v.qtd_produtos; i++) {
            rewind(prod_produto);
            while (fread(&p, sizeof(Produto), 1, prod_produto)) {
                if (p.id == v.produtos[i]) {
                    printf(" - %s (ID: %d, Preço: %.2f)\n", p.descricao, p.id, p.preco);
                    break;
                }
            }
        }
        printf("\n");
        encontrado = 1;
    }
    if (!encontrado) {
        printf("Nenhuma venda cadastrada.\n");
    }

    fclose(vend_venda);
    fclose(prod_produto);
}
