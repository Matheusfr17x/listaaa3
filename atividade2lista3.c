#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct livraria{
	char nome[40];
	char autor[40];
	int prateleira;
	int ano;
}tlivraria;
int qtd=0;
//---------------------------
int addlivraria(tlivraria b[]){
	if(qtd==MAX)
	   return 0;
	printf("***** Dados para os livros cadastrados %d *****\n",qtd+1);
	fflush(stdin);
	printf("Nome:");
	gets(b[qtd].nome);
	fflush(stdin);
	printf("autor:");
	gets(b[qtd].autor);
	printf("prateleira:");
	scanf("%d",&b[qtd].prateleira);
	printf("ano:");
	scanf("%d",&b[qtd].ano);
	qtd++;
	return 1;
} 
//---------------------------
void mostralivraria(tlivraria b[]){
	int i;
	for(i=0;i<qtd;i++){
		printf("\n----------- livro %d ---------\n",i+1);
		printf("Nome:%s\nautor:%s\nprateleira:%d\nano:%d\n",
		       b[i].nome, b[i].autor,b[i].prateleira, b[i].ano);
		printf("-------------------------------\n");
	}// fim for
}
//--------------------------
void buscalivraria(tlivraria b[], char nomeBusca[]){
	int i, encontrou=0;
	char nomelivraria[40];
	for(i=0;i<qtd;i++){
		strcpy(nomelivraria, b[i].nome);
		if(strcmp(strupr(nomelivraria) , strupr(nomeBusca) )==0){ // iguais
		printf("\n----------- livro %d ---------\n",i+1);
		printf("Nome:%s\nprateleira:%d\n",
		       b[i].nome,b[i].prateleira);
		printf("-------------------------------\n");
		encontrou=1;
		break; // para o laço de repetição
	   }
	}// fim for
	if(!encontrou) // se nao encontrou
	   printf("livro nao encontrado :(");
}
//--------------------------
void buscaano(tlivraria b[], int ano){
	int i, cont=0;
	for(i=0; i<qtd; i++){
		if(b[i].ano > ano){
			printf("Nome:%s\nautor:%s\nprateleira:%d\nano:%d\n",
		     b[i].nome, b[i].autor,b[i].prateleira, b[i].ano);
		printf("-------------------------------\n");
		cont++;
		}
	}// fim for
	printf("Existem %d livros(s) mais atuais \n",cont);
}
//---------------------------
void salvarDados(tlivraria b[]){
	int i;
	FILE *arq;
	arq = fopen("livraria.txt","w"); // w = write
	fprintf(arq,"%d\n",qtd); // qtd é variável global da qtde de livraria cadastradas
	for(i=0;i<qtd;i++){
		fprintf(arq,"%s\n",b[i].nome);
		fprintf(arq,"%s\n",b[i].autor);
		fprintf(arq,"%d\n",b[i].prateleira);
		fprintf(arq,"%d\n",b[i].ano);
	}
	printf("Dados salvos com sucesso :)\n");
}
//--------------------------
void carregaDados(tlivraria b[]){
	FILE *arq;
	int i;
	arq = fopen("livraria.txt","r"); // r = leitura
	if(arq==NULL){
		printf("Arquivo nao foi encontrado :(\n");
		return;
	}// fim if
	fscanf(arq,"%d",&qtd);
	for(i=0;i<qtd;i++){
		fscanf(arq,"%s",&b[i].nome);
		fscanf(arq,"%s",&b[i].autor);
		fscanf(arq,"%d",&b[i].prateleira);
		fscanf(arq,"%d",&b[i].ano);
	}// fim for
	fclose(arq);
	printf("Dados carregados com sucesso :)\n");
}
//--------------------------
void salvaArquivoBinario(tlivraria livraria[]){
	FILE *arq;
	arq=fopen("dadosBinario.txt","wb");
	fwrite(&livraria[0],sizeof(tlivraria),qtd,arq);
	printf("Dados salvos com sucesso - binario\n");
	fclose(arq);
}
//-----------------------------
void carregaBinario(tlivraria livraria[]){
	FILE *arq;
	arq=fopen("dadosBinario.txt","rb");
	if(arq==NULL){
	  printf("Arquivo nao encontrado :(\n");
	  return;
	  }// fim if
	 while(fread(&livraria[qtd],sizeof(tlivraria),1,arq) >0  )
	      qtd++;  
	 printf("Dados carregados com sucesso - binario !\n");
	fclose(arq);
}
//-----------------------------------------
int menu(){
	int op;
	printf("*** sistema de cadastro dos livros ****\n");
	printf("1-Inserir novo livro\n");
	printf("2-Mostrar todos os livros\n");
	printf("3-Buscar livros por nome\n");
	printf("4-buscar livros mais recentes que o ano mencionado\n");
	printf("0-Sair\n");
	scanf("%d",&op);
	return op;
}
//---------------------------
int main(){
	tlivraria livraria[MAX];
	char nomeBusca[40];
	int op, ano;
	carregaBinario(livraria);
    do{
      op = menu();	
      switch(op){
      	case 1: addlivraria(livraria);
      	break;
      	case 2: mostralivraria(livraria);
      	break;
      	case 3: printf("Nome do livro para buscar:");
      			fflush(stdin); gets(nomeBusca);
      			buscalivraria(livraria, nomeBusca);
      	break;		
      	case 4: printf("ano para busca:");
      			scanf("%d",&ano);
      			buscaano(livraria, ano);
      			
      	break;
      	case 0: salvaArquivoBinario(livraria);
		  		printf("Saindo... \n");
      	break;
	  }
      	getch(); // pausa na tela - espera digitar uma tecla
      	system("cls");
	}while(op!=0);
	return 0;
}


