#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");
    float codigodoproduto [20];
    float peso;

//int legumes[10];
//int verduras[5];
//int vegetal[5];
printf("Digite o código do produto: ");
scanf("%f", &codigodoproduto);
printf("Digite o peso do produto: ");
scanf("%f", &peso);
return 0;


}
