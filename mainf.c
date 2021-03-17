# include <stdio.h>
# include <stdlib.h>
# include <string.h>

#define MAX_WORD 30

typedef struct
{
	char bow_word[MAX_WORD];
	int bow_ocurr;
}BOW_T;

// typedef struct
// {
// 	char bow_word[MAX_WORD];
// 	int bow_a;
//     int bow_b;
// }BOWs_T;

void menu(void);
char valida_op(void);
void valida_string(char *p_string);
FILE* abrirArquivo (char *nome_arquivo, char modo_abertura );
void exporta_tr(BOW_T *p_bow, char *nome_arq_dic, char *nome_arq_bow, char *nome_arq_tr);
void le_dicionario(BOW_T *p_bow,  int *qtde_dic);
void lista_bow_tr(BOW_T *p_bow,  int qtde_dic);
void dist_euclid(BOW_T *p_bow,  int qtde_dic);
void flush_in();
void exclui_arquivo();

// ================================  Main ======================================== 
int main()
{
	char opcao;
	BOW_T *p_bow = (BOW_T *) malloc(sizeof(BOW_T));
	char nome_arq_dic[] = "dicionario.txt";
	char nome_arq_bowa[] ="bowa.txt";
	char nome_arq_bowb[] ="bowb.txt";
	char nome_arq_tra[] = "tra.txt";
	char nome_arq_trb[] = "trb.txt";

	int qtde_dic = 0;

	do
	{
		menu ();
		opcao =  valida_op();
		switch (opcao)
		{
			case '1': le_dicionario(p_bow, &qtde_dic);	break;				
			case '2': exporta_tr(p_bow, nome_arq_dic, nome_arq_bowa, nome_arq_tra );	    break;				
            case '4': lista_bow_tr(p_bow, qtde_dic);	break;				
            case '5': dist_euclid(p_bow, qtde_dic);		break;				
			case '6': exclui_arquivo(&qtde_dic);
		}
	} while (opcao != '0');
	printf ("\n\n\n\n---> Finalizando programa.........")	;
	printf ("\n________________________________________________________________________________\n\n");
	return 0;

} // Fim da Main

//===========================================================================================================
void flush_in() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}
//===========================================================================================================
void le_dicionario(BOW_T *p_bow,  int *qtde_dic)
{
	printf("Entrei funcao ler dicionario!\n");
	getchar();	
}
//===========================================================================================================
void lista_bow_tr(BOW_T *p_bow,  int qtde_dic)
{
	printf("Entrei funcao listar bow!\n");
	getchar();	
}
//===========================================================================================================
void dist_euclid(BOW_T *p_bow,  int qtde_dic)
{
	printf("Entrei funcao distancia de euclides!\n");
	getchar();	
}
//===========================================================================================================
void menu(void)
{
    system("tput reset");
	// system ("cls");
 	// system ("clear");
    //printf("\e[H\e[2J");               //limpa a tela
    
	puts ("\n========================================================================");
	puts ("\t\t      TRABALHO PRATICO 1 - VETORES DINAMICOS");
	puts ("========================================================================\n\n");
	puts ("\t +--------------------------------------------------+");
	puts ("\t |                                                  |");
	puts ("\t | --> Escolha uma das opcoes abaixo                |");
	puts ("\t |                                                  |");
	puts ("\t +--------------------------------------------------+");
	puts ("\t |                                                  |");
	puts ("\t |       1. Ler Arquivo de dicionario               |");
	puts ("\t |       2. Exportar BOW TRA                        |");
	puts ("\t |       3. Exportar BOW TRA                        |");
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
//===========================================================================================================
void valida_string(char *p_string)
{
	// if (p_string[strlen(p_string)-1] == '\n') {    // Verifica se existe o \n na string
	// 	p_string[strlen(p_string)-1] = '\0';		// retira o \n na string

	// 	if (strlen(p_string) == 0 ) {        	// Verifica se existe a string esta vazia
	// 		printf ("\n\tVoce nao pode deixar este campo em branco..\n\tInfome novamente: __________\b\b\b\b\b\b\b\b\b\b");
	// 		fgets (p_string, MAX_WORD, stdin);
	// 		valida_string(p_string);
	// 	}
	// }
}
//===========================================================================================================
FILE* abrir_arquivo (char nome_arquivo[], char modo_abertura )
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
void exclui_arquivo()
{
	char op, controle;
    system("tput reset");

	do
	{
		system("tput reset");
		puts ("\n================================================================================================");
		// display2();
		puts ("================================================================================================");
		puts("\n\t==>>  1. Excluir arquivos\n");
		
		puts ("\t	1. Excluir arquivo de Dicionario");
		puts ("\t	2. Excluir arquivo TRA");
		puts ("\t	3. Excluir arquivo TRB");
		puts ("\t	4. Excluir arquivo BOW TRA");
		puts ("\t	5. Excluir arquivo BOW TRB");
		puts ("\t   0. Voltar menu inicial");

		printf("\n\tSelecione uma opcao [0-5]: _\b");
		scanf(" %c%*[^\n]",&op); 
		
		switch (op)
		{

			case '1':	
				if(remove("fdic.txt"))
					printf("\n\n\t---> %d Dicionario removido com sucesso!\n");
				puts ("==============================================================================================\n");
				getchar();
				break;

			case '2': remove("ftra.txt");	    break;				
			case '3': remove("ftrb.txt");	    break;				
			case '4': remove("fbowa.txt"); 	    break;				
			case '5': remove("fbowb.txt");		break;
			default :
    			printf ("Valor invalido!\n");

		}
	} while (op != '0');
	puts ("\n\n------------> Pressione uma tecla para voltar ao menu inicial");
	puts ("================================================================================================");
	getchar();
}
//===========================================================================================================
void exporta_tr(BOW_T *p_bow, char *nome_arq_dic, char *nome_arq_bow, char *nome_arq_tr)
{
    char dic_word[MAX_WORD];
    char tr_word[MAX_WORD];;
    FILE *p_fbow, *p_fdic, *p_ftr;
	int count = 0, ocurr = 0;

    p_fbow = abrir_arquivo(nome_arq_bow,'a');
    p_fdic = abrir_arquivo(nome_arq_dic,'a');
    p_ftr  = abrir_arquivo(nome_arq_tr,'a');

    while(1)
    {
        if(fscanf(p_fdic, "%s", dic_word) == EOF)  break;
        
        while(1)
        {
            if(fscanf(p_ftr, "%s", tr_word) == EOF) break;
            else
            {
                if ( !(strcmp(tr_word, dic_word)) )
                    ocurr++;
            }
        }
        memcpy(p_bow->bow_word, dic_word, sizeof(MAX_WORD));
        p_bow->bow_ocurr = ocurr;

        // if (fwrite (p_bow, sizeof(*p_bow), 1, p_fbow ) == 1);
        //     printf("\n\n\t\t\t\t****** Registro cadastrado com sucesso! ******\n");
		// while(fread(bow, sizeof(bow_t), 1, fp_bow) == 1)


		fprintf(p_fbow,"%s : %d\n", p_bow->bow_word , p_bow->bow_ocurr); 

	    printf("WORD :%s \n", p_bow->bow_word);
	    printf("OCCUR:%d  \n", p_bow->bow_ocurr);
        
		ocurr = 0;
        rewind (p_ftr);
        
    }
    fclose(p_fbow);
    fclose(p_fdic);
    fclose(p_ftr);

        // while(fread(bow, sizeof(bow_t), 1, fp_bow) == 1)
        // // fprintf(fp_bow,"%s : %d\n", bow->bow_word , bow->bow_ocurr); 

        // printf("WORD :%s \n", bow->bow_word);
        // printf("OCCUR:%d  \n", bow->bow_ocurr);
        // fclose(fp_dic);

}
//===========================================================================================================
