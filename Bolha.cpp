#include <stdio.h>

int main () {
	int vetor[5];
	int dec;
	int flag=0;
	int temporaria=0;
	
	printf("1 - Inserir Dados\n2 - Organizar Lista\n3 - Listar\n\nDigite sua operacao: ");
	scanf("%i", &dec);
		if(dec == 1){
			for (int i=0;i<5;i++){
				printf ("Digite o valor %i do vetor: ", i+1);
				scanf("%i", &vetor[i]);
			}
			printf ("Dados obtidos\n\n");
			for (int i=0;i<5;i++){
				printf (" | %i", vetor[i]);
			}
		}
		if (dec == 2){
			for (;;){
				if(flag == 0) {
					for (int i=0;i<5;i++){
						if (vetor[i] > vetor[i+1]){
							temporaria = vetor[i];
							vetor[i] = vetor[i+1];
							vetor[i+1] = temporaria;
							flag = 1;
						}
					}
				}
			}
		}
				
	
	
}
