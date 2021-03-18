# include <stdio.h>
# include <stdlib.h>
# include "functions.h"

void menu(void)//O(1)
{
    //system("tput reset");//O(1)
	system ("cls");//O(1)

	puts ("\n========================================================================");//O(1)
	puts ("\t\tTRABALHO PRATICO 1 - VETORES DINAMICOS");//O(1)
	puts ("========================================================================\n\n");//O(1)
	puts ("\t +--------------------------------------------------+");//O(1)
	puts ("\t |                                                  |");//O(1)
	puts ("\t | --> Escolha uma das opcoes abaixo                |");//O(1)
	puts ("\t |                                                  |");//O(1)
	puts ("\t +--------------------------------------------------+");//O(1)
	puts ("\t |                                                  |");//O(1)
	puts ("\t |       1. Selecionar Arquivo Dicionario           |");//O(1)
	puts ("\t |       2. Selecionar Arquivo de referencia A      |");//O(1)
	puts ("\t |       3. Selecionar Arquivo de referencia B      |");//O(1)
	puts ("\t |       4. Exibir tabela                           |");//O(1)
	puts ("\t |       5. Imprimir BOW TRA e TRB                  |");//O(1)
	puts ("\t |       6. Imprimir distancia Euclidiana           |");//O(1)
	puts ("\t |       0. Sair                                    |");//O(1)
	puts ("\t |                                                  |");//O(1)
    puts ("\t +--------------------------------------------------+");//O(1)

}
//===========================================================================================================
char valida_op(void)//O(n^2)
{
	char op, controle;//O(1)
	int i = 1;//O(1)
	do//O(1)
	{
		printf("\n\tSelecione uma opcao [0-6]: _\b");//O(n)
		scanf(" %c%*[^\n]",&op);//O(n^2)
		flush_in();//O(n^2)
		if (op <'0' || op > '5')//O(n)
		{
			puts ("\t ** Opcao invalida! **");//O(n)
			getchar();//O(n)
		}
		else//O(n)
			if (op != '0') return op;//O(n)
			else//O(n)
			{
				puts ("\n\n=========================================================================\n");//O(n)
				printf("\t[S] ---> Sim - \n\t[N] ---> Retornar\n\n\t\t Deseja realmente sair: _\b");//O(n)
				scanf(" %c%*[^\n]",&controle);//O(n^2)

				if ( controle == 's' || controle == 'S')//O(n)
				   return  op;//O(n)
 			    i = 0;//O(n)
 			    puts ("\n\n------------> Pressione uma tecla para voltar ao menu inicial");//O(n)
				getchar();//O(n)
                puts ("\n\n=========================================================================\n");//O(n)

			}
	}while (i);//O(n)
}
