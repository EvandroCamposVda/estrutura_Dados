#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <time.h>
#include <windows.h>

#define UM 49
#define DOIS 50
#define TRES 51
#define QUATRO 52
#define CINCO 53
#define SEIS 54
#define ACIMA 72
#define ABAIXO 80
#define DIREITA 77
#define ESQUERDA 75
#define del 22

int quant = 0;
int i=0;

struct arvore
{
	int valor;
	struct arvore *ant;
	struct arvore *direita;
	struct arvore *esquerda;
};

int valores[50];
int ops2 = 1, num;
int cont = 0;
int vetortxt[50];

//GRAVA OS VALORES ORGANIZADOS EM "pre-ordem.txt"

void grava(){
	FILE *arqGRAVA;
	arqGRAVA = fopen("pre-ordem.txt", "w");
	for (int i = 0; i <= cont; i++){
		fprintf(arqGRAVA, " %d", valores[i]);
	}
	fclose(arqGRAVA);
	_getch();
}

void apaga(){
	remove("pre-ordem.txt");
}



//PEGA OS VALORES DO ARQUIVO "pega.txt" 

void pega(){
	FILE *arqPEGA;
	arqPEGA = fopen("pre-ordem.txt", "r");
	if (arqPEGA == NULL){
		printf("ERROR 404 FILE NOT FOUND");
	}
	else{
		while ((fscanf(arqPEGA, "%d ", &num)) != EOF)
			(vetortxt[quant] = num, quant++);

		fclose(arqPEGA);
	}
}

//ORGANIZA OS VALORES DA ARVORE EM PRÉ-ORDEM

void backup(arvore *raiz)
{
	if (ops2 == 1){
		if (raiz != NULL){
			if (raiz->valor != 0){
				printf(" %d|", raiz->valor);
			}
			valores[cont] = raiz->valor;
			cont++;
			backup(raiz->esquerda);
			backup(raiz->direita);
		}
	}
}

int main()
{
	arvore *atual = NULL;
	arvore *posisaoAnterior = NULL;
	arvore *primeiro = NULL;
	arvore *aux = NULL;
	arvore *posicaoAtual = NULL;
	boolean teste = true,testarq=false;
	int ajuda = 0;
	int sair = 0;
	int ops;

	//menu de opsões

	while (sair == 0){
		system("cls");
		printf("1--> Inserir elementos na arvore\n");
		printf("2--> Procurar um numero na arvore\n");
		printf("3--> Percorer a arvore\n");
		printf("4--> Backup\n");
		printf("5--> Pega valor\n");
		printf("6--> Sair ");
		ops = _getch();
		if (ops == SEIS){
			char a;
			system("cls");
			printf("Realmente deseja sair? (1 sair/2 continuar)\n");
			a = _getch();
			if ((a == UM)){
				sair++;
			}
		}
		else if (ops==CINCO){
			if (primeiro == NULL){
				testarq = true;
				pega();
				for (i = 0; i <= quant; i++){
					if (primeiro != NULL){
						ajuda = vetortxt[i];
						goto gravar;
					}
					else{
						system("cls");
						aux = (struct arvore *)malloc(sizeof(struct arvore));
						atual = aux;
						aux->valor = vetortxt[i];
						fflush(stdin);
						aux->ant = NULL;
						aux->direita = NULL;
						aux->esquerda = NULL;
						primeiro = aux;
						posicaoAtual = aux;
					}
				r:
					printf("");
				}
				system("cls");
				printf("\n\nDados restaurados com sucesso!!! ");
				_getch();
			}
			else{
				system("cls");
				printf("\n\nA arvore ja contem elementos!!!");
				_getch();
			}
			testarq = false;
		}
		else if (ops == QUATRO){
			system("cls");
			if (primeiro == NULL){
				printf("\n\nArvore vazia!!!");
			}
			else{
				apaga();
				backup(primeiro);
				grava();

			}
		}

		// inserir elementos na arvore

		else if (ops == UM){

			//se a arvore estiver vazia-------------------------------------------------------------------------------------------

			if (primeiro == NULL){
				system("cls");
				aux = (struct arvore *)malloc(sizeof(struct arvore));
				atual = aux;
				printf("Informe um numero ");
				scanf("%d", &aux->valor);
				fflush(stdin);
				aux->ant = NULL;
				aux->direita = NULL;
				aux->esquerda = NULL;
				primeiro = aux;
				posicaoAtual = aux;
			}

			// se ja tem numeros na arvore

			else if (primeiro != NULL){
				system("cls");
				printf("Informe um numero ");
				scanf("%d", &ajuda);
			gravar:
				fflush(stdin);
				arvore *fim = primeiro;
				posisaoAnterior = primeiro;

				//percorendo a arvore-------------------------------------------------------------------------------------------

				while (fim != NULL){
					if (ajuda > fim->valor){
						fim = fim->direita;
					}
					else if (ajuda < fim->valor){
						fim = fim->esquerda;
					}
					else if (ajuda == fim->valor){
						fim = NULL;
						teste = false;
					}
					if (fim != NULL){
						posisaoAnterior = fim;
					}
				}

				//configurando os ponteiros----------------------------------------------------------------------------------

				if (teste == true){
					aux = (struct arvore *)malloc(sizeof(struct arvore));
					atual = aux;
					aux->valor = ajuda;
					aux->direita = NULL;
					aux->esquerda = NULL;
					aux->ant = posisaoAnterior;
					aux = aux->ant;

					//testando o lado que sera salvo--------------------------------------------------------------------------------

					if (ajuda < aux->valor){
						aux->esquerda = atual;
					}
					else if (ajuda > aux->valor){
						aux->direita = atual;
					}
				}
			}
			system("cls");
			if (testarq == true){
				goto r;
			}
			if (teste == true){
				printf("\n\n\n\nValor (%d) salvo na arvore!!!\n\n", atual->valor);
			}
			else{
				printf("\n\n\n\nO valor (%d) ja esta salvo na arvore, portanto não sera repitido!!!\n\n", ajuda);
			}
			teste = true;
			_getch();
		}

		//caminhando entre os galhos da arvore

		else if (ops == TRES){
			int tecla = 0;
			int test;
			posicaoAtual = primeiro;
			if (primeiro == NULL){
				system("cls");
				printf("\n\n\nArvore vazia!!!");
				_getch();
			}

			if (primeiro != NULL){
				while (tecla != ABAIXO){
					if ((posicaoAtual != NULL) && (posicaoAtual->esquerda != NULL) && (posicaoAtual->direita != NULL)){
						system("cls");
						printf("\n\nPara percorer a arvore use as seta <^>, para deletar precione 1, e para sair precione a tecla para baixo\n\n\n");
						printf("\n\n----------");
						printf("[%d]", posicaoAtual->valor);
						printf("----------\n"
							"------[%d]----[%d]------", posicaoAtual->esquerda->valor, posicaoAtual->direita->valor);
						test = 111;
					}
					else if ((posicaoAtual != NULL) && (posicaoAtual->direita != NULL) && (posicaoAtual->esquerda == NULL)){
						system("cls");
						printf("\n\nPara percorer a arvore use as seta <^>, para deletar precione 1, e para sair precione a tecla para baixo\n\n\n");
						printf("\n\n----------");
						printf("[%d]", posicaoAtual->valor);
						printf("----------\n"
							"-------[*]----[%d]------", posicaoAtual->direita->valor);
						test = 101;
					}
					else if ((posicaoAtual != NULL) && (posicaoAtual->esquerda != NULL) && (posicaoAtual->direita == NULL)){
						system("cls");
						printf("\n\nPara percorer a arvore use as seta <^>, para deletar precione 1, e para sair precione a tecla para baixo\n\n\n");
						printf("\n\n----------");
						printf("[%d]", posicaoAtual->valor);
						printf("----------\n"
							"------[%d]----[*]-------", posicaoAtual->esquerda->valor);
						test = 110;
					}
					else if ((posicaoAtual != NULL) && (posicaoAtual->esquerda == NULL) && (posicaoAtual->direita == NULL)){
						system("cls");
						printf("\n\nPara percorer a arvore use as seta <^>, para deletar precione 1, e para sair precione a tecla para baixo\n\n\n");
						printf("\n\n----------");
						printf("[%d]", posicaoAtual->valor);
						printf("----------\n"
							"-------[*]----[*]-------");
						test = 100;
					}
					tecla = _getch();
					if (tecla == ACIMA){
						if (posicaoAtual != primeiro){
							posicaoAtual = posicaoAtual->ant;
						}
					}
					else if (tecla == ESQUERDA){
						if (posicaoAtual->esquerda != NULL){
							posicaoAtual = posicaoAtual->esquerda;
						}
					}
					else if (tecla == DIREITA){
						if (posicaoAtual->direita != NULL){
							posicaoAtual = posicaoAtual->direita;
						}
					}

					//Deletar termos

					else if (tecla == UM){

						//se for a folha

						if (test == 100){
							arvore *temporaria = posicaoAtual;
							if (posicaoAtual != primeiro){
								posicaoAtual = posicaoAtual->ant;
								if (posicaoAtual->valor > temporaria->valor){
									posicaoAtual->esquerda = NULL;
								}
								else{
									posicaoAtual->direita = NULL;
								}
								free(temporaria);
							}
							else
							{
								tecla = ABAIXO;
								primeiro = NULL;
								free(posicaoAtual);
							}
						}

						// com filho a esquerda

						else if (test == 110){
							arvore *temporaria = posicaoAtual;
							if (posicaoAtual == primeiro){
								posicaoAtual = posicaoAtual->esquerda;
								posicaoAtual->ant = NULL;
								primeiro = posicaoAtual;
							}
							else{
								posicaoAtual = posicaoAtual->ant;
								posicaoAtual->direita = posicaoAtual->direita->esquerda;
								posicaoAtual = posicaoAtual->direita;
								posicaoAtual->ant = posicaoAtual->ant->ant;
							}
							free(temporaria);
						}

						// com filho a direita

						else if (test == 101){
							arvore *temporaria = posicaoAtual;
							if (posicaoAtual == primeiro){
								posicaoAtual = posicaoAtual->direita;
								posicaoAtual->ant = NULL;
								primeiro = posicaoAtual;
							}
							else{
								posicaoAtual = posicaoAtual->ant;
								posicaoAtual->direita = posicaoAtual->direita->direita;
								posicaoAtual = posicaoAtual->direita;
								posicaoAtual->ant = posicaoAtual->ant->ant;
							}
							free(temporaria);
						}

						// galho com dois filhos

						else if (test == 111){
							arvore *temporaria = posicaoAtual;
							
							temporaria = temporaria->esquerda;
							
							while (temporaria->direita != NULL){
								temporaria = temporaria->direita;
							}
							
							printf ("%d", temporaria->valor);
							
							if (temporaria->esquerda == NULL){
								posicaoAtual->valor = temporaria->valor;
								temporaria->ant->direita = NULL;
								free(temporaria);
							}else {	
								posicaoAtual->valor = temporaria->valor;
								temporaria->ant->direita = temporaria->esquerda;
								temporaria->esquerda->ant = temporaria->ant;
								free(temporaria);
							}							
						}
					}
					test = 0;
				}
			}
		}

		// encontra um numero especifico

		else if (ops == DOIS){
			if (primeiro == NULL){
				system("cls");
				printf("\n\n\nArvore vazia!!!");
			}
			else if (primeiro != NULL){
				int valor;
				int fim = NULL;
				posicaoAtual = primeiro;
				system("cls");
				printf("\n\n Informe o valor a ser procurado\n ");
				scanf("%d", &valor);
				fflush(stdin);
				while (fim == NULL){
					if (valor == posicaoAtual->valor){
						printf("\n\nO numero [%d] esta na arvore!!!\n\n", posicaoAtual->valor);
						fim = 1;
					}
					else if (valor > posicaoAtual->valor){
						posicaoAtual = posicaoAtual->direita;
					}
					else if (valor < posicaoAtual->valor){
						posicaoAtual = posicaoAtual->esquerda;
					}
					if (posicaoAtual == NULL){
						printf("\n\nO numero [%d] não pertence a esta arvore\n\n!!!", valor);
						fim = 1;
					}
				}
			}
			_getch();
		}
		else{
			system("cls");
			printf("\n\nComando não reconhacido pelo sistema!!!");
			_getch();
			system("cls");
		}
	}
}
