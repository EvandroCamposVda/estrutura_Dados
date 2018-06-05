#include<stdio.h>

int main (){
	int vetor [5];
	int dec;
	int temporaria=0;
	int flag = 0;
	int i = 0;
	
	for (;;){
		printf ("1 - Cadastro\n2 - Orgaizar\n3- Salvar\n4 - Sair\nDigite sua operacao: ");
		scanf("%i", &dec);
		if (dec == 1){
			for (i=0;i<5;i++){
				printf ("Digite o valor para a posicao %i do vetor: ", i+1);
				scanf ("%i", &vetor[i]);
			}
			
			for (i=0;i<5;i++){
				printf (" | %i", vetor[i]);
			}
			
			printf ("\n\n");
		}
		
		if (dec == 2){
			for(;;){
				for(i=0;i<4;i++){
					if (vetor[i] > vetor[i+1]){
						temporaria = vetor[i+1];
						vetor[i+1] = vetor[i];
						vetor[i] = temporaria;
						flag = 1;
					}
				}
				if (flag == 0){
					break;
				}
				flag = 0;
			}
			for (i=0;i<5;i++){
				printf (" | %i", vetor[i]);
			}
			printf ("\n\n");
		}
		
		if (dec == 3){
			FILE *arquivo;
			
			arquivo = fopen("dados.txt", "w");
			
			for (i=0;i<5;i++){
				fprintf(arquivo, "%i | ", vetor[i]);
			}
			fclose(arquivo);
			
			printf ("Dados salvo com sucesso !\n\n");
		}
		
		else if (dec == 4){
			printf ("\n\nBye");
			break;
		}
	}
}
