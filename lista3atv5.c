#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 100
typedef struct emprestimo{
	 	int data;
	 	char nomepessoa[30];
	 	char emprestado[1];
	}temprestimo;
	
typedef struct jogo{

	char nome[30];
	char console[15];
	int ano;
	int ranking;
	struct emprestimo;
}tjogo;
int qtd=0;
//------------------------------------------------------
int addjogo(tjogo b[]){
	if(qtd==MAX)
	   return 0;
	printf("***** Dados para o usuario %d *****\n",qtd+1);
	fflush(stdin);
	printf("nome:");
	gets(b[qtd].nome);
		fflush(stdin);
	printf("console");
	gets(b[qtd].console);
	printf("ano");
	scanf("%d",&b[qtd].ano);
	printf("ranking");
	scanf("%d",&b[qtd].ranking);
	printf("data");
	scanf("%d",&b[qtd].data);
		fflush(stdin);
	printf("nome pessoa");
	gets(b[qtd].nomepessoa);
		fflush(stdin);
	printf("emprestimo");
	gets(b[qtd].emprestado);
	
	qtd++;
	return 1;
} 
//-------------------------------------------------------
void buscaconsole(tjogo b[], char nomebusca[]){
	int i, encontrou=0;
	char nomeconsole[15];
	for(i=0;i<qtd;i++){
		strcpy(nomeconsole, b[i].console);
		if(strcmp(strupr(nomeconsole) , strupr(nomebusca) )==0){ // iguais
			printf("\n----------- console %d ---------\n",i+1);
			printf("nome:%s\nconsole:%s\nano:%d\n",
		       b[i].nome, b[i].console, b[i].ano);
			printf("-------------------------------\n");
		encontrou=1;
		break; // para o laço de repetição
	   }
	}// fim for
	if(!encontrou) // se nao encontrou
	   printf("console nao encontrado\n");
}
//-------------------------------------------------------
void buscanome(tjogo b[], char nomebusca[]){
	int i, encontrou=0;
	char nomejogo[40];
	for(i=0;i<qtd;i++){
		strcpy(nomejogo, b[i].nome);
		if(strcmp(strupr(nomejogo) , strupr(nomebusca) )==0){ // iguais
			printf("\n----------- jogo %d ---------\n",i+1);
			printf("nome:%s\nconsole:%s\nano:%d\nranking:%d\ndata:%d\nnome da pessoa:%s\nemprestado:%s",
		       b[i].nome, b[i].console, b[i].ano, b[i].ranking,b[i].data,  b[i].nomepessoa,b[i].emprestado);
			printf("-------------------------------\n");
		encontrou=1;
		break; // para o laço de repetição
	   }
	}// fim for
	if(!encontrou) // se nao encontrou
	   printf("jogo nao encontrado\n");
}
//-------------------------------------------------------
int emprestimo(tjogo b[]){
	if(qtd==MAX)
	   return 0;
	printf("***** Dados do usuario que pegou emprestado %d *****\n",qtd+1);
	fflush(stdin);
	printf("nome:");
	gets(b[qtd].nome);
	printf("data");
	scanf("%d",&b[qtd].data);
	printf("emprestado:");
	gets(b[qtd].emprestado);
	
	qtd++;
	return 1;
} 
//--------------------------------------------------------
void devolucao(tjogo b[], char nomebusca[]){
	int i, encontrou=0;
	char nomepessoa[40];
	for(i=0;i<qtd;i++){
	
		if (devolucao=="n"){ // iguais
			printf("\n----------- jogo %d ---------\n",i+1);
			printf("nome:%s\nconsole:%s\nano:%d\nranking:%d\ndata:%d\nnome da pessoa:%s\n",
		       b[i].nome, b[i].console, b[i].ano, b[i].ranking,b[i].data,  b[i].nomepessoa);
			fflush(stdin);
			printf("emprestado:");
			gets(b[qtd].emprestado);
				printf("-------------------------------\n");
		encontrou=1;
		break; // para o laço de repetição
	   }
	   else // se nao encontrou
	   printf("jogo ja devolvido\n");
	}// fim for
	
}
//------------------------------------------------------
int menu(){
	int op;
	printf("*** sistema de locadora TGAMES ****\n");
	printf("1-Inserir novo jogo\n");
	printf("2-inserir novo jogo no console\n");
	printf("3-realizar o emprestimo do jogo\n");
	printf("4-devolucao do jogo\n");

	scanf("%d",&op);
	return op;
}
//-----------------------------------------------------
	int main(){
	tjogo jogo[MAX];
	char nomebusca[15];
	int op, numero;

    do{
       op = menu();	
      switch(op){
      	case 1: addjogo(jogo);
      	break;
    
      	case 2: printf("Nome do console para buscar:");
      			fflush(stdin); gets(nomebusca);
      			buscaconsole(jogo, nomebusca);
      	break;	
      case 3:	emprestimo(jogo);
		break;	
	  case 4: printf("Nome do console para buscar:");
      			fflush(stdin); gets(nomebusca);
      			devolucao(jogo, nomebusca);
		
      
	  }
      	getch(); // pausa na tela - espera digitar uma tecla
      	system("cls");
	}while(op!=0);
	return 0;
}		
