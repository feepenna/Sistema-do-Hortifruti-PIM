    #include <stdio.h>
    #include <locale.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>
    #include <unistd.h>
    #define LIMPA_BUFFER fflush(stdin); //macro de limpeza pro buffer de teclado

    struct endereco{
        char rua[50];
        int numero;
        char cidade[30];
    };

    typedef struct cadastro{
	char nome[50];
	int idade;
	struct endereco ender;			//Declara variável ender do tipo endereco
} Cadastro;							//tipo "struct cadastro" será chamado apenas de "Cadastro"

void gravaArquivo(Cadastro *pC, int n){ 			//pC aponta para vetor c, n recebe o número de clientes
	FILE *arq; 										//Declara ponteiro para manipular arquivo
	arq = fopen("clientes.txt", "wb");				//abre arquivo clientes.txt em modo escrita binária
	if(arq == NULL){								//Testa se arquivo foi aberto corretamente
		puts("Erro na abertura do arquivo");
		exit(1);
	}
	int bls_gravados;  								//Variável p/ coletar retorno de fwrite, que deve coincidir com o valor de n
	bls_gravados = fwrite(pC, sizeof(Cadastro), n, arq);
	if(bls_gravados != n){
		puts("Erro na escrita do arquivo");
	}
	fclose(arq);
}

void leArquivo(Cadastro *pC, int n){
	FILE *arq;
	arq = fopen("clientes.txt", "rb"); 				//abre arquivo clientes.txt em modo leitura binária
	if(arq == NULL){
		puts("Erro na abertura do arquivo");		//Haverá erro caso o arquino clientes.txt não exista no diretório do código-fonte
		exit(1);
	}
	int bls_lidos;									//Variável p/ coletar retorno de fread, que deve coincidir com o valor de n
	bls_lidos = fread(pC, sizeof(Cadastro), n, arq);
	if(bls_lidos != n){
		puts("Erro na leitura do arquivo");
	}
	fclose(arq);
}

void cadastraCliente(Cadastro *pC, int i){
	printf("Nome do cliente %d: ", i);
	LIMPA_BUFFER
	scanf("%49[^\n]", pC[i].nome);
	printf("Idade do cliente %d: ", i);
	scanf("%d", &pC[i].idade);
	printf("Endereço do cliente %d\n", i);
	printf("Rua: ");
	LIMPA_BUFFER
	scanf("%49[^\n]", pC[i].ender.rua);
	printf("Número: ");
	scanf("%d", &pC[i].ender.numero);
	printf("Cidade: ");
	LIMPA_BUFFER
	scanf("%29[^\n]", pC[i].ender.cidade);
}

int adicionarMaisClientes() {
    char resposta;
    
    printf("Deseja adicionar mais clientes? (S/N): ");
    LIMPA_BUFFER
    scanf("%c", &resposta);
    
    return (resposta == 'S' || resposta == 's');
}
    

    struct Produto {
        char nome[30];
        float precoGerais;
    };

    int main(){
        setlocale(LC_ALL, "Portuguese");
        Cadastro c[3];	//Cria o cadastro c (cliente), de 3 posições
	int i=0;
	char op;
	
	do{
		system("cls");
		puts("Escolha uma opção: ");
		puts("1. Cadastrar clientes");
		puts("2. Consultar dados de cliente");
		puts("3. Alterar cadastro");
		puts("4. Exibir clientes cadastrados");
		puts("5. Sair");
		LIMPA_BUFFER
		scanf("%c", &op);
		
		switch(op){
			
			//Cadastrar clientes "do zero"
			case '1':					
				for(i=0; i<3; i++){		//Laço de coleta de dados
					cadastraCliente(c, i);

					if (!adicionarMaisClientes()) {
						break;
					}
				}
				gravaArquivo(c, 3);
				puts("Cadastro realizado com sucesso.");
				break;
			
			//Consultar dados de cliente específico
			case '2':					
				do{
					printf("Consultar dados do cliente [0, 1 ou 2]: ");
					scanf("%d", &i);
				} while (i<0 || i>2);
				leArquivo(c, 3);
				printf("Nome: %s \nIdade: %d \n", c[i].nome, c[i].idade);
				printf("Endereço: Rua %s, %d, %s.\n", c[i].ender.rua, c[i].ender.numero, c[i].ender.cidade);
				system("pause");
				break;
			
			//Alterar dados de cliente específico
			case '3':					
				do{
					printf("Alterar dados do cliente [0, 1 ou 2]: ");
					scanf("%d", &i);
				} while (i<0 || i>2);
				leArquivo(c, 3);
				cadastraCliente(c, i);
				gravaArquivo(c, 3);
				puts("Alteração realizada com sucesso.");
				system("pause");
				break;			

			//Exibir clientes cadastrados
			case '4':					
				printf("Clientes cadastrados \n\n");
				leArquivo(c, 3);
				for(i=0; i<3; i++){
					printf("Cliente %d: \n", i);
					printf("Nome: %s \nIdade: %d \n", c[i].nome, c[i].idade);
					printf("Endereço: Rua %s, %d, %s.\n\n", c[i].ender.rua, c[i].ender.numero, c[i].ender.cidade);
				}
				system("pause");
				break;			

			default:
				if(op!='5'){
					puts("Opção inválida");
					sleep(1);
				}	
				
		}
		
		
	} while(op!='5');

        // Definindo os produtos 35 itens
        struct Produto vegetais[4] = {
            {"Alho", 10.00}, //Pacote
            {"Cebola", 4.00},
            {"Pimentão", 10.00},
            {"Salsinha", 2.50}
        };
        struct Produto verduras[4] = {
            {"Alface", 3.00}, //unidade
            {"Couve", 3.50}, //unidade
            {"Couve-Flor", 8.00}, //unidade
            {"Brócolis", 6.00} //unidade
        };
        struct Produto legumes[8] = {
            {"Abóbora", 5.00},
            {"Batata Doce", 6.00},
            {"Batata", 4.50},
            {"Cenoura", 5.00},
            {"Chuchu", 3.00},
            {"Mandioquinha", 10.00},
            {"Milho", 2.50},
            {"Mandioca", 13.00}
        };
            struct Produto frutas[17] = {
            {"Abacate", 8.99},
            {"Abacaxi", 7.50}, //unidade
            {"Ameixa", 15.00},
            {"Banana", 4.50},
            {"Caju", 12.00},
            {"Laranja", 5.00},
            {"Maçã", 8.00},
            {"Manga", 7.00},
            {"Maracujá", 14.00}, //unidade
            {"Melancia", 3.50}, //unidade
            {"Melão", 10.00},
            {"Mexerica", 6.00},
            {"Morango", 18.00},
            {"Pera", 12.00},
            {"Pêssego", 14.00},
            {"Tomate", 9.00},
            {"Uva", 12.00}
        };
        struct Produto prodgen[10] = {
            {"Refrigerante 2L", 10.00},
            {"Salgadinho", 9.90},
            {"Cerveja", 3.99},
            {"Balas", 7.50},
            {"Detergente", 2.50},
            {"Chocolate", 3.59},
            {"Limpadpr Multiuso", 5.19},
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
