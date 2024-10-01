/*
Programação Estruturada | 2024.2
Aluna: Kailane Lisley de Araújo Silva | RA: 00000851345
*/

#include <stdio.h>
#include <stdlib.h>

#define M 4
#define N 4

void preencherMatriz(int m[][N], int lin, int col);
void imprimirMatriz(int m[][N], int lin, int col);
void maiorCadaColuna(int m[][N], int lin, int col, int v[]);
void imprimirVetor(int v[], int tam);
int maisRepetidosLinhaOuColuna(int m[][N], int lin, int col);

int main() {
    int matriz[M][N];
    int vetor[N];
    int opcao;
    do {
        printf("\nMENU\n\n");
        printf("1 - Preencher matriz com aleatórios\n");
        printf("2 - Maior valor de cada coluna\n");
        printf("3 - Linha ou coluna com mais repetidos\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            preencherMatriz(matriz, M, N);
            imprimirMatriz(matriz, M, N);
            break;
        case 2:
            maiorCadaColuna(matriz, M, N, vetor);
            imprimirVetor(vetor, N);
            break;
        case 3:
            maisRepetidos_L_C(matriz, M, N);
            break;
        default:
            break;
        }
    } while (opcao != 0);
    return 0;
}

void preencherMatriz(int m[][N], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            m[i][j] = rand() % 10 + 1; 
        }
    }
}

void imprimirMatriz(int m[][N], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
}

void maiorCadaColuna(int m[][N], int lin, int col, int v[]) {
    for (int j = 0; j < col; ++j) {
        int maior = m[0][j];
        for (int i = 1; i < lin; ++i) {
            if (m[i][j] > maior) {
                maior = m[i][j];
            }
        }
        v[j] = maior;
    }
}

void imprimirVetor(int v[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

//Função para contar a quantidade de números repetidos seja numa linha ou coluna (depende do parâmetro)
//Não é necessário declarar um protótipo dessa função antes do main pois só será usada dentro da função seguinte
int contarRepetidos(int v[], int tam) {
    int contagem = 0;
    for (int i = 0; i < tam; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (v[i] == v[j]) {
                contagem++;
                break;
            }
        }
    }
    return contagem;
}

//Função para verificar se há mais repetições em uma linhas ou em uma colunas e informar o indice respectivo 
int maisRepetidosLinhaOuColuna(int m[][N], int lin, int col) {
    int maxRepeticao = 0;
    int indice = 0;
    int isLinha = 1;  // 1 = linha, 0 = coluna

    // Verificando repetição de números nas LINHAS
    for (int i = 0; i < lin; ++i) {
        int linha[N];
        for (int j = 0; j < col; ++j) {
            linha[j] = m[i][j];  
        }
        int repetidos = contarRepetidos(linha, col);  
        if (repetidos > maxRepetidos) {
            maxRepetidos = repetidos;
            indice = i;
            isLinha = 1;
        }
    }

    // Verificando repetição de números nas COLUNAS
    for (int j = 0; j < col; ++j) {
        int coluna[M];
        for (int i = 0; i < lin; ++i) {
            coluna[i] = m[i][j]; 
        }
        int repetidos = contarRepetidos(coluna, lin);  
        if (repetidos > maxRepetidos) {
            maxRepetidos = repetidos;
            indice = j;
            isLinha = 0;  
        }
    }

    if (maxRepetidos > 0) {
        if (isLinha) {
            printf("A linha %d tem o maior número de elementos repetidos: %d repetidos\n", indice, maxRepetidos);
        } else {
            printf("A coluna %d tem o maior número de elementos repetidos: %d repetidos\n", indice, maxRepetidos);
        }
    } else {
        printf("Nenhuma repetição encontrada nas linhas ou colunas.\n");
    }

    return maxRepetidos;
}
