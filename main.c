#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main( ){
    setlocale(LC_ALL, "Portuguese");
    float umquilovt = 5.0, umquilovr = 4.0, umquilole = 3.0, peso;
    //cada produto custa 5 reais o quilo, com a variável peso elas vão se multiplicar ent se alguém compra dois quilos de manjerição vão ser 10 reais
    char calculo;
    float preco;

    do{
        printf("Qual produto deseja escanear?\n");
        printf("v. vegetais \n");
        printf("r. verduras \n");
        printf("l. legumes \n");
        printf("e. saída \n");
        scanf(" %c", &calculo);

        switch (calculo){
        case 'v':
            printf("Digite o peso do produto: ");
            scanf("%f", &peso);
            preco = umquilovt*peso;
            break;
        case 'r':
            printf("Digite o peso do produto: ");
            scanf("%f", &peso);
            preco = umquilovr*peso;
            break;
        case 'l':
            printf("Digite o peso do produto: ");
            scanf("%f", &peso);
            preco = umquilole*peso;
            break;
        case 'e':
            printf("Sair \n");
            break;
        default:
            printf("Operação inválida \n");
            break;
        }
    }while (calculo != 'e');
        printf("Fim da execucaõ");

        return 0;
    }
    
