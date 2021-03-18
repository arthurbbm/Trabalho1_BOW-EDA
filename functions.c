# include "functions.h"
# include <stdio.h>

#define MAX_WORD 30
#define MAX_LINE 100

typedef struct
{
	char bow_word[MAX_WORD];
	int bow_ocurr;
}BOW_T;


//===========================================================================================================
void selecionar_dicionario(char *arq_dic, int *qtde_dic, int **p_contA, int **p_contB)//O(n^2)
{
	char buff[MAX_LINE]; //O(1)
	int cont = 0; //O(1)

	printf("Selecionar Arquivo de Dicionario: "); //O(1)
	fgets (arq_dic, MAX_WORD, stdin); //O(n)
	valida_string(arq_dic);//O(n)

	FILE *p_file = abrir_arquivo(arq_dic, 'r');//O(1)

	printf("\n_____________________________________________________\n\n"); // O(1)

	while(!feof(p_file)) // O(n)
	{
		if(fgets(buff, MAX_LINE, p_file));//O(n^2)
			printf("\t%d: %s",cont + 1 ,buff);//O(n)
		cont++;//O(n^2)
	}
	printf("\nCont = %d", cont); //O(1)
	printf("\n_____________________________________________________\n"); //O(1)
	printf ("\n\n---> Arquivo selecionado com sucesso........."); //O(1)
	getchar(); //O(1)

	*qtde_dic = cont; //O(1)
	*p_contA = (int *) malloc(sizeof(int)* cont); //O(1)
	*p_contB = (int *) malloc(sizeof(int)* cont); //O(1)

	fclose(p_file); //O(1)
}
//===========================================================================================================
void selecionar_tra(char *arq_dic, char *arq_tra, int *contA)//O(n^3)
{
	printf("Selecionar Arquivo de Referencia A (TRA): "); //O(1)
	fgets (arq_tra, MAX_WORD, stdin); //O(n)
	valida_string(arq_tra); //O(n)

	FILE *p_tra  = abrir_arquivo(arq_tra, 'r');//O(1)
	FILE *p_dic = abrir_arquivo(arq_dic, 'r');//O(1)
	FILE *p_bow = abrir_arquivo("bowA.txt", 'w');//O(1)

	exportar_bow(p_tra, p_dic, p_bow, contA); //O(n^3)

	fclose(p_tra); //O(1)
	fclose(p_dic); //O(1)
	fclose(p_bow); //O(1)
}
//===========================================================================================================
void selecionar_trb(char *arq_dic, char *arq_trb, int *contB)//O(n^3)
{
	printf("Selecionar Arquivo de Referencia B (TRB): "); //O(1)
	fgets (arq_trb, MAX_WORD, stdin); //O(n)
	valida_string(arq_trb);//O(n)

	FILE *p_trb = abrir_arquivo(arq_trb, 'r');//O(1)
	FILE *p_dic = abrir_arquivo(arq_dic, 'r');//O(1)
	FILE *p_bow = abrir_arquivo("bowB.txt", 'w');//O(1)

	exportar_bow(p_trb, p_dic, p_bow, contB);//O(n^3)

	fclose(p_trb); //O(1)
	fclose(p_dic); //O(1)
	fclose(p_bow); //O(1)
}
//===========================================================================================================
void exibir_tabela(char *arq_dic,int contA[], int contB[])//O(n^2)
{
	char buff[MAX_LINE];//O(1)
	int cont = 0;//O(1)
	int i=0;//O(1)

	FILE *p_file = abrir_arquivo(arq_dic, 'r');//O(1)

	printf("\n_____________________________________________________\n\n");//O(1)
	printf ("PALAVRAS|\t   |Texto A|\t\t   |Texto B|\n");//O(1)
	while(!feof(p_file))//O(n)
	{
		if(fscanf(p_file, "%s", buff) == EOF)  break; //O(n^2)
			printf("%s\t\t\t%d\t\t\t%d \n",buff, contA[i], contB[i]);//O(n)
		cont++;//O(n^2)
		i++;//O(n^2)
	}
	printf("\n_____________________________________________________\n");//O(1)
	printf ("\n\t---> Aperte qualquer tecla para voltar..");//O(1)
	getchar();//O(1)

	fclose(p_file);//O(1)
}
//===========================================================================================================
void exibir_bow_tr(int qtde_dic)//O(n^2)
{
	char op, controle; //O(1)
	char nome_arquivo[MAX_WORD]; //O(1)

	do //O(1)
	{
		//system("tput reset"); //O(n)
		system("cls"); //O(n)
		puts ("\n================================================================================================"); //O(n)
		puts("\n\t==>>  Listar arquivos\n\n"); //O(n)

		puts ("\t	1. Exibir bowA.txt");//O(n)
		puts ("\t	2. Exibir bowB.txt");//O(n)
		puts ("\t	3. Exibir tra.txt");//O(n)
		puts ("\t	4. Exibir trb.txt");//O(n)
		puts ("\t	5. Exibir Dicionario");//O(n)
		puts ("\t	6. contA");//O(n)
		puts ("\t	7. contB");//O(n)
		puts ("\t	0. voltar menu inicial");//O(n)

		printf("\n\tSelecione uma opcao [0-7]: _\b");//O(n)
		scanf(" %c%*[^\n]",&op);//O(n^2)

		switch (op) //O(n)
		{
			case '1':
				strcpy (nome_arquivo, "bowA.txt");//O(n^2)
				break;

			case '2':
				strcpy (nome_arquivo, "bowB.txt");//O(n^2)
				break;

			case '3':
				strcpy (nome_arquivo, "tra.txt");//O(n^2)
				break;

			case '4':
				strcpy (nome_arquivo, "trb.txt");//O(n^2)
				break;

			case '5':
				strcpy (nome_arquivo, "dic1.txt");//O(n^2)
				break;

			case '6':
				break;

			case '7':
				break;

			default :
    			printf ("Valor invalido!\n");//O(n)

		}
		flush_in();//O(n^2)
		FILE *p_file = abrir_arquivo(nome_arquivo, 'r');//O(n)
		char buff[MAX_LINE];//O(n)

		//system("tput reset");//O(n)
		system("cls");//O(n)
		printf("\n==================================================\n");//O(n)
		printf("\n\t==>>  %s\n\n", nome_arquivo);//O(n)
		while(fgets(buff, MAX_LINE, p_file))//O(n^2)
		{
            printf("\t%s",buff);//O(n^2)
		}
		printf("\n==================================================\n");//O(n)
		puts ("\n------- Pressione uma tecla para voltar ao menu");//O(n)
		getchar();//O(n)

	} while (op != '0');//O(n)
	puts ("\n\n-------> Pressione uma tecla para voltar ao menu inicial");//O(1)
	puts ("================================================================================================");//O(1)
	getchar();//O(1)
}
//===========================================================================================================
void valida_string(char *p_string)//O(n)
{
	char c = p_string[strlen(p_string)-1];//O(n)
	if ( c == '\n' || c == '.' || c == ',' || c == ':' ) {//O(1)    // Verifica se existe o \n na string
		p_string[strlen(p_string)-1] = '\0';//O(n)		// retira o '\n' ':' '.' ',' da string

		if (strlen(p_string) == 0 ) {//O(n)        	// Verifica se existe a string esta vazia
			printf ("\n\tVoce nao pode deixar este campo em branco..\n");//O(1)
			getchar();//O(1)
		}
	}
}
//===========================================================================================================
FILE* abrir_arquivo (char *nome_arquivo, char modo_abertura )//O(1)
{
	FILE *p_file = NULL;//O(1)
	switch (modo_abertura){//O(1)
		case 'a':
			p_file = fopen (nome_arquivo,"a");//O(1)
			break;
		case 'w':
			p_file = fopen (nome_arquivo,"w");//O(1)
			break;
		case 'r':
			p_file = fopen (nome_arquivo,"r");//O(1)
			break;
		default:
			printf ("\t Modo de abertura de arquivo invalido! ");//O(1)
	}
	if (p_file)//O(1)
		return p_file;//O(1)
	else//O(1)
	{
		puts ("\n\n\t Erro ao abrir o arquivo ou arquivo inexistente.");//O(1)
		printf ("\n\n---> Finalizando programa.........");//O(1)
		printf ("\n______________________________________________________________________________________________\n\n");//O(1)
		exit(1);//O(1)
	}
}
//===========================================================================================================
void exportar_bow(FILE *p_tr, FILE *p_dic, FILE *p_bow, int cont[])//O(n^3)
{
	BOW_T *bow = (BOW_T *) malloc(sizeof(BOW_T));//O(1)
    char dic_word[MAX_WORD];//O(1)v
    char tr_word[MAX_WORD];//O(1)
	int i = 0, ocurr = 0;//O(1)

    while(1)//O(n)
    {
        if(fscanf(p_dic, "%s", dic_word) == EOF)  break; //O(n^2)

        while(1) //O(n^2)
        {
            if(fscanf(p_tr, "%s", tr_word) == EOF) break;//O(n^3)
            else//O(n^2)
            {
				valida_string(&tr_word[0]);//o(n^3)

                if ( !(strcmp(tr_word, dic_word)) )//O(n^3)
                    ocurr++;//O(n^3)
            }
        }
        memcpy(bow->bow_word, dic_word, sizeof(bow));//O(n^2)
        bow->bow_ocurr = ocurr;//O(n)

		fprintf(p_bow,"%s : %d\n", bow->bow_word , bow->bow_ocurr);//O(n)

		cont[i] = ocurr;//O(n)

		ocurr = 0;//O(n)
		i++;//O(n^2)
        rewind (p_tr);//O(n^2)
    }
}
//===========================================================================================================
void dist_euclid(int contA[], int contB[], int qtde_dic)//O(n^2)
{
    int i;//O(1)
    float gdistance=0;//O(1)
    float sum = 0;//O(1)
    double euc;//O(1)

    //system("tput reset");//O(1)
    system("cls");//O(1)
    printf("\n==================================================\n");//O(1)
    printf("\n\t==>>  Vetores BOW\n\n");//O(1)

    printf("contA = {");//O(1)

    for( i = 0; i < qtde_dic; i++)//O(n)
        printf(" %d, ",contA[i]);//O(n)

    printf("}\n");//O(1)
    printf("contB = {");//O(1)

    for( i = 0; i < qtde_dic; i++)//O(n)
        printf(" %d, ",contB[i]);//O(n)

    printf("}\n");//O(1)


    for (i = 0; i < qtde_dic; ++i)//O(n)
    {
      gdistance = (contA[i] - contB[i])*(contA[i] - contB[i]);//O(n)
      sum += gdistance;//O(n^2)
    }

    euc = sqrt(sum);//O(1)

    printf("Similaridade: %.4lf", euc);//O(1)

    printf("\n==================================================\n");//O(1)
    puts ("\n------- Pressione uma tecla para voltar ao menu");//O(1)
    getchar();//O(1)

}
//===========================================================================================================
void flush_in()//O(n)
{
    int ch;//O(n)
    do {//O(1)
        ch = fgetc(stdin);//O(n)
    } while (ch != EOF && ch != '\n');//O(n)
}
