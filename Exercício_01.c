/*
Exercício 01 | Programação Estruturada 2024.2
Aluna: Kailane Lisley de Araújo Silva | RA: 00000851345
*/
#include <stdio.h>

int main (){

    // Questão 1
    for(int i=1; i<101; i++){
        if(i!=100){
            printf("%d,",i);
        }
        else{
            printf("%d\n",i);
        }
    }
    
    // Questão 2
    int soma = 0;
    for(int b=10; b<1001; b++){
        if(b%2!=0){
            soma += b;
        }
    }
    
    printf("\nO somatório dos números ímpares entre 10 e 1000 é igual a %d\n", soma);
    printf("\n");
    
    // Questão 3
    for (int i = 3; i <= 200; i += 3) {
        if (i == 3 || i % 10 != 3) {
            if (i < 198){
                printf("%d, ", i);
            }
            else{
                printf("%d", i);
            }
        }
    }
    printf("\n");
    return (0);
}
