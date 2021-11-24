#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define tamLei 200
#define tamLivro 200
#define arquivoLeitor "leitores.dat"
#define arquivoLivros "livro.dat"
#define arqLista
typedef struct
{
    int dia;
	int mes;
	int ano;

}dt;

typedef struct
{
    //int codigo;
    char nome[30];
    //char endereco[50];
    char cpf[15];
    //char nomeContato[30];
    //int telefoneContato;
    //int telefone;
}leitor;

typedef struct
{
    int codigo;
    char titulo[30];
    char genero[10];
    //char duracao[10];
    dt data_lanc;
}livro;

void cadastraLeitor(void);
void cadastraLivro(void);
void consultaLeitor(void);
void consultaLeitorNome(void);
void consultaLeitorCPF(void);
void consultaLivros(void);
void consultaLivroCodigo(void);
void consultaLivroTitulo(void);
int main(){
    int op;
	do {
		printf("\n\n\t-------------------------------\n");
		printf("\t   Escolha uma das opcoes      \n");
		printf("\t-------------------------------\n");
		printf("\n\t1- Cadastrar Leitor\n");
		printf("\n\t2- Cadastrar Livros\n");
		printf("\n\t3- Mostrar todos os Leitores Cadastrados\n");
        printf("\n\t4- Consultar Leitores por Nome\n");
		printf("\n\t5- Consultar Leitores por CPF\n");
		printf("\n\t6- Mostrar todos os Livros Cadastrados\n");
		printf("\n\t7- Consultar Livros por Codigos\n");
		printf("\n\t8- Consultar Livros por Titulo\n");
		printf("\n\t0- Sair do programa\n\n");
		printf("\tEscola uma Opcao: ");
		scanf("%d", &op);
		switch(op){
		    case 1:
				system ("cls");
			 	cadastraLeitor();
		        break;
		    case 2:
			 	system ("cls");
			 	cadastraLivro();
		        break;
		    case 3:
				system ("cls");
				consultaLeitor();
		        break;
		    case 4:
			    system ("cls");
				consultaLeitorNome();
		        break;
		    case 5:
			    system ("cls");
				consultaLeitorCPF();
		        break;
		    case 6:
			    system ("cls");
				consultaLivros();
		        break;
		    case 7:
			    system ("cls");
				consultaLivroCodigo();
		        break;
		    case 8:
			    system ("cls");
				consultaLivroTitulo();
		        break;
		    case 0:
				system ("cls");
			    break;
			default:
			    printf("\n\tOpcao invalida!\n\n");
			    system("pause");
                break;
        }
	}while(op != 0);
	return 0;
}

void cadastraLeitor(void){

	FILE * arq;
	leitor x;
    char aux[15];
    char aux2[15];
    char cpf[15];
    int i=0,j=0;
    int a = 0, num=0;
    do{
		do{
		   printf("\n\n\t     Cadastro de Novo Leitor\n\n");
		   if ((arq = fopen(arquivoLeitor, "a+b")) == NULL) {
				fprintf(stderr, "\n\tImpossivel abrir o arquivo %s!\n", arquivoLeitor);
		   }
		   fseek(arq, 0, SEEK_SET);
		   a=0;
		   printf("\nCPF: ");
		   fflush(stdin);
		   gets(cpf);
		   while(fread(&x, sizeof(leitor), 1, arq) > 0) {
				if(strncmp(cpf,x.cpf, strlen(cpf)) == 0){
			  		a=a+1;
		    	}
	       	}
		   if(a > 0){
			  printf("\n\n\tJa existe um cliente cadastrado com esse cpf: %s\n\n",cpf);
			  printf("\n\tCPF Invalido !!!\n\n");
			}
		}while(a > 0);
	    fseek(arq, 0, SEEK_END);
		//x.codigo= ftell(arq) / sizeof(leitor) + 1;
		//printf("\tCodigo do Cliente: %d\n\n", x.codigo);
		printf("\n\nCPF: %s \n",cpf);
	    strcpy(x.cpf,cpf);

		printf("\nNome: ");
		fflush(stdin);
		gets(x.nome);

		fwrite(&x, sizeof(leitor), 1, arq);
	    system("cls");
	    printf("\n\n\tLeitor Cadastrado Com Sucesso!\n\n");
	    fclose(arq);

        printf("\n\tDeseja Cadastrar outro Leitor ?\n\n\t1 - Sim\n\n\t2 - Nao\n\n ");
 	    scanf("%d", &num);
		while(num < 0 || num > 2){
			system ("cls");
			printf("\n\tOpcao Invalida!!\n\n");
            printf("\n\tDeseja Cadastrar outro Leitor ?\n\n");
            printf("\n\tDigite novamente:\n\n\n\t\t1 - Sim\n\n\t\t2 - Nao\n");
  		    scanf("%d", &num);
			system("cls");
	    }
	}while(num==1);
}

void cadastraLivro(void){
	FILE * arq;
	livro x;
	int num=0;
	do{

		printf("\n\n\t     Cadastro de novo Livro \n\n");
		if ((arq = fopen(arquivoLivros, "ab")) == NULL) {
			fprintf(stderr, "\n\tImpossivel abrir o arquivo %s!\n", arquivoLivros);
		}
		fseek(arq, 0, SEEK_END);

		x.codigo = ftell(arq) / sizeof(livro) + 1;

	    system("cls");
	    printf("Cadastro de Livros\n\n");

	    printf("Codigo: %d\n\n", x.codigo);
	    printf("\nTitulo: ");
	    fflush(stdin);
		gets(x.titulo);
	    printf("\nGenero: ");
	    gets(x.genero);
	 	printf("\nData do Lancamento (ddmmaaaa): ");
		scanf("%02d %02d %4d", &x.data_lanc.dia, &x.data_lanc.mes, &x.data_lanc.ano);

		fwrite(&x, sizeof(livro), 1, arq);
    	system("cls");
		printf("\n\n\tLivro Cadastrado Com Sucesso!\n\n");

		fclose(arq);

		printf("\n\tDeseja Cadastrar outro Livro ?\n\n\t1- Sim\n\n\t2- Nao\n\n ");
		scanf("%d", &num);
		while(num < 0 || num > 2){
  		  	system ("cls");
			printf("\n\tOpcao Invalida!!\n\n\tDigite novamente:\n\n\t\t1-Sim\n\n\t\t2- Nao\n");
		    scanf("%d", &num);
        }
	}while(num==1);
}

void consultaClientes (void){
	system("cls");

	FILE * arq;
	FILE * arq2;
	int num=0;

	leitor l;

	if ((arq = fopen(arquivoLeitor, "rb")) == NULL) {
		fprintf(stderr, "\n\tNao existe nenhum leitor cadastrado!\n\n\n");
		printf("\n\ns");
        system("pause");
		return;
	}

	if((arq2 = fopen(arqLista"TodosLeitores.txt", "w")) == NULL) {
		fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"TodosLeitores.txt");
        printf("\n\n");
		system("pause");
		return;
	}

	printf("\n\nLeitores Cadastrados\n\n");
	printf("==========================================================================\n");
	printf("Nome\tCpf\t    \n");
	printf("==========================================================================\n\n");
	printf("--------------------------------------------------------------------------\n");
	while (fread(&l, sizeof(leitor), 1, arq) > 0) {

     	printf("%-10s %-10s \n",l.nome,l.cpf);

		printf("--------------------------------------------------------------------------\n");
	}
	fseek(arq,0,SEEK_SET);

    printf("\n\n\tDeseja gerar um relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t");
    scanf("%d", &num);
    while(num<1||num>2){
	  	system ("cls");
	    printf("\n\tOpcao Invalida!!!");
        printf("\n\n\tDeseja gerar um relatorio ?\n\n\tDigite novamente:\n\n\t\t 1- Sim \n\t\t 2- Nao\n ");
        scanf("%d", &num);
    }
    if(num==1){
    	fprintf(arq2,"\n\nLeitores Cadastrados\n\n");
		fprintf(arq2,"==========================================================================\n");
		fprintf(arq2,"Nome\tCpf\t    \n");
     	fprintf(arq2,"--------------------------------------------------------------------------\n");
      	while (fread(&l, sizeof(leitor), 1, arq) > 0) {
            fprintf(arq2,"%-10s %-10s \n",l.nome,l.cpf);
            fprintf(arq2,"--------------------------------------------------------------------------\n");
        }
	    fprintf(arq2,"==========================================================================\n");
        system ("cls");
		printf("\n\n\tRelatorio gerado com sucesso!\n\n");
   }
   else if(num==2){
		system ("cls");
		return;
   }
    system("pause");
    system("cls");
    fclose(arq);
    fclose(arq2);
}

void consultaLeitorNome(void){
	system("cls");

	FILE * arq;
	FILE * arq2;

	leitor l;
	int num=0,num2=0;
	char nome[50];
	int achei = 0;

	int i=0,j=0;

	do{
		if ((arq = fopen(arquivoLeitor, "rb")) == NULL) {
			fprintf(stderr, "\n\tNao existe nenhum leitor cadastrado!\n");
			printf("\n\n");
			system("pause");
            return;
		}
		if((arq2 = fopen(arqLista"PesquisaLeitorNome.txt", "w")) == NULL) {
			fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"PesquisaLeitorNome.txt");
			printf("\n\n");
            system("pause");
            return;
		}
		printf("\n\n\t     Pesquisa de leitor por nome\n\n");
	    do{
			printf("\tNome do leitor: ");
			scanf(" %50[^\n]", nome);
		    printf("\n\n");
			rewind(arq);
	        printf("\n\nLeitor cadastrados com esse nome:%s\n\n",nome);
	        printf("==========================================================================\n");
	        printf("Nome\tCpf\t    \n");
	        printf("==========================================================================\n\n");
	        printf("--------------------------------------------------------------------------\n");

			while(fread(&l, sizeof(leitor), 1, arq) > 0){
			  for(i=0;i< (strlen(nome));i++){
			  		nome[i]=toupper(nome[i]);
					for(j=0;j<(strlen(l.nome));j++){
			  			l.nome[j]=toupper(l.nome[j]);
			  		}
			  	}
			  	if(strncmp(nome,l.nome, strlen(nome)) == 0){
                   printf("%-10s %-10s \n",l.nome,l.cpf);
	           		printf("--------------------------------------------------------------------------\n");
					achei = 1;
			  	}
			}
	        printf("==========================================================================\n\n");
		    if (!achei){
			  	printf("\n\n\tNao existe leitor cadastrado com esse nome: %s\n\n",nome);
			  	printf("\n\tDigite Novamente !\n\n");
			}

		}while(!achei);

		fseek(arq,0,SEEK_SET);

		printf("\n\n\tDeseja Gerar Um Relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t");
		scanf("%d", &num);
		while(num<1||num>2){
           system ("cls");
		   printf("\n\tOpcao Invalida!!!\n\n");
           printf("\tDeseja Gerar Um Relatorio ?\n\n");
           printf("\tDigite novamente:\n\n\t\t 1- Sim \n\t\t 2- Nao\n");
		   scanf("%d", &num);
        }

		if(num==1){
	    	fprintf(arq2,"\n\nLeitores cadastrados com esse nome\n\n");
	        fprintf(arq2,"==========================================================================\n");
	        fprintf(arq2,"Nome\tCpf\t    \n");
	        fprintf(arq2,"==========================================================================\n\n");
	        fprintf(arq2,"--------------------------------------------------------------------------\n");

			while(fread(&l, sizeof(leitor), 1, arq) > 0){
			    for(i=0;i< (strlen(nome));i++){
			  	  	nome[i]=toupper(nome[i]);
				  	for(j=0;j<(strlen(l.nome));j++){
			  			l.nome[j]=toupper(l.nome[j]);
			  	  	}
		        }
			  	if(strncmp(nome,l.nome, strlen(nome)) == 0){
				    fprintf(arq2,"%-10s %-12d \n",l.nome,l.cpf);
                	fprintf(arq2,"--------------------------------------------------------------------------\n");
				    achei = 1;
				}
			}
	        fprintf(arq2,"==========================================================================\n\n");

			system ("cls");
			printf("\n\n\tRelatorio gerado com sucesso!!\n\n");
   			system("pause");
		}

	    system("cls");
	    fclose(arq);
	    fclose(arq2);

		printf("\n\tDeseja Realizar Outra Pesquisa ?\n\n\t1- Sim\n\n\t2- Nao\n\n ");
		scanf("%d", &num2);
		while(num2 < 0 || num2 > 2){
			system ("cls");
		    printf("\n\tOpcao Invalida!!!\n\n");
            printf("\tDeseja Realizar Outra Pesquisa ?\n\n");
            printf("\tDigite novamente:\n\n\t\t 1-Sim \n\t\t 2- Nao).\n");
      		scanf("%d", &num2);
		}
		system("cls");
	}while(num2==1);
}

void consultaLeitorCPF(void){
	system("cls");

	FILE * arq;
	FILE * arq2;

	leitor l;
	int num=0,num2=0;
	char cpf[15];
	int achei = 0;
	int i=0,j=0;

	do{
		if ((arq = fopen(arquivoLeitor, "rb")) == NULL){
			fprintf(stderr, "\n\tErro: Nao existe nenhum leitor cadastrado!\n");
		    printf("\n\n");
        	system("pause");
            return;
		}
		if((arq2 = fopen(arqLista"PesquisaLeitorCPF.txt", "w")) == NULL){
			fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"PesquisaLeitorCPF.txt");
			printf("\n\n");
            system("pause");
    		return;
		}
		printf("\n\n\t   Consultar Leitor por cpf    \n\n");
	 do{
		printf("\tCPF do Leitor: ");
		fflush(stdin);
			gets(cpf);
		    printf("\n\n");

			rewind(arq);

			printf("\n\n\t\tLeitor com esse cpf: %s\n\n",cpf);
	        printf("==========================================================================\n");
	        printf("Nome\tCpf\t    \n");
	        printf("==========================================================================\n\n");
	        printf("--------------------------------------------------------------------------\n");

			while(fread(&l, sizeof(leitor), 1, arq) > 0)
            {
			  for(i=0;i< (strlen(cpf));i++)
              {
			  	cpf[i]=toupper(cpf[i]);
				  for(j=0;j<(strlen(l.cpf));j++)
                  {
			  		l.cpf[j]=toupper(l.cpf[j]);
			  	  }
			  }
			  if(strncmp(cpf,l.cpf, strlen(cpf)) == 0)
              {
                printf("%-10s %-10s \n",l.nome,l.cpf);
                printf("--------------------------------------------------------------------------\n");
				achei = 1;
 			  }
			}
	        printf("==========================================================================\n");

		    if (!achei){
			  printf("\n\n\tNao existe leitor cadastrado com  esse CPF: %s\n\n",cpf);
			  printf("\n\tDigite Novamente !\n\n");
			}

		}while(!achei);

		fseek(arq,0,SEEK_SET);

	    printf("\n\n\tDeseja Gerar Um Relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t ");
		scanf("%d", &num);
		while(num<1||num>2)
        {
           	system ("cls");
			printf("\n\tOpcao Invalida!!!\n\n");
            printf("\tDeseja Gerar Um Relatorio ?\n\n");
            printf("\tDigite novamente:\n\n\t\t 1- Sim\n\n\t\t 2- Nao\n");
		    scanf("%d", &num);
        }
		if(num==1)
        {
			   fprintf(arq2,"\n\n\t\t\t\t\tLeitor com esse CPF: %s\n\n",cpf);
	           fprintf(arq2,"================================================================================\n");
	           fprintf(arq2,"Nome\tCpf\t    \n");
	           fprintf(arq2,"================================================================================\n\n");
	           fprintf(arq2,"--------------------------------------------------------------------------------\n");
			while(fread(&l, sizeof(leitor), 1, arq) > 0)
            {
			  for(i=0;i< (strlen(cpf));i++)
              {
			  	cpf[i]=toupper(cpf[i]);
			    for(j=0;j<(strlen(l.cpf));j++)
                {
			  		l.cpf[j]=toupper(l.cpf[j]);
			  	}
			  }
			  if(strncmp(cpf,l.cpf, strlen(cpf)) == 0)
              {
 			    fprintf(arq2," %-20s %-15s  \n",l.nome,l.cpf);
	            fprintf(arq2,"--------------------------------------------------------------------------------\n");
				achei = 1;
			  }
			}
            fprintf(arq2,"================================================================================\n\n");
		 	system ("cls");
			printf("\n\n\tRelatorio gerado com sucesso!!\n\n");
			system("pause");
		}
	    system("cls");
	    fclose(arq);
	    fclose(arq2);

		printf("\n\tDeseja Realizar Outra Pesquisa ?\n\n\t1- Sim\n\n\t2- Nao\n\n ");
		scanf("%d", &num2);
		while(num2 < 0 || num2 > 2)
        {
			system ("cls");
			printf("\n\tOpcao Invalida!!!\n\n\tDigite novamente:\n\n\t\t 1-Sim \n\t\t 2- Nao).\n");
		    scanf("%d", &num2);
		}
  		system("cls");
	}while(num2==1);
}
