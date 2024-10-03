/*
Programação Estruturada | 2024.2
Aluna: Kailane Lisley (RA: 00000851345)
*/
#include <stdio.h>

void inserirOrdenado(int vetor[], int tam, int valor);
void imprimirValores(int vetor[], int tam);
int buscaBinaria(int vetor[], int tam, int valor);
void removerValor(int vetor[], int *tam, int indice);

int main() {
    printf("\nVETORES | Inserção, Remoção e Consulta\n");
    
    int QTD;
    do {
        printf("\nDigite a capacidade total (Maior que 3 e menor que 50): ");
        scanf("%d", &QTD);
        if (QTD < 3 || QTD > 50) {
            printf("\nQuantidade Inválida. Tente Novamente\n");
        }
    } while (QTD < 3 || QTD > 50);
   
    printf("\n");
    int valores[QTD];
    int totalInseridos = 0;  // Contador para o número de elementos inseridos
    
    int resposta;
    do {
        printf("\n| M E N U |\n\n");
        printf("1 | Inserir Valores\n");
        printf("2 | Remover Valor\n");
        printf("3 | Imprimir Valores Ordenados\n");
        printf("4 | Buscar Valor\n");
        printf("0 | Sair\n");

        printf("Escolha uma opção do menu: ");
        scanf("%d", &resposta);

        switch (resposta) {
            case 1: {
                if (totalInseridos < QTD) {
                    int n;
                    int q;
                    do{
                        printf("Quantos valores deseja inserir?: ");
                        scanf("%d", &q);
                        if ((totalInseridos+q)>QTD){
                            printf("\nOps! Ultrapassou o limite de valores para adicionar\nEncolha uma quatidade menor por favor\n\n");
                        }
                    }while((totalInseridos+q)>QTD);
                    
                    for(int i=0; i<q; i++){
                        printf("Digite o valor %d: ", i+1);
                        scanf("%d", &n);
                        inserirOrdenado(valores, totalInseridos, n); 
                        totalInseridos++; 
                    }
                } else {
                    printf("Capacidade máxima atingida!\n");
                }
                break;
            }
            
            case 2:
                if (totalInseridos > 0) {
                    int r;
                    printf("\nQual valor deseja remover?: ");
                    scanf("%d", &r);
                    int buscar = buscaBinaria(valores, totalInseridos, r);
                    if (buscar != -1) {
                        removerValor(valores, &totalInseridos, buscar);
                        printf("Valor Removido");
                    } else {
                        printf("Valor não encontrado\n");
                    }
                } else {
                    printf("Nenhum valor inserido para buscar!\n");
                }
                break;

            case 3: 
                if (totalInseridos > 0) {
                    printf("\nValores inseridos (ordenados):\n");
                    imprimirValores(valores, totalInseridos);
                } else {
                    printf("Nenhum valor inserido ainda!\n");
                }
                break;

            case 4:
                if (totalInseridos > 0) {
                    int b;
                    printf("\nQual valor deseja procurar?: ");
                    scanf("%d", &b);
                    int busca = buscaBinaria(valores, totalInseridos, b);
                    if (busca != -1) {
                        printf("Valor encontrado na posição %d\n", busca + 1);
                    } else {
                        printf("Valor não encontrado\n");
                    }
                } else {
                    printf("Nenhum valor inserido para buscar!\n");
                }
                break;

            case 0:
                printf("\nPrograma Encerrado! Até a próxima!\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (resposta != 0);

    return 0;
}

void inserirOrdenado(int vetor[], int tam, int valor) {
    int i = tam - 1;
    while (i >= 0 && vetor[i] > valor) {
        vetor[i + 1] = vetor[i];
        i--;
    }
    vetor[i + 1] = valor;
}

void imprimirValores(int vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("valor[%d] = %d \n", i + 1, vetor[i]);
    }
    printf("\n");
}

int buscaBinaria(int vetor[], int tam, int valor) {
    int esq = 0, dir = tam - 1, meio;
    while (esq <= dir) {
        meio = (esq + dir) / 2;
        if (valor < vetor[meio]) {
            dir = meio - 1;
        } else if (valor > vetor[meio]) {
            esq = meio + 1;
        } else {
            return meio;
        }
    }
    return -1;
}

void removerValor(int vetor[], int *tam, int indice) {
   int i;
   for(i=indice; i< *tam - 1; i++){
       vetor[i] = vetor[i+1];
   }
   (*tam)--;
}
