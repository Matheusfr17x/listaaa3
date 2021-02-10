#include <stdio.h>
#include <string.h>
#define MAX 15

typedef struct livraria{
	char nome[30];
	char autor[15];
	int ano;
	int prateleira;

	
	
}tlivraria;
int qtd=0;
//---------------------//
int addlivraria(tlivraria t[]){
	if(qtd==MAX)
		return 0;
				
	printf("***** Dados para livros %d *****\n",qtd+1);
	fflush(stdin);
	printf("Nome:");
	gets(t[qtd].nome);
	fflush(stdin);
	printf("\nautor:");
	gets(t[qtd].autor);
	printf("ano:");
	scanf("%d",&t[qtd].ano);
	printf("prateleira:");
	scanf("%d",&t[qtd].prateleira);
qtd++;
	return 1;
								}
//---------------------//
void mostralivraria(tlivraria t[]){
	int i;
	for(i=0;i<qtd;i++){
	
		
	printf("\n----------- livros %d --------- \n",i+1);
	printf("Nome:%s\nautor:%s\nano:%d\nprateleira:%d\n",
	       t[i].nome, t[i].autor,t[i].ano, t[i].prateleira);
	   
	       	printf("-----------------\n");
	      	 }//fimfor
	      	}
//---------------------//
void buscalivro(tlivraria t[], char nomebusca[]){
	int i, encontrou=0;
	char nomelivro[30];
	for(i=0;i<qtd;i++){
		strcpy(nomelivro, t[i].nome);
		if(strcmp(strupr(nomelivro) , strupr(nomebusca) )==0){ // iguais
		printf("\n----------- Banda %d ---------\n",i+1);
			printf("Nome:%s\nautor:%s\nano:%d\nprateleira:%d\n",
	       t[i].nome, t[i].autor,t[i].ano, t[i].prateleira);
		printf("-------------------------------\n");
		encontrou=1;
		break; // para o laço de repetição
	   }
	}// fim for
	if(!encontrou) // se nao encontrou
	   printf("livro nao encontrado :(");
}
	      	
//---------------------//
void salvardados (tlivraria t[]){
	int i;
	FILE *arq;
	arq=fopen("livros.txt","w");
	fprintf(arq,"%d\n",qtd);
	for(i=0;i<qtd;i++){
		fprintf(arq,"%s\n",t[i].nome);
		fprintf(arq,"%s\n",t[i].autor);
		fprintf(arq,"%d\n",t[i].ano);
		fprintf(arq,"%d\n",t[i].prateleira);
	}
	printf("Dados  salvos com sucesso \n");
	
}
//---------------------//
void carregadados(tlivraria t[]){
	FILE *arq;
	int i;
	arq= fopen ("livros.txt","r");
	if(arq==NULL){
		printf("arquivo nao encontrado \n");
		return;
				  }//fim if
	
	fscanf(arq,"%d",&qtd);
	for (i=0;i<qtd;i++){
		fgets(arq,"%s",&t[i].nome);
		fscanf(arq,"%s",&t[i].autor);
		fscanf(arq,"%d",&t[i].ano);
		fscanf(arq,"%d",&t[i].prateleira);
	}
	fclose(arq);
	printf("Dados carregados com sucesso\n");
	
}
//---------------------//
int menu(){
	int op;
	printf("*** SISTEMA DE CADASTRO DE LIVROS  ***\n");
	printf("1-Inserir novo livro\n");
	printf("2-Mostrar todos os livros\n");
	printf("3-buscar por nome:\n");
	printf("0-Para sair");
	scanf("%d",&op);
	return op;
}

//---------------------//
int main(){
	tlivraria livraria [MAX];
	char nomebusca[30];
	int op;
	carregadados(livraria);
	do{
	op = menu();

switch(op){
	case 1: addlivraria(livraria);
	break;
	case 2: mostralivraria(livraria);
	break;
	case 3: printf("Nome do livro para buscar:");
      			fflush(stdin); gets(nomebusca);
      			buscalivro(livraria, nomebusca);
      	break;		
	case 0: salvardados(livraria);
			printf("Saindo...\n");
	break;
}
	getch();//espera digitar uma teclinha
	system("cls");
}while(op!=0);
return 0;
}
	
	
	

