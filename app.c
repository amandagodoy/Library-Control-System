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
    int codigo;
    char nome[30];
    //char endereco[50];
    //char cpf[15];
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
