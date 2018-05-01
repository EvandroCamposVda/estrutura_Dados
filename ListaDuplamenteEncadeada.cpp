#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

//Criei varias arvores por causa do problema de exibir

int flag_lista =0;
int flag_primeiro_valor=0;
int flag_ant_proximo =0;
int tamanho;//Tamanho dos dados
int posicao;//Usado para ter controle do cadastro de posicao
int inc;//Usado para definir posicao para excluir e alterar


char resposta[2];

void pause (float delay1) {

   if (delay1<0.001) return; // pode ser ajustado e/ou evita-se valores negativos.

   float inst1=0, inst2=0;

   inst1 = (float)clock()/(float)CLOCKS_PER_SEC;

   while (inst2-inst1<delay1) inst2 = (float)clock()/(float)CLOCKS_PER_SEC;

   return;

}

struct lista {
	
    struct lista *ponteiro_anterior;
	int valor;
	struct lista *ponteiro_proximo;

} *lista, *a, *b, *c, *d, *e, *f, *g, *h, *ex;

//a --> Aponta para a primeira posicao

//b --> Aponta para a ultima posicao 

//C --> Aponta para uma posicao especifica

//d --> VAriavel auxiliar de anterior

//e --> Variavel auxiliar de proximo 

//f --> Variavel auxiliar de adicionar

//g --> controle do atual para LISTA 4/5

//h --> controle do atual para LISTA 4/5

void carregar_lista(){
	
	lista = (struct lista*) malloc(sizeof(struct lista));
	
	if(lista != NULL){
		
		lista->ponteiro_anterior = NULL;
		lista->ponteiro_proximo = NULL;
		
	}
	else{
		
		printf("Erro no malloc!!");
	}
}

void Incluir_inicio (int inc){
	int valor = 0;
	
	do {
		if (flag_primeiro_valor == 0){
			system ("cls");
			printf ("Digite um valor a ser incluido na lista: ");
			scanf ("%d", &valor);
			
			lista->valor = valor;
			a = lista;
			b = a;
			
			flag_primeiro_valor = 1;
			
			posicao+=1;
			tamanho+=1;	
			
		}else if(flag_primeiro_valor == 1){
			system ("cls");
			printf ("Digite um valor a ser incluido na lista: ");
			scanf ("%d", &valor);
			
			lista->valor = valor;
			lista->ponteiro_proximo = a;
			a->ponteiro_anterior = lista;
			
			a = lista;
			e = lista;    
			
    		posicao+=1;
    		tamanho+=1;
    		
		}
	}while (valor == 0);	
}

void Incluir_fim (int fim){
	int valor = 0;
	do {
		system ("cls");
		
		printf ("Digite um valor para ser incluido no fim: ");
		scanf ("%d", &valor);
		
		lista->valor = valor;	
        b->ponteiro_proximo = lista;
		lista->ponteiro_anterior = b;
		
		b = lista;
		e = lista;  
		
		posicao+=1;
    	tamanho+=1;
    	
	}while (valor == 0);
}

void Incluir_posicao_especifica(int inc){
	
	int valor=0;
	
	do{
		system("cls");
	
			
		valor=0;	
		int position;
		int i = 2;  //referente a 2ª posição
		c = a;
			
		do{
				
			system("cls");
				
			printf("Digite a posicao para inserir o valor: ");
			scanf(" %i", &position);
			
				if(position >= 1 && position <= tamanho) {
  					break;
  				}
  						
				 else if ((position < 1) || (position >= tamanho + 1))
   					 {
        				printf("\n Posição Inexistente\n\n");
        				
        				
        				pause(1.5);
        				
  					  }
  					  
			}while(2>1);
			
  					
			  						
			  		if (position == 1){
			    		
			    			system("cls");
			    			int inc=1;
			      			Incluir_inicio(inc);
			      			
			      			flag_lista = 1;
			      			goto p;
			      			
			   			 }
			   		else
			   		{
			        
			    			system("cls");
			    			
			    			
			      			flag_lista = 3;
					
						while (i < position)
			        	{
			           	 	c = c->ponteiro_proximo;
			            	i+=1;
			        	}
			        		
						printf("Digite o valor para incluir: ");
						scanf(" %i", &valor);
							        	
							lista->valor = valor;
									
							d = lista;
											
						   	lista->ponteiro_anterior = c;
						        	
						   	lista->ponteiro_proximo = c->ponteiro_proximo;
						        	
						   	c->ponteiro_proximo->ponteiro_anterior = lista;
						        	
						   	c->ponteiro_proximo = lista;
						        	
							e = lista;  
				        	goto p;
			}	
		}while(valor == 0);	
		
		p:
   		posicao+=1;
    	tamanho+=1;
}

void Listar(){
	lista = a;
	system ("cls");
	printf ("Lista\n\n");
	while (lista->ponteiro_proximo != NULL){
        printf(" %d |", lista->valor);
        lista = lista->ponteiro_proximo;
    }
    printf(" %d ", lista->valor);
    printf("\n\n");
}
//Inicio Listar1 ---------------------------------------------------------------------------------------------------------------------------------------------
void Listar1(){//Esta sendo usado no listar infinito
	system("cls");
		if (tamanho == 0){
			printf ("A lista esta vazia !!!");
		}else {
			Listar();
			if (tamanho == 1){
				if (lista == NULL){
					lista = a;
					while (lista->ponteiro_proximo != NULL){
     			   		lista = lista->ponteiro_proximo;
  			 		}
					printf("| %d ",lista->valor);
				}else if(lista->ponteiro_anterior == NULL){
  			
  					lista=a;
  			
 					while (lista->ponteiro_proximo != NULL){
     			   		lista = lista->ponteiro_proximo;
  			 		}
  			 	printf("| %d ",lista->valor);
				}else{
					lista=lista->ponteiro_anterior;
					printf("| %d ",lista->valor);
				}if(lista->ponteiro_proximo==NULL){
  					lista=a;
					printf("| %d ",lista->valor);
				}else{
					lista= lista->ponteiro_proximo;
					printf("| %d ",lista->valor);
				}
				g=lista;
				if(lista->ponteiro_proximo == NULL){
					lista=a;
					printf("| %d ",lista->valor);
				}else {
					lista = lista->ponteiro_proximo;
					printf("| %d ",lista->valor);
				}
				
			}else if (tamanho > 1){
				
				if(lista == NULL){
  					lista=a;
  					
  					while (lista->ponteiro_proximo != NULL){
     			   		lista = lista->ponteiro_proximo;
  			 		}
  					printf("| %d ",lista->valor);
		
  				}else if(lista->ponteiro_anterior == NULL){
  					lista=a;
  					
  					while (lista->ponteiro_proximo != NULL){
     			   		lista = lista->ponteiro_proximo;
  			 		}
  			 	printf("| %d ",lista->valor);
		
  				}else{
					lista=lista->ponteiro_anterior;	
					printf("| %d ",lista->valor);
				}if(lista->ponteiro_proximo==NULL){
					
				  	lista=a;
					printf("| %d ",lista->valor);
				}else{
						
					lista= lista->ponteiro_proximo;
					printf("| %d ",lista->valor);
				}
				
				g=lista;
				
				if(lista->ponteiro_proximo == NULL){
					lista=a;	
					printf("| %d ",lista->valor);
				}else{
					lista = lista->ponteiro_proximo; 
					printf("| %d ",lista->valor);
				}	
			}
		}
	printf("\nANTERIOR | ATUAL | PROXIMO");
	printf ("\n");
}

//Inicio Listar2 ---------------------------------------------------------------------------------------------------------------------------------------------

void Listar2(){
	if (tamanho==1){
    
		lista = a;
	    
	    printf("| %d ",lista->valor);       	
		printf("| %d ",lista->valor);
		printf("| %d ",lista->valor);

	}else if (tamanho>1){
		Listar();
		lista = lista->ponteiro_anterior;
			           
		printf("| %d ",lista->valor);
		   
		lista=lista->ponteiro_proximo;
		
		g=lista;
		
		printf("| %d ",lista->valor);
	    
	    lista = a;	    
	             
		printf("| %d ",lista->valor);
	}
	
	printf("\n");
	printf("\nANTERIOR | ATUAL | PROXIMO");
	printf("\n");
}

//Inicio Listar3 ---------------------------------------------------------------------------------------------------------------------------------------------

void Listar3(){
	
	Listar();

	if (tamanho==1){
    
	lista = a;
	
    printf("| %d ",lista->valor);       
	printf("| %d ",lista->valor);
	printf("| %d ",lista->valor);
    
    
}
 else if (tamanho>1){
	
	lista = d->ponteiro_anterior;
	
	printf("| %d ",lista->valor);
	
	g=d;
	
	printf("| %d",d->valor);
        
    lista = d->ponteiro_proximo;
	    
	printf("| %d ",lista->valor);
           
    
}
		printf("\n");
					
		printf("ANTERIOR    |     ATUAL      |     PROXIMO");
			
		printf("\n");
			
}
//Inicio Listar4----------------------------------------------------------------------------------------------------------------------------------------------------------
void Listar4() {
	system("cls");
	
	Listar();
	
	printf("\n");
	
	if (tamanho==1){
    
		lista = a;
	    g=lista;
	    
	    printf("| %d ",lista->valor);       
		
		printf("| %d ",lista->valor);
		
		printf("| %d ",lista->valor);
    } else if (tamanho>1){
 	
		lista=g;
	    //  null 8 6 4 2 null
		lista=lista->ponteiro_anterior;
		printf ("\n");
	
		if(lista == NULL){
	  			
			lista=a;
			
		 	while (lista->ponteiro_proximo != NULL){
		       lista = lista->ponteiro_proximo;
		  	} 	
		  			 	
			lista=lista->ponteiro_anterior;
		  			
			printf("| %d ",lista->valor);
			
	  	} else if(lista->ponteiro_anterior == NULL){
	  			
		  	lista=a;
		  			
		 	while (lista->ponteiro_proximo != NULL){
		       lista = lista->ponteiro_proximo;
		  	}
		  					
			printf("| %d ",lista->valor);
			
	  	}else{
		
			lista=lista->ponteiro_anterior;	
			printf("| %d ",lista->valor);
		}
		
		if(lista->ponteiro_proximo==NULL){
			
		  	lista=a;
		  	
			printf("| %d ",lista->valor);	
			
		}else{
			
			lista= lista->ponteiro_proximo;
			printf("| %d ",lista->valor);
		}
		
		g=lista;
				
		if(lista->ponteiro_proximo == NULL){
			
			lista=a;	
			printf("| %d ",lista->valor);
			
		}else{
			
			lista = lista->ponteiro_proximo;    
			printf("| %d ",lista->valor);
			
		}
	}
	printf("\n");
	printf("ANTERIOR | ATUAL | PROXIMO");
	printf("\n");		
}

//Inicio Listar5 ---------------------------------------------------------------------------------------------------------------------------------------------

void Listar5(){
	system("cls");
			
	Listar();
	printf("\n");
	printf("\n");
			
	if (tamanho==1){
    
		lista = a;
	
	    printf("| %d ",lista->valor);       
		printf("| %d ",lista->valor);
		printf("| %d ",lista->valor);
	}
	
	else if (tamanho>1){
	 	lista=g;
	    //  null 8 6 4 2 null
		
		lista = lista->ponteiro_proximo;
		
		if(lista == NULL){
	  			
		  		lista=a;
		  			
		 		while (lista->ponteiro_proximo != NULL){
		    	   lista = lista->ponteiro_proximo;
		  		}
		  		printf("| %d ",lista->valor);
			
		}else if(lista->ponteiro_anterior == NULL){
	  			
		  		lista=a;
		  		
		 		while (lista->ponteiro_proximo != NULL){
		    	   lista = lista->ponteiro_proximo;
		  		}  			
				printf("| %d ",lista->valor);
			
	  	}else{
			lista=lista->ponteiro_anterior;	
			printf("| %d ",lista->valor);
		}
		
		
		if(lista->ponteiro_proximo==NULL){	
		  	lista=a;	
			printf("| %d ",lista->valor);
		}else{
				
			lista= lista->ponteiro_proximo;
			printf("| %d ",lista->valor);
		}
			
		g=lista;
		
		if(lista->ponteiro_proximo == NULL){		
			
			lista=a;
			printf("| %d ",lista->valor);
		} else{
			
			lista = lista->ponteiro_proximo;        
			printf("| %d ",lista->valor);		
		}
	}
	printf("\n");	
	printf("ANTERIOR | ATUAL | PROXIMO");
	printf("\n");
}



void ListarINFINITO(){
	
system("cls");
	int op_ap;
	if(tamanho==0){
		printf("     A LISTA ESTA VAZIA DE UM 'INCLUIR' PARA ACRESCENTAR DADOS.   ");
		printf(" \n");
		
	}else{
		if (tamanho==1){ 	
			g:
		 	Listar1();
			
		 	printf("\nAnterior(1)|     |(2)Proximo\nDIGITE 3 PARA SAIR\n");
			printf("Opcao: " );
			scanf(" %i", &op_ap);
							
							
			switch (op_ap){
					
				case(1) :				
					goto g;
					break;
			
				case(2) :		
					goto g;	
					break;
			
				case(3) :
					break;
						
				default:
					printf("OPCAO INVALIDA!!!\n");
					printf("Por favor, verifique novamente as opcoes.\n");
					pause(1.5);
				}
			}
	
	 	if (tamanho>1){
			
			int flag_controle_1=1;
			int cont_contador=0;
			
			i:
			
			if(flag_controle_1==1){
				
				Listar1();
				
				
				flag_controle_1=2;	
				cont_contador+=1;
				goto h;
			}
				
			if(flag_controle_1==2){			
						
				Listar4();
					
				if(cont_contador<(tamanho-1)){
				
					cont_contador+=1;
				} else{	
					cont_contador=0;
					flag_controle_1=1;
				}
			goto h;
			}
			
			if(flag_controle_1==3){			
					
				Listar5();
				flag_controle_1=2;
					
				goto h;
			}
				
			h:
			
		 	printf("\n");
				
			printf("Anterior(1)|     |(2)Proximo\n\nDIGITE 3 PARA SAIR\n");
			printf("Opcao: ");
			scanf(" %i", &op_ap);
						
						
			switch (op_ap){
		
				case(1) :
					goto i;
					
					
					break;
				case(2) :
					flag_ant_proximo = 1;
					flag_controle_1=3;
					
					goto i;
					
					break;
		
				case(3) :
				
					flag_ant_proximo = 0;
					break;
					goto i;
					
		
		
				default:
					printf("OPCAO INVALIDA!!!\n");
					printf("Por favor, verifique novamente as opcoes.\n");
					pause(1.5);
				break;
			}
		}
	}
}

void Incluir(int opcao){
  
	int valor;
	carregar_lista();
	
	if (tamanho == 0){
		// se a lista estiver vazia vai inserir no inicio
		
			system("cls");

			printf("A LISTA ESTA VAZIA, O VALOR SERA INCLUIDO NO INICIO.");
				
			inc = 1; 	
			
			pause(2.5);
			
			Incluir_inicio(inc);
			
			Listar1();
			
			system("pause");
			
	} else if(tamanho>0){
				
		system("cls");
	    printf("Escolha uma opcao para incluir:");
	 
		printf("\n");
		printf("1 - Incluir no inicio\n");
		printf("2 - Incluir no fim\n");
		printf("3 - Incluir em posicao especifica\n");
		printf("\n");
		scanf("%i", &inc);
		
		switch (inc){
	
			case(1):
				//INCLUI NO INICIO
				
				Incluir_inicio(inc);
				Listar1();
				
				system("pause");
				break;
	
			case(2):
				//INCLUI NO FIM
				Incluir_fim(inc);
				Listar2();
				
				system("pause");
				break;
	
			case(3):
				//INCLUI EM POSICAO ESPECIFICA
				
				Incluir_posicao_especifica(inc);
				
				
				if(	flag_lista == 3){
					
				Listar3();	
				system("pause");
				
				}
				else if(flag_lista == 1){
					Listar1();
					system("pause");
				}
				      			
				break;
				
			default:
				printf("OPCAO INVALIDA!!!\n");
				printf("Por favor, verifique novamente as opcoes.\n");
				pause(1.5);
			}
	system("cls");
	}   
}

void Excluir(int opcao){
	
	if (tamanho == 0){
	//se a lista estiver vazia
		system("cls");
		printf("A LISTA ESTA VAZIA DE UM 'INCLUIR NA LISTA' PARA ACRESCENTAR DADOS.");
		pause(2.5);
	}else if (tamanho > 0){	
		
		int valor=0;
		system("cls");	
		int position;
		int i = 0;  
		c = a;
			
			do{
			
			system("cls");
			printf("DIGITE A POSICAO: ");
			scanf(" %i", &position);
			
				if(position >= 1 && position <= tamanho) {
  					break;
  				}else if ((position < 1) || (position >= tamanho + 1)){
        			printf("\n Posicao Inexistente\n\n");
        			pause(1.5);
				}
			}while(2>1);
				
			int ps=0;
			//null  6  2   null //			
			
			system("cls");
			for(ps; ps<position-1;ps++){	
				c=c->ponteiro_proximo;
				i++;
			}
			
				
	
			system("cls");
			printf("EXCLUIR DA LISTA   ");
			printf(" \n");
			printf("-----------------------------------------------------------------------\n");
			printf("POSICAO A SER EXCLUIDA: | ");
			printf("%i", (i+1));
			printf(" \n");
			printf("-----------------------------------------------------------------------\n");
			printf("| VALOR: |      ");
			printf("%i", c->valor);
			printf(" \n");
			printf("-----------------------------------------------------------------------\n");
			printf(" \n");
			printf(" \n");
			printf(" \n");
			printf(" \n");		
			printf("-----------------------------------------------------------------------\n");
			printf("TEM CERTEZA QUE DESEJA EXCLUIR? ( S/N )  ");
			printf(" \n");
			printf("-----------------------------------------------------------------------\n");
			printf("| RESPOSTA: |      ");
			scanf(" %[^\n]s", resposta);
			strlwr(resposta);
			
			
			if(!strcmp(resposta,"n")){
				printf("Movimento de lista cancelado, sem alteracoes na LISTA!!!\n");
				printf(" \n");
			
				system("pause");
			}else if(!strcmp(resposta,"s")){
			
 				if (tamanho == 1){  //quando so ha um valor
      	
	  
            		if (c->ponteiro_proximo == NULL){
	            	  	printf("\n    Excluido com sucesso\n\n");
	                	//free desaloca espaço alocado
	                	free(c);
	                	c = a = NULL;
	                
	    				tamanho-=1;
	    			
						flag_primeiro_valor=0;
				
	    				printf("\n    da 1 POSICAO\n\n");
	    			
	    				system("pause");
	                	return;
    				}
    			}
    
    
    
	    	if (c->ponteiro_proximo == NULL){
	        	//ultimo valor
	        	
	        	printf("\nExcluido com sucesso\n\n");
	        	printf ("\n c->ponteiro_proximo == NULL)");

	            c=c->ponteiro_anterior;
				c->ponteiro_proximo = NULL;		
				c=c->ponteiro_proximo;
				
	            free(c);
	            
	            tamanho= tamanho - 1;
	    		
	    		system("pause");
	            return;
	        }else if (c->ponteiro_anterior == NULL){
				printf("\nExcluido com sucesso\n\n");
				printf ("c->ponteiro_anterior == NULL\n\n");
	        	
	        	ex=c;	        	
	            c=c->ponteiro_proximo;	            
				c->ponteiro_anterior = NULL;
				a=c;
				
				free(ex);
				
	            tamanho= tamanho - 1;
	    		
	    		system("pause");
	            return;		
			
			}else{
				printf("\nExcluido com sucesso\n\n");
				printf ("\nelse\n");
	        	
	        	c = c;
				c->ponteiro_anterior->ponteiro_proximo = c->ponteiro_proximo;
				c->ponteiro_proximo->ponteiro_anterior = c->ponteiro_anterior;  	
				
				free(c);
				
	            tamanho= tamanho - 1;
	    		
	    		system("pause");
	            return;		
			
			}
		}
	}
}

void Proximo_anterior(){
	ListarINFINITO();
}



int main (){

	int i=0 ;
	
	int opcao=0;
	
	
		system("cls"); 
		free(h);
		
		do{
	        printf("Escolha uma opcao\n\n");
	        printf("\n");
			printf("1 - Incluir na Lista\n");
			printf("2 - Excluir da Lista\n");
			printf("3 - Visualizar\n");
			printf("4 - Sair\n");
			printf("\n");
			printf ("Opcao: ");
			scanf("%i", &opcao);
			switch (opcao){
	
			case(1) :
				Incluir(opcao);
				break;
	
			case(2) :
				
				Excluir(opcao);
				break;
	
			case(3) :
				system("cls");
				Proximo_anterior();
				break;
	
			case(4) :
				return(0);
				break;
			default:
				printf("OPCAO INVALIDA!!!\n");
				printf("Por favor, verifique navamente as opcoes.\n");
				pause(1.5);
			}
	
		system("cls");
	}while(2>1);
	return(0);
}
