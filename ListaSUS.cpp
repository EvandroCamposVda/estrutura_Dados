#include<stdio.h>
#include<String.h>
#include<stdlib.h>

main (){
	int idade1[10];//normal
	int idade2[10];//preferencial
	char fila1[10][90];//normal
	char fila2[10][90];//preferencial
	int posicao1 = 0;
	int posicao2 = 0;
	int cont1 = 0;
	int cont2 = 0;
	int sai1 = 0;
	int sai2 = 0;
	int dec;
	int idade;
	char nome[90] = "";
	int i = 0;
	
	for (i=0;i<10;i++){
		idade1[i] = 0;
		idade2[i] = 0;
		strcpy(fila1[i], nome);
		strcpy(fila2[i], nome);
	}
	
	
	for (;;){
		printf ("1 - Adicionar\n2 - Atender\n3 - Fechar\nDigite sua operacao: ");
		scanf ("%d", &dec);
		
		if (dec == 1){	
		
			printf ("Digite o nome: ");
			scanf ("%s", &nome);
			printf ("Digite a idade: ");
			scanf ("%d", &idade);
			printf ("\n");
				
			if (idade > 60){
				if(cont2 == 10) {
					printf ("Nao foi possivel adicionar um paciente !\nFila preferencial cheia !\n");
				}else {
					if (idade2[posicao2] == 0){
						idade2[posicao2] = idade;
						strcpy(fila2[posicao2], nome);
							
						if (posicao2 == 9){
							posicao2 = 0;
						}
						
						posicao2++;
						cont2++;
					}else {
						printf ("Deu Bug !!! kkkkk");
					}
				}
					
			}else {
				if (cont1 == 10){
					printf ("Nao foi possivel adicionar um paciente !\nFila cheia !\n");	
				}else {
					idade1[posicao1] = idade;
					strcpy(fila1[posicao1], nome);
					posicao1++;
				}
			}
		}else if (dec == 2){
			if (cont2 > 0){
				if (sai2 == 9){
					sai2 = 0;
				}
				
				strcpy(fila2[posicao2], "");
				idade2[sai2] = 0;
				cont2--;
				sai2++;
			}else {
				if (cont1 == 9){
					cont1 = 0;
				}
				strcpy(fila1[posicao1], "");
				idade1[sai1] = 0;
				cont1 --;
				sai1 ++;
			}
		}else if (dec == 3){
			printf ("Ate logo !");
			break;
			system("exit");
		}
		system("cls");
		printf ("Fila Normal !\n\n");
		for (i=0;i<10;i++){
			if (idade1[i] == 0){
				
			}else {
				printf ("%s, %d | ", fila1[i], idade1[i]);
			}
		}
		printf ("\n\nFila Preferencial !\n\n");
		for (i=0;i<10;i++){
			if (idade2[i] == 0){
				
			}else {
				printf ("%s, %d | ", fila2[i], idade2[i]);
			}
		}
		printf ("\n\n");
	}
}
	

