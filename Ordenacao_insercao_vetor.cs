/*
Programação Estruturada | 2024.2
Aluna: Kailane Lisley (RA: 00000851345)
*/
#include <stdio.h>

void inserirOrdenado(double[], int tam, double valor);

int main(){
    
    int QTD_ALUNOS;
    printf("Digite a capacidade total: ");
    scanf("%d", &QTD_ALUNOS);

    printf("\n");
    double nota[QTD_ALUNOS];
    for(int i=0; i<QTD_ALUNOS;i++){
        double n;
        printf("Digite o %dº número: ", i + 1);
        scanf("%lf", &n);
        inserirOrdenado(nota, i, n);
    }
    printf("\n");
    
    for(int i=0; i<QTD_ALUNOS;i++){
        printf("nota[%d] = %.1f \n", i + 1, nota[i]);
    }
    printf("\n");
}

void inserirOrdenado(double vetor[], int tam, double valor){
    int i = tam - 1;
    while(i>=0 && vetor[i]>valor){
        vetor[i+1] = vetor[i];
        i--;
    }
    vetor[i+1] = valor;
}
