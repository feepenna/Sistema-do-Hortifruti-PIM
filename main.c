#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    double umquilovt = 5.0, umquilovr = 4.0, umquilole = 3.0, peso;
    char calculo;
    double preco;
    //char addprod;

    do{
        printf("Qual produto deseja escanear?\n");
        printf("v. vegetais \n");
        printf("r. verduras \n");
        printf("l. legumes \n");
        printf("s. saida \n");
        scanf(" %c", &calculo);
       // scanf("%c", &addprod);

        switch (calculo){
        case 'v':
            printf("Digite o peso do produto: ");
            scanf("%lf", &peso);
            preco = umquilovt * peso;
            break;
        case 'r':
            printf("Digite o peso do produto: ");
            scanf("%lf", &peso);
            preco = umquilovr * peso;
            break;
        case 'l':
            printf("Digite o peso do produto: ");
            scanf("%lf", &peso);
            preco = umquilole * peso;
            break;
        case 's':
            //printf("Sair \n");
            break;
        default:
            printf("Operação inválida \n");
            break;
        }

        printf("O preço total é: %.2f\n", preco);
        printf("Deseja adicionar mais produtos? \n");


    }while (calculo != 'e');
    printf("Fim da execução\n");
    }

