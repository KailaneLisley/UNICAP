#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraVetor(int v[], int tam, int tipo);
void insertionSort(int v[], int tam);
void selectionSort(int v[], int tam);
void bubbleSort(int v[], int tam);
//void imprimeVetor(int v[], int tam);

int main() {
    srand(time(NULL)); 

    int tamanhos[] = {10, 100, 1000, 10000, 100000};
    int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    int maxTempo = 5 * 60 * 1000;  

    for (int i = 0; i < numTamanhos; i++) {
        int tamanho = tamanhos[i];
        
        while (tamanho > 0) {
            int *vetor = (int *) malloc(tamanho * sizeof(int));
            if (vetor == NULL) {
                printf("Falha na alocação da memória para vetor de tamanho %d.\n", tamanho);
                break;
            }

            printf("\n--- Tamanho do vetor: %d ---\n", tamanho);

            int tempoExcedido = 0;

            for (int tipo = 0; tipo < 3; tipo++) {
                geraVetor(vetor, tamanho, tipo);

                char* descricao;
                if (tipo == 0) {
                    descricao = "Desordenado";
                } else if (tipo == 1) {
                    descricao = "Ordenado Crescente";
                } else {
                    descricao = "Ordenado Decrescente";
                }

                printf("Vetor original (%s):\n", descricao);
                // imprimeVetor(vetor, tamanho);

                int *vetorInsertion = (int *) malloc(tamanho * sizeof(int));
                if (vetorInsertion != NULL) {
                    for (int j = 0; j < tamanho; j++) {
                        vetorInsertion[j] = vetor[j];
                    }

                    clock_t inicio = clock();
                    insertionSort(vetorInsertion, tamanho);
                    clock_t fim = clock();

                    double tempoInsertion = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
                    printf("Vetor após Insertion Sort (%.2f ms):\n", tempoInsertion);
                    // imprimeVetor(vetorInsertion, tamanho);
                    free(vetorInsertion);

                    if (tempoInsertion > maxTempo) {
                        printf("Tempo excedido para Insertion Sort. Interrompendo execução.\n");
                        tempoExcedido = 1; 
                        break;
                    }
                }

                int *vetorSelection = (int *) malloc(tamanho * sizeof(int));
                if (vetorSelection != NULL) {
                    for (int j = 0; j < tamanho; j++) {
                        vetorSelection[j] = vetor[j];
                    }

                    clock_t inicio = clock();
                    selectionSort(vetorSelection, tamanho);
                    clock_t fim = clock();

                    double tempoSelection = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
                    printf("Vetor após Selection Sort (%.2f ms):\n", tempoSelection);
                    // imprimeVetor(vetorSelection, tamanho);
                    free(vetorSelection);

                    if (tempoSelection > maxTempo) {
                        printf("Tempo excedido para Selection Sort. Interrompendo execução.\n");
                        tempoExcedido = 1; 
                        break;
                    }
                }

                                int *vetorBubble = (int *) malloc(tamanho * sizeof(int));
                if (vetorBubble != NULL) {
                    for (int j = 0; j < tamanho; j++) {
                        vetorBubble[j] = vetor[j];
                    }

                    clock_t inicio = clock();
                    bubbleSort(vetorBubble, tamanho);
                    clock_t fim = clock();

                    double tempoBubble = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
                    printf("Vetor após Bubble Sort (%.2f ms):\n", tempoBubble);
                    // imprimeVetor(vetorBubble, tamanho);
                    free(vetorBubble);

                    if (tempoBubble > maxTempo) {
                        printf("Tempo excedido para Bubble Sort. Interrompendo execução.\n");
                        tempoExcedido = 1; 
                        break;
                    }
                }
            }

            free(vetor);

            if (tempoExcedido) {
                tamanho = tamanho / 2;
                if (tamanho < 1) {
                    tamanho = 1;  
                }
                printf("Novo tamanho após redução: %d\n", tamanho);
            } else {
                break;  
            }
        }
    }

    printf("Execução finalizada.\n");
    return 0;
}

void geraVetor(int v[], int tam, int tipo) {
    if (tipo == 0) { 
        for (int i = 0; i < tam; i++) {
            v[i] = rand() % 100; 
        }
    } else if (tipo == 1) { 
        for (int i = 0; i < tam; i++) {
            v[i] = i;
        }
    } else if (tipo == 2) { 
        for (int i = 0; i < tam; i++) {
            v[i] = tam - i;
        }
    }
}

void imprimeVetor(int v[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void insertionSort(int v[], int tam) {
    for(int i = 1; i < tam; i++) {
        int valor = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > valor) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = valor;
    }
}

void selectionSort(int v[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < tam; j++) {
            if (v[j] < v[menor])
                menor = j;
        }
        int aux = v[menor];
        v[menor] = v[i];
        v[i] = aux;
    }
}

void bubbleSort(int v[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}
