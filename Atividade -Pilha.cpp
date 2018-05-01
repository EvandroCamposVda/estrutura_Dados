#include <stdio.h>
#include <stdlib.h>

int main (){
	int vetor[5];
	int posicao = 0;
	int valor;
	int dec;
	int i=0;
	int j=0;
	
	for (j=0;j<5;j++){
		vetor[j] = 0;
	}
	
	while (1){
		printf ("------------------------------------------------------------\n");
		printf ("1 - Push (inserir)\n2 - Pop (Remover)\n3 - Fechar\nDigite sua operacao:");
		scanf ("%d", &dec);
		if (dec == 1){
			if (i == 5){
				system ("cls");
				printf ("Comando PUSH Impossivel ! Sem espaco para adicionar dados !\n\n");
				system ("pause");
			}else {
				printf ("Digite o valor para o PUSH: ");
				scanf("%d", &valor);
				vetor[i] = valor;
				i++;
				printf ("Comando Push Efetuado !\n\n");
				printf ("------------------------------------------------------------\n");
				for (j=0;j<5;j++){
					printf ("%d - ", vetor[j]);
				}
				printf ("\n");	
			}
		}else if (dec == 2){
			if (i==0){
				printf ("------------------------------------------------------------\n");
				printf ("\n\nComando POP Impossivel ! Sem dados para serem removidos !\n\n");
			}else {
				i--;
				vetor [i] = 0;
				printf ("\nDados Removidos com Sucesso !\n");
				printf ("------------------------------------------------------------\n");
				for (j=0;j<5;j++){
					printf ("%d - ", vetor[j]);
				}
				printf ("\n");
			}
		}else if (dec == 3){
			system ("cls");
			printf ("Fila final !\n\n");
			for (i=0;i<5;i++){
				printf ("%d - ", vetor[i]);
			}
			break;
		}else {
			system ("cls");
			printf ("Comando invalido !\n\n");
			system("pause");
			system("cls");
		}
	}
}
