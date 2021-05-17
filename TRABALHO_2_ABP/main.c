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
#include  "abp.h"

//------------------------------- Prototipos --------------------------------------------

void menu          (void);
char leValidaOpcao (void);
void gerarABP      (void);
void imprimir      (void);	
void sair          (void);	
// ---------------------------------------------------------------------------------------

int main(int argc, char**argv)
{
	char opcao;
	do
	{
		menu ();
		opcao =  leValidaOpcao ();
		switch (opcao)
		{
			case '1': gerarABP  ();	break;
			case '2': imprimir  ();	break;
			case '3': sair      (); break;
		}
	} while (opcao != '3');
	
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
	puts ("\t |  3. Sair e desalocar                |");
	puts ("\t |                                     |");
    puts ("\t +-------------------------------------+");

}
// ---------------------------------------------------------------------------------------------------------------------------------------
char leValidaOpcao (void)
{
	char op, controle;
	do
	{
		printf ("\n\tSelecione uma opcao [1-3]: _\b");
		op = getchar(); 
		getchar();

		if (op <'0' || op > '3')
		{
			printf ("\t ** Opcao invalida! **");
			getchar();
		}
		else
			if (op == '3')
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
    printf("Nos arvore = %d", n);


	
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

	// fatBal(raiz);
	
	if (0)
		puts (" Fila Vazia !");
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

    puts ("\n===============================================================================");
	puts("\n\t==>>  Saindo.....\n");
	

	puts ("\n\n\n------------> Finalizando programa.........");
	puts ("===============================================================================");
	getchar();
}



