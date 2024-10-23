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

        struct Produto prodgen[10] = {
            {"Refrigerante 2L", 10.00},
            {"Salgadinho", 9.90},
            {"Cerveja", 3.99},
            {"Balas", 7.50},
            {"Detergente", 2.50},
            {"Chocolate", 3.59},
            {"Veja", 5.19},
            {"Oleo", 7.18},
            {"Nescau", 15.00},
            {"Milho de Pipoca", 14.10}
        };
        

        float peso, preco;
        char calculo;
        double precototal = 0.0;
        double contprod = 0;

        do {
            printf("Qual produto deseja escanear?\n");
            printf("v. Vegetais\n");
            printf("r. Verduras\n");
            printf("l. Legumes\n");
            printf("f. Frutas\n");
            printf("p. Produtos\n");
            printf("c. Fechar conta\n");
            printf("s. Saida\n");
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
                        printf("Preco: %.2f reais\n", preco);
                        precototal += preco;
                        contprod++;
                    } else {
                        printf("Vegetal invalido\n");
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
                        printf("Preco: %.2f reais\n", preco);
                        precototal += preco;
                        contprod++;
                    } else {
                        printf("Verdura invalida\n");
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
                        printf("Preco: %.2f reais\n", preco);
                        precototal += preco;
                        contprod++;
                    } else {
                        printf("Legume invalido\n");
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
                        printf("Preco: %.2f reais\n", preco);
                        precototal += preco;
                        contprod++;
                    } else {
                        printf("Fruta invalida\n");
                    }
                    break;
                }
                case 'p': {
                    printf("Escolha o produto:\n");
                    for (int i = 0; i < 5; i++) {
                        printf("%d. %s\n", i+1, prodgen[i].nome);
                    }
                    int prodgen_choice;
                    scanf("%d", &prodgen_choice);

                    if (prodgen_choice >= 1 && prodgen_choice <= 5) {
                        printf("Quantas unidades deseja? (%s): ", prodgen[prodgen_choice-1].nome);
                        scanf("%f", &peso);
                        preco = prodgen[prodgen_choice-1].precoGerais * peso;
                        printf("Preco: %.2f reais\n", preco);
                        precototal += preco;
                        contprod++;
                    } else {
                        printf("Produto invalido\n");
                    }
                    break;
                }
                case 'c':{
                    printf("Fechar conta\n");
                    scanf("%c", &calculo);
                }
                case 's':{
                    printf("Saindo...\n");
                    if (contprod > 0){
                        printf("Preco Total: %.2f reais\n", precototal);
                    }
                    
                    break;
                }
                default:
                    printf("Operacão invalida\n");
                    break;
            }
        } while (calculo != 's');

        printf("Fim da execucao\n");
        return 0;
    }
