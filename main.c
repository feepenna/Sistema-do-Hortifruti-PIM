#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    char nome[30];
    float precoGerais;
};

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Definindo os produtos
    struct Produto vegetais = {"Vegetais", 5.0};
    struct Produto verduras = {"Verduras", 4.0};
    struct Produto legumes = {"Legumes", 3.0};
    
    struct Produto frutas[5] = {
        {"Laranja", 0.035},  // Por grama
        {"Uva", 0.070},     
        {"Morango", 0.120},   
        {"Abacaxi", 0.050},   
        {"Banana", 0.040}    
    };

    
    float peso, preco;
    char calculo;

    do {
        printf("Qual produto deseja escanear?\n");
        printf("v. vegetais\n");
        printf("r. verduras\n");
        printf("l. legumes\n");
        printf("f. frutas\n");
        printf("s. saída\n");
        scanf(" %c", &calculo);

        switch (calculo) {
            case 'v':
                printf("Digite o peso do produto (%s): ", vegetais.nome);
                scanf("%f", &peso);
                preco = vegetais.precoGerais * peso;
                printf("Preço: %.2f reais\n", preco);
                break;

            case 'r':
                printf("Digite o peso do produto (%s): ", verduras.nome);
                scanf("%f", &peso);
                preco = verduras.precoGerais * peso;
                printf("Preço: %.2f reais\n", preco);
                break;

            case 'l':
                printf("Digite o peso do produto (%s): ", legumes.nome);
                scanf("%f", &peso);
                preco = legumes.precoGerais * peso;
                printf("Preço: %.2f reais\n", preco);
                break;

            case 'f':
                printf("Escolha a fruta:\n");
                printf("1. %s\n2. %s\n3. %s\n4. %s\n5. %s\n", 
                       frutas[0].nome, frutas[1].nome, frutas[2].nome, frutas[3].nome, frutas[4].nome);
                int fruta;
                scanf("%d", &fruta);

                if (fruta >= 1 && fruta <= 5) {
                    float peso;
                    printf("Digite o peso do produto (%s): ", frutas[fruta-1].nome);
                    
        scanf("%f", &peso);
                    
                    float preco = frutas[fruta-1].precoGerais * peso;
                    printf("Preço: %.2f reais\n", preco);
                } else {
                    printf("Fruta inválida\n");
                }
                break;

            case 's':
                printf("Saindo...\n");
                break;

            default:
                printf("Operação inválida\n");
                break;
        }
    } while (calculo != 's');

    printf("Fim da execução\n");
    return 0;
}


