#include <stdio.h>

#define QTD_LINHAS 100
#define QTD_COLUNAS 100

// Função para multiplicar duas matrizes
void multiplicarMatrizes(int matrizA[QTD_LINHAS][QTD_COLUNAS], int linA, int colA, 
                         int matrizB[QTD_LINHAS][QTD_COLUNAS], int linB, int colB, 
                         int matrizMult[QTD_LINHAS][QTD_COLUNAS]) {
    // Verifica se a multiplicação é possível
    if (colA != linB) {
        printf("Multiplicação impossível: o número de colunas de A deve ser igual ao número de linhas de B.\n");
        return;
    }
    
    // Inicializa a matriz resultado com zeros
    for (int i = 0; i < linA; i++) {
        for (int j = 0; j < colB; j++) {
            matrizMult[i][j] = 0;
        }
    }

    // Realiza a multiplicação
    for (int i = 0; i < linA; i++) {
        for (int j = 0; j < colB; j++) {
            for (int k = 0; k < colA; k++) {
                matrizMult[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

int main() {
    int linA, colA, linB, colB;

    // Entrada das dimensões da Matriz A
    printf("Digite o número de linhas e colunas da matriz A: ");
    scanf("%d %d", &linA, &colA);

    int matrizA[QTD_LINHAS][QTD_COLUNAS];
    
    // Entrada dos valores da Matriz A
    printf("Digite os elementos da matriz A:\n");
    for (int i = 0; i < linA; i++) {
        for (int j = 0; j < colA; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &matrizA[i][j]);
        }
    }

    // Entrada das dimensões da Matriz B
    printf("Digite o número de linhas e colunas da matriz B: ");
    scanf("%d %d", &linB, &colB);

    int matrizB[QTD_LINHAS][QTD_COLUNAS];
    
    // Entrada dos valores da Matriz B
    printf("Digite os elementos da matriz B:\n");
    for (int i = 0; i < linB; i++) {
        for (int j = 0; j < colB; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &matrizB[i][j]);
        }
    }

    // Matriz para armazenar o resultado
    int matrizMult[QTD_LINHAS][QTD_COLUNAS];

    // Chamada da função de multiplicação
    multiplicarMatrizes(matrizA, linA, colA, matrizB, linB, colB, matrizMult);

    // Exibe o resultado
    printf("Resultado da multiplicação:\n");
    for (int i = 0; i < linA; i++) {
        for (int j = 0; j < colB; j++) {
            printf("%d ", matrizMult[i][j]);
        }
        printf("\n");
    }

    return 0;
}
