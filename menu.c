# include <stdio.h>
# include <stdlib.h>

void menu(void)
{
    //system("tput reset");
	system ("cls");   // limpar tela windows

	puts ("\n========================================================================");
	puts ("\t\tTRABALHO PRATICO 1 - VETORES DINAMICOS");
	puts ("========================================================================\n\n");
	puts ("\t +--------------------------------------------------+");
	puts ("\t |                                                  |");
	puts ("\t | --> Escolha uma das opcoes abaixo                |");
	puts ("\t |                                                  |");
	puts ("\t +--------------------------------------------------+");
	puts ("\t |                                                  |");
	puts ("\t |       1. Selecionar Arquivo Dicionario           |");
	puts ("\t |       2. Selecionar Arquivo de referencia A      |");
	puts ("\t |       3. Selecionar Arquivo de referencia B      |");
	puts ("\t |       4. Imprimir BOW TRA e TRB                  |");
	puts ("\t |       5. Imprimir distancia Euclidiana           |");
	puts ("\t |       0. Sair                                    |");
	puts ("\t |                                                  |");
    puts ("\t +--------------------------------------------------+");

}
//===========================================================================================================
char valida_op(void)
{
	char op, controle;
	int i = 1;
	do
	{
		printf("\n\tSelecione uma opcao [0-5]: _\b");
		scanf(" %c%*[^\n]",&op);
		flush_in();
		if (op <'0' || op > '5')
		{
			puts ("\t ** Opcao invalida! **");
			getchar();
		}
		else
			if (op != '0') return op;
			else                             // op = 0  -> Sair)
			{
				puts ("\n\n=========================================================================\n");
				printf("\t[S] ---> Sim - \n\t[N] ---> Retornar\n\n\t\t Deseja realmente sair: _\b");
				scanf(" %c%*[^\n]",&controle);

				if ( controle == 's' || controle == 'S')
				   return  op;
 			    i = 0;
 			    puts ("\n\n------------> Pressione uma tecla para voltar ao menu inicial");
				getchar();
                puts ("\n\n=========================================================================\n");

			}
	}while (i);
}
