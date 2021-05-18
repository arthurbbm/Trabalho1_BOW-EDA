// -------------------------------------------------------------------------------------
//                              Trabalho 2 - ARVORE BINARIA DE PESQUISA ABP
//
// 	Professor : 
// 	Alunos    : Flavio Vieira Leao /  
// 	Matriculas: 15/0125682         /  
// 
// --------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  "abp.h"

//------------------------------- Prototipos --------------------------------------------

void menu          (void);
char leValidaOpcao (void);
void gerarABP      (void);
void imprimir      (void);	
void sair          (void);
void limpar_raiz   (void);	
// ---------------------------------------------------------------------------------------

int main(int argc, char**argv)
{
	char opcao;
	raiz = NULL;
	do
	{
		menu ();
		opcao =  leValidaOpcao ();
		switch (opcao)
		{
			case '1': gerarABP   ();  break;
			case '2': imprimir   ();  break;
			case '3': limpar_raiz();  break;
			case '4': sair       ();  break;

		}
	} while (opcao != '4');
	
	return 0;
}
// ---------------------------------------------------------------------------------------------------------------------------------------
void menu (void)
{
    system("tput reset");  // limpar tela linux
	//system ("cls");      // limpar tela windows

	puts ("\n===============================================================================");
	puts ("\t\tTRABALHO PRATICO 2 - ARVORE BINARIA DE PESQUISA");
	puts ("===============================================================================\n\n");
	puts ("\t +-------------------------------------+");
	puts ("\t |                                     |");
	puts ("\t | --> Escolha uma das opcoes abaixo   |");
	puts ("\t |                                     |");
	puts ("\t +-------------------------------------+");
	puts ("\t |                                     |");
	puts ("\t |  1. Gerar arvore binaria ABP        |");
	puts ("\t |  2. Imprimir arvore binaria ABP     |");
	puts ("\t |  3. Limpar arvore binaria ABP       |");
	puts ("\t |  4. Sair e desalocar                |");
	puts ("\t |                                     |");
    puts ("\t +-------------------------------------+");

}
// ---------------------------------------------------------------------------------------------------------------------------------------
char leValidaOpcao (void)
{
	char op, controle;
	do
	{
		printf ("\n\tSelecione uma opcao [1-4]: _\b");
		op = getchar(); 
		getchar();

		if (op <'0' || op > '4')
		{
			printf ("\t ** Opcao invalida! **");
			getchar();
		}
		else
			if (op == '4')
			{
                puts ("\n\n===============================================================================\n");
				printf("\tDeseja realmente sair? \n\t[S] -> Sim - [Outra tecla] -> Retornar: _\b");
				controle = getchar();
				getchar();
			
				if (controle == 's' | controle == 'S')
                {
                    sair();
                    return op;
                }
				else
					return -1;
	     	}
			else
				return op;
	} while (1);

}
// ---------------------------------------------------------------------------------------------------------------------------------------
void gerarABP(void)
{
    system("tput reset");
	//system ("cls");

	puts ("\n===============================================================================");
	puts("\n\t==>>  Gerar Arvore Binaria de Pesquisa\n");
   
    int n;
  	n = create_tree();

	
	puts ("\n\n\n ** Arvore gerada com sucesso!!\n");
	puts ("------------> Pressione uma tecla para voltar ao menu inicial");
	puts ("===============================================================================");
	getchar();
}
// ---------------------------------------------------------------------------------------------------------------------------------------
void imprimir(void)
{
    system("tput reset");
	//system ("cls");
	puts ("\n===============================================================================");
	puts("\n\t==>>  Impressao Arvore Binaria ABP\n");
	
	if(raiz == NULL)
		printf("Arvore vazia.\n");
	else
		print_inorder(raiz);	

	puts ("\n\n\n------------> Pressione uma tecla para voltar");
	puts ("===============================================================================");
	getchar();
}
// ---------------------------------------------------------------------------------------------------------------------------------------
void sair(void)
{
    system("tput reset");
	//system ("cls");

	if(raiz)
	{
		printf("Liberando Memoria alocada!\n");
		limpar_raiz();

	}

    puts ("\n===============================================================================");
	puts("\n\t==>>  Saindo.....\n");
	

	puts ("\n\n\n------------> Finalizando programa.........");
	puts ("===============================================================================");
	getchar();
}
//---------------------------------------------------------------------------------------------------------------------------------------
void limpar_raiz ()
{
	clear_tree(raiz);
	raiz = NULL;
}
