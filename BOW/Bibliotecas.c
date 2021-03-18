#include "includes.h"

//================================= Sub Programas ===========================================================
void selecionar_dicionario(char *arq_dic, int *qtde_dic, int **p_contA, int **p_contB)
{
	char buff[MAX_LINE];
	int cont = 0;;

	printf("\n\tSelecionar Arquivo de Dicionario: ");
	fgets (arq_dic, MAX_WORD, stdin);
	valida_string(arq_dic);                                     //retira o /n e validacao nome vazio.
	
	FILE *p_file = abrir_arquivo(arq_dic, 'r');

	printf("\n_____________________________________________________\n\n");
	while(!feof(p_file))
	{	
		if(fgets(buff, MAX_LINE, p_file));  
			printf("\t%d: %s",cont + 1 ,buff);
		cont++;
	}
	// printf("\nCont = %d", cont);
	printf("\n_____________________________________________________\n");
	printf ("\n---> Arquivo selecionado com sucesso, aperte qualquer tecla para voltar..");
	getchar();
	
	*qtde_dic = cont;
	*p_contA = (int *) malloc(sizeof(int)* cont);
	*p_contB = (int *) malloc(sizeof(int)* cont);

	fclose(p_file);
}
//===========================================================================================================
void selecionar_tra(char *arq_dic, char *arq_tra, int *contA)
{
	printf("\n\tSelecionar Arquivo de Referencia A (TRA): ");
	fgets (arq_tra, MAX_WORD, stdin);
	valida_string(arq_tra);

	printf("\tnome trA: %s\n", arq_tra);

	FILE *p_tra  = abrir_arquivo(arq_tra, 'r');
	FILE *p_dic = abrir_arquivo(arq_dic, 'r');
	FILE *p_bow = abrir_arquivo("bowA.txt", 'w');
	
	exportar_bow(p_tra, p_dic, p_bow, contA);;

	fclose(p_tra);
	fclose(p_dic);
	fclose(p_bow);

	printf("\n_____________________________________________________\n");
	printf ("\n---> Arquivo selecionado com sucesso, aperte qualquer tecla para voltar..");
	getchar();
}
//===========================================================================================================
void selecionar_trb(char *arq_dic, char *arq_trb, int *contB)
{
	printf("\n\tSelecionar Arquivo de Referencia B (TRB): ");
	fgets (arq_trb, MAX_WORD, stdin);
	valida_string(arq_trb);

	// printf("nome dicionario: %s\n", arq_dic);
	printf("\tnome trB: %s\n", arq_trb);

	// getchar();

	FILE *p_trb = abrir_arquivo(arq_trb, 'r');
	FILE *p_dic = abrir_arquivo(arq_dic, 'r');
	FILE *p_bow = abrir_arquivo("bowB.txt", 'w');
	
	// printf("Antes de entrar na exportar bow\n");
	// getchar();
	exportar_bow(p_trb, p_dic, p_bow, contB);

	fclose(p_trb);
	fclose(p_dic);
	fclose(p_bow);

	printf("\n_____________________________________________________\n");
	printf ("\n---> Arquivo selecionado com sucesso, aperte qualquer tecla para voltar..");
	getchar();
}
//===========================================================================================================
void exibir_bow_tr(int qtde_dic)
{
	char op, controle;
	char nome_arquivo[MAX_WORD];
	
	do
	{
		system("tput reset");
		puts ("\n================================================================================================");
		// display2();
		puts ("================================================================================================");
		puts("\n\t==>>  Listar arquivos\n\n");

		puts ("\t	1. Exibir bowA.txt");
		puts ("\t	2. Exibir bowB.txt");
		puts ("\t	3. Exibir tra.txt");
		puts ("\t	4. Exibir trb.txt");
		puts ("\t	5. Exibir Dicionario");
		puts ("\t	6. contA");
		puts ("\t	7. contB");
		puts ("\t	0. voltar menu inicial");

		printf("\n\tSelecione uma opcao [0-7]: _\b");
		scanf(" %c%*[^\n]",&op); 
		
		switch (op)
		{
			case '1':	
				strcpy (nome_arquivo, "bowA.txt");
				break;

			case '2': 
				strcpy (nome_arquivo, "bowB.txt");
				break;				
			
			case '3': 
				strcpy (nome_arquivo, "tra.txt");
				break;				
			
			case '4': 
				strcpy (nome_arquivo, "trb.txt");
				break;				
			
			case '5': 
				strcpy (nome_arquivo, "dic1.txt");
				break;
			
			case '6': 
				break;

			case '7': 
				break;
			
			default :
    			printf ("Valor invalido!\n");

		}
		flush_in();
		FILE *p_file = abrir_arquivo(nome_arquivo, 'r');
		char buff[MAX_LINE];
		
		system("tput reset");
		printf("\n==================================================\n");
		printf("\n\t==>>  %s\n\n", nome_arquivo);
		while(!feof(p_file))
		{	
			if(fgets(buff, MAX_LINE, p_file));  
				printf("\t%s",buff);
		}
		printf("\n==================================================\n");
		puts ("\n------- Pressione uma tecla para voltar ao menu");
		getchar();
	
	} while (op != '0');
	puts ("\n\n-------> Pressione uma tecla para voltar ao menu inicial");
	puts ("================================================================================================");
	getchar();
}
//===========================================================================================================
void dist_euclid(int contA[], int contB[], int qtde_dic)
{
	int i;	
   float gdistance=0;
   float sum = 0;
   double euc;

	system("tput reset");
	printf("\n==================================================\n");
	printf("\n\t==>>  Vetores BOW\n\n");

	printf("contA = {");
	for( i = 0; i < qtde_dic; i++)
		printf(" %d, ",contA[i]);
	printf("}\n");

	printf("contB = {");;
	for( i = 0; i < qtde_dic; i++)
		printf(" %d, ",contB[i]);
	printf("}\n");


   	for (i = 0; i < qtde_dic; ++i)
	{
      gdistance = (contA[i] - contB[i])*(contA[i] - contB[i]);
      sum += gdistance;
 	}
 	
 	euc = sqrt(sum);

	printf("Similaridade: %.4lf", euc);

	printf("\n==================================================\n");
	puts ("\n------- Pressione uma tecla para voltar ao menu");
	getchar();

}

//===========================================================================================================
void menu(void)
{
    system("tput reset");
	// system ("cls");   // limpar tela windows
    
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
	puts ("\t |       6. Exibir Tabela			    |");	
	puts ("\t |       0. Sair                                    |");
	puts ("\t |                                                  |");
    puts ("\t +--------------------------------------------------+");
	puts ("\t | 		--> INSTRUCOES: <--     	    |");
    puts ("\t +--------------------------------------------------+");
	puts ("\t |     ** Eh necessario primeiramente **  	    |");
	puts ("\t |     ** escolher opcoes 1. 2. e 3.  ** 	    |");
	puts ("\t |     ** para execucao correta	      **	    |");	
    puts ("\t +--------------------------------------------------+");

}
//===========================================================================================================
char valida_op(void)
{
	char op, controle;
	int i = 1;
	do
	{
		printf("\n\tSelecione uma opcao [0-6]: _\b");
		scanf(" %c%*[^\n]",&op); 
		flush_in();
		if (op <'0' || op > '6')
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
//===========================================================================================================
void valida_string(char *p_string)
{	
	char c = p_string[strlen(p_string)-1];
	if ( c == '\n' || c == '.' || c == ',' || c == ':' ) {    // Verifica se existe o \n na string
		p_string[strlen(p_string)-1] = '\0';		// retira o '\n' ':' '.' ',' da string

		if (strlen(p_string) == 0 ) {        	// Verifica se existe a string esta vazia
			printf ("\n\tVoce nao pode deixar este campo em branco..\n\tInfome novamente: __________\b\b\b\b\b\b\b\b\b\b");
			fgets (p_string, MAX_WORD, stdin);
			valida_string(p_string);
		}
	}
}
//===========================================================================================================
FILE* abrir_arquivo (char *nome_arquivo, char modo_abertura )
{
	FILE *p_file = NULL;
	switch (modo_abertura){
		case 'a':
			p_file = fopen (nome_arquivo,"a");
			break;
		case 'w':
			p_file = fopen (nome_arquivo,"w");
			break;
		case 'r':
			p_file = fopen (nome_arquivo,"r");
			break;
		default:
			printf ("\t Modo de abertura de arquivo invalido! ");
	}
	if (p_file)
		return p_file;
	else
	{
		puts ("\n\n\t Erro ao abrir o arquivo ou arquivo inexistente.");
		printf ("\n\n---> Finalizando programa.........")	;
		printf ("\n______________________________________________________________________________________________\n\n");
		exit(1);
	}
}
//===========================================================================================================
void exportar_bow(FILE *p_tr, FILE *p_dic, FILE *p_bow, int cont[])
{
	BOW_T *bow = (BOW_T *) malloc(sizeof(BOW_T));
    char dic_word[MAX_WORD];
    char tr_word[MAX_WORD];;
	int i = 0, ocurr = 0;

    while(1)
    {
        if(fscanf(p_dic, "%s", dic_word) == EOF)  break;
        
        while(1)
        {
            if(fscanf(p_tr, "%s", tr_word) == EOF) break;
            else
            {	
				// printf("tr_word = %s\n", tr_word);
				valida_string(&tr_word[0]);
				// printf("tr_word = %s\n", tr_word);
				// getchar();
                if ( !(strcmp(tr_word, dic_word)) )
                    ocurr++;
            }
        }
        memcpy(bow->bow_word, dic_word, sizeof(bow));
        bow->bow_ocurr = ocurr;

		// printf("WORD :%s \n", bow->bow_word);
	    // printf("OCCUR:%d  \n", bow->bow_ocurr);
		// getchar();

        // if (fwrite (p_bow, sizeof(*p_bow), 1, p_fbow ) == 1);
        //     printf("\n\n\t\t\t\t****** Registro cadastrado com sucesso! ******\n");
		// while(fread(bow, sizeof(bow_t), 1, fp_bow) == 1)
        if (bow->bow_ocurr)
			fprintf(p_bow,"%s : %d\n", bow->bow_word , bow->bow_ocurr); 
        
		cont[i] = ocurr;

		ocurr = 0;
		i++;
        rewind (p_tr);
    }
	// for( int j = 0; j < i; j++)
	// 	printf("%d ",cont[j]);
	// printf("\n");

	// getchar();


        // while(fread(bow, sizeof(bow_t), 1, fp_bow) == 1)
        // // fprintf(fp_bow,"%s : %d\n", bow->bow_word , bow->bow_ocurr); 

        // printf("WORD :%s \n", bow->bow_word);
        // printf("OCCUR:%d  \n", bow->bow_ocurr);
        // fclose(fp_dic);

}

void exibir_tabela(char *arq_dic,int contA[], int contB[])
{
	char buff[MAX_LINE];
	int cont = 0;
	int i=0;
	
	FILE *p_file = abrir_arquivo(arq_dic, 'r');

	printf("\n_____________________________________________________\n\n");
	printf ("PALAVRAS|\t   |Texto A|\t\t   |Texto B|\n");
	while(!feof(p_file))
	{	
		if(fscanf(p_file, "%s", buff) == EOF)  break; 
			printf("%s\t\t\t%d\t\t\t%d \n",buff, contA[i], contB[i]);
		cont++;
		i++;
	}
	printf("\n_____________________________________________________\n");
	printf ("\n\t---> Aperte qualquer tecla para voltar..");
	getchar();
	
	// *qtde_dic = cont;
	// *p_contA = (int *) malloc(sizeof(int)* cont);
	// *p_contB = (int *) malloc(sizeof(int)* cont);

	fclose(p_file);
}

//===========================================================================================================
void flush_in()
{
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}
//===========================================================================================================
