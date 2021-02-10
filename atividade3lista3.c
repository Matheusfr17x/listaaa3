#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 100

typedef struct matricula{
	int nmatricula;
	char nome[40];
	float nota1;
	float nota2;
	float nota3;
}tmatricula;
int qtd=0;
//---------------------------
int addmatricula(tmatricula b[]){
	if(qtd==MAX)
	   return 0;
	printf("***** Dados para as matriculas %d *****\n",qtd+1);
	fflush(stdin);
	printf("matricula:");
	scanf("%d",&b[qtd].nmatricula);
	fflush(stdin);
	printf("nome:");
	gets(b[qtd].nome);
	printf("nota prova 1:");
	scanf("%f",&b[qtd].nota1);
	printf("nota prova 2:");
	scanf("%f",&b[qtd].nota2);
	printf("nota prova 3:");
	scanf("%f",&b[qtd].nota3);
	qtd++;
	return 1;
} 
//---------------------------
void mostramatricula(tmatricula b[]){
	int i;

	for(i=0;i<qtd;i++){
		printf("\n----------- matricula %d ---------\n",i+1);
		printf("matricula:%d\nnome:%s\nnota da prova 1:%f\nnota da prova 2:%f\nnota da prova 3:%f\n",
		       b[i].nmatricula, b[i].nome, b[i].nota1, b[i].nota2, b[i].nota3);
		       	float media=(b[i].nota1+b[i].nota2+b[i].nota3)/3;
		       if (media>=6){
		       	printf("O aluno foi aprovado\n");
			   }
			   else
			   printf("o aluno foi reprovado\n");
		       
		       
		printf("-------------------------------\n");
	}// fim for
}
//--------------------------
void buscanome(tmatricula b[], char nomeBusca[]){
	int i, encontrou=0;
	char nomematricula[40];
	for(i=0;i<qtd;i++){
		strcpy(nomematricula, b[i].nome);
		if(strcmp(strupr(nomematricula) , strupr(nomeBusca) )==0){ // iguais
			printf("\n----------- matricula %d ---------\n",i+1);
			printf("matricula:%d\nnome:%s\nnota da prova 1:%f\nnota da prova 2:%f\nnota da prova 3:%f\n",
		       b[i].nmatricula, b[i].nome, b[i].nota1, b[i].nota2, b[i].nota3);
			printf("-------------------------------\n");
		encontrou=1;
		break; // para o laço de repetição
	   }
	}// fim for
	if(!encontrou) // se nao encontrou
	   printf("aluno nao encontrado :(");
}
//--------------------------
void buscamatricula(tmatricula b[], int nmatricula){
	int i, cont=0;
	int numero;
	for(i=0; i<qtd; i++){

	
		if(numero+1==b[i].nmatricula){
		printf("matricula:%d\nnome:%s\nnota da prova 1:%f\nnota da prova 2:%f\nnota da prova 3:%f\n",
		       b[i].nmatricula, b[i].nome, b[i].nota1, b[i].nota2, b[i].nota3);
			printf("-------------------------------\n");
		cont++;
		}
	}// fim for
}

//---------------------------
void salvardadostxt(tmatricula b[]){
	int i;
	FILE *arq;
	arq = fopen("matricula.txt","w"); // w = write
	fprintf(arq,"%d\n",qtd); // qtd é variável global da qtde de livraria cadastradas
	for(i=0;i<qtd;i++){
		fprintf(arq,"%d\n",b[i].nmatricula);
		fprintf(arq,"%s\n",b[i].nome);
		fprintf(arq,"%f\n",b[i].nota1);
		fprintf(arq,"%f\n",b[i].nota2);
		fprintf(arq,"%f\n",b[i].nota3);
	}
	printf("Dados salvos em texto com sucesso :)\n");
}
//--------------------------
void carregaDados(tmatricula b[]){
	FILE *arq;
	int i;
	arq = fopen("matricula.txt","r"); // r = leitura
	if(arq==NULL){
		printf("Arquivo nao foi encontrado :(\n");
		return;
	}// fim if
	fscanf(arq,"%d",&qtd);
	for(i=0;i<qtd;i++){
			fprintf(arq,"%d\n",b[i].nmatricula);
		fprintf(arq,"%s\n",b[i].nome);
		fprintf(arq,"%f\n",b[i].nota1);
		fprintf(arq,"%f\n",b[i].nota2);
		fprintf(arq,"%f\n",b[i].nota3);
	}// fim for
	fclose(arq);
	printf("Dados carregados com sucesso :)\n");
}
//--------------------------
void salvaArquivoBinario(tmatricula matricula[]){
	FILE *arq;
	arq=fopen("dadosBinariomatricula.txt","wb");
	fwrite(&matricula[0],sizeof(tmatricula),qtd,arq);
	printf("Dados salvos com sucesso - binario\n");
	fclose(arq);
}
//-----------------------------
void carregaBinario(tmatricula matricula[]){
	FILE *arq;
	arq=fopen("dadosBinariomatricula.txt","rb");
	if(arq==NULL){
	  printf("Arquivo nao encontrado :(\n");
	  return;
	  }// fim if
	 while(fread(&matricula[qtd],sizeof(tmatricula),1,arq) >0  )
	      qtd++;  
	 printf("Dados carregados com sucesso - binario !\n");
	fclose(arq);
}
//----------------------------------------
void maiormedia(tmatricula b[]){
double maior = (b[0].nota1+b[0].nota2+b[0].nota3)/3; 
int i;
double media;
for(i=0; i<qtd; i++){
	
				 media=(b[i].nota1+b[i].nota2+b[i].nota3)/3;
				 
				  if(media > maior){
				  	maior = media;
				  }
							}
			
			
			printf("a maior media e %f",maior);
			}
//-----------------------------------------
int menu(){
	int op;
	printf("*** sistema de cadastro dos alunos ****\n");
	printf("1-Inserir novo aluno\n");
	printf("2-Mostrar todos os alunos\n");
	printf("3-Buscar alunos por nome\n");
	printf("4-buscar por numero de matricula\n");
	printf("5-salvar arquivo como binario\n");
	printf("6-salvar arquivo como txt\n");
	printf("7-para descobrir a maior media\n");
	printf("0-para sair e salvar binario\n");
	scanf("%d",&op);
	return op;
}
//---------------------------
int main(){
	tmatricula matricula[MAX];
	char nomeBusca[40];
	double nota1,nota2,nota3;
	int op, numero;
	carregaBinario(matricula);
    do{
      op = menu();	
      switch(op){
      	case 1: addmatricula(matricula);
      	break;
      	case 2: mostramatricula(matricula);
      	break;
      	case 3: printf("Nome do aluno para buscar:");
      			fflush(stdin); gets(nomeBusca);
      			buscanome(matricula, nomeBusca);
      	break;		
      case 4: printf("matricula para busca:");
      			scanf("%d",&numero);
      			buscamatricula(matricula, numero);
      			
      	break;
      	case 5: salvaArquivoBinario(matricula);
		  		printf("arquivo salvo como binario! \n");
      	break;
      	
      	case 6: salvardadostxt(matricula);
		  		printf("arquivo salvo como txt!\n");
		break;
			case 7: printf("maior media:\n");
      		
      			maiormedia(matricula);
		
		break;
      	case 0: salvaArquivoBinario(matricula);
		  		printf("Saindo... \n");
      	break;
	  }
      	getch(); // pausa na tela - espera digitar uma tecla
      	system("cls");
	}while(op!=0);
	return 0;
}
