#include <stdio.h>
#include <string.h>

#define QTD_ESTADOS 26

struct Estado {
    char nomeEstado[20];
    int numVeiculos;
    int acidentes;
};

void lerStr(char *str, int tam);
void lerEstado(struct Estado *estado, int tam);
void lerEstados(struct Estado estado[], int tam);
void maiorMenorAcid(struct Estado estado[], int tam);
float percentualAcidentes(struct Estado estado);
float mediaAcidentes(struct Estado estado[], int tam);
void estadosAcimaMedia(struct Estado estado[], int tam, float media);

int main() {
    struct Estado estado[QTD_ESTADOS];
    
    lerEstados(estado, QTD_ESTADOS);
    maiorMenorAcid(estado, QTD_ESTADOS);
    float media = mediaAcidentes(estado, QTD_ESTADOS);
    printf("A média de acidentes no país é %.2f\n", media);
    estadosAcimaMedia(estado, QTD_ESTADOS, media);

    return 0;
}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void lerEstado(struct Estado *estado, int tam) {
    printf("\nNome do Estado: ");
    lerStr(estado->nomeEstado, tam);
    printf("\nNumero de veiculos que circulam no estado(2007): ");
    scanf("%d", &estado->numVeiculos);
    getchar();  
    printf("\nNumero de acidentes de transito(2007): ");
    scanf("%d", &estado->acidentes);
    getchar(); 
}

void lerEstados(struct Estado estado[], int tam) {
    for (int i = 0; i < tam; i++) {
        lerEstado(&estado[i], 20); 
    }
}

void maiorMenorAcid(struct Estado estado[], int tam) {
    int pos_men = 0;
    int pos_mai = 0;

    for (int i = 1; i < tam; i++) {
        if (estado[i].acidentes < estado[pos_men].acidentes) {
            pos_men = i;
        }
        if (estado[i].acidentes > estado[pos_mai].acidentes) {
            pos_mai = i;
        }
    }
    printf("\nO Estado com menor quantidade de acidentes é %s e está na posição %d\n", estado[pos_men].nomeEstado, pos_men);
    printf("O Estado com maior quantidade de acidentes é %s e está na posição %d\n", estado[pos_mai].nomeEstado, pos_mai);
}

float percentualAcidentes(struct Estado estado) {
    if (estado.numVeiculos == 0) {
        return 0;  
    }
    return ((estado.acidentes / (float)estado.numVeiculos)) * 100;
}

float mediaAcidentes(struct Estado estado[], int tam) {
    int somaAcidentes = 0;
    
    for (int i = 0; i < tam; i++) {
        somaAcidentes += estado[i].acidentes;
    }
    
    return somaAcidentes / (float)tam;
}

void estadosAcimaMedia(struct Estado estado[], int tam, float media) {
    printf("\nEstados com número de acidentes acima da média\n");
    printf("\nMédia = %.2f:\n", media);
    
    for (int i = 0; i < tam; i++) {
        if (estado[i].acidentes > media) {
            printf("Estado: %s | Acidentes: %d\n", estado[i].nomeEstado, estado[i].acidentes);
        }
    }
}
