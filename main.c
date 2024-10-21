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
    struct Produto vegetais[5] = {
        {"Brocolis", 0.25},
        {"Cenoura", 0.50},
        {"Espinafre", 0.30},
        {"Alface", 0.75},
        {"Batata Doce", 0.70}
    };
    struct Produto verduras[3] = {
        {"Couve", 1.70},
        {"Acelga", 0.20},
        {"Escarola", 2.20}
    };
    struct Produto legumes[4] = {
        {"Chuchu", 0.75},
        {"Ervilha", 1.25},
        {"Palmito", 2.00},
        {"Quiabo", 1.75}
    };
    
    struct Produto frutas[5] = {
        {"Laranja", 0.35},
        {"Uva", 0.70},     
        {"Morango", 1.20},   
        {"Abacaxi", 0.50},   
        {"Banana", 0.40}    
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
            case 'v': {
                printf("Escolha o vegetal:\n");
                for (int i = 0; i < 5; i++) {
                    printf("%d. %s\n", i+1, vegetais[i].nome);
                }
                int veg_choice;
                scanf("%d", &veg_choice);

                if (veg_choice >= 1 && veg_choice <= 5) {
                    printf("Digite o peso do produto (%s): ", vegetais[veg_choice-1].nome);
                    scanf("%f", &peso);
                    preco = vegetais[veg_choice-1].precoGerais * peso;
                    printf("Preço: %.2f reais\n", preco);
                } else {
                    printf("Vegetal inválido\n");
                }
                break;
            }
            case 'r': {
                printf("Escolha a verdura:\n");
                for (int i = 0; i < 3; i++) {
                    printf("%d. %s\n", i+1, verduras[i].nome);
                }
                int verd_choice;
                scanf("%d", &verd_choice);

                if (verd_choice >= 1 && verd_choice <= 3) {
                    printf("Digite o peso do produto (%s): ", verduras[verd_choice-1].nome);
                    scanf("%f", &peso);
                    preco = verduras[verd_choice-1].precoGerais * peso;
                    printf("Preço: %.2f reais\n", preco);
                } else {
                    printf("Verdura inválida\n");
                }
                break;
            }
            case 'l': {
                printf("Escolha o legume:\n");
                for (int i = 0; i < 4; i++) {
                    printf("%d. %s\n", i+1, legumes[i].nome);
                }
                int legume_choice;
                scanf("%d", &legume_choice);

                if (legume_choice >= 1 && legume_choice <= 4) {
                    printf("Digite o peso do produto (%s): ", legumes[legume_choice-1].nome);
                    scanf("%f", &peso);
                    preco = legumes[legume_choice-1].precoGerais * peso;
                    printf("Preço: %.2f reais\n", preco);
                } else {
                    printf("Legume inválido\n");
                }
                break;
            }
            case 'f': {
                printf("Escolha a fruta:\n");
                for (int i = 0; i < 5; i++) {
                    printf("%d. %s\n", i+1, frutas[i].nome);
                }
                int fruta_choice;
                scanf("%d", &fruta_choice);

                if (fruta_choice >= 1 && fruta_choice <= 5) {
                    printf("Digite o peso do produto (%s): ", frutas[fruta_choice-1].nome);
                    scanf("%f", &peso);
                    preco = frutas[fruta_choice-1].precoGerais * peso;
                    printf("Preço: %.2f reais\n", preco);
                } else {
                    printf("Fruta inválida\n");
                }
                break;
            }
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
