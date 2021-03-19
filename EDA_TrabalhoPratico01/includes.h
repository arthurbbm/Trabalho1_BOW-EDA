#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORD 30
#define MAX_LINE 100

typedef struct
{
	char bow_word[MAX_WORD];
	int bow_ocurr;
}BOW_T;


// =======================================  Protótipos ================================================== 
void menu(void);
char valida_op(void);
void valida_string(char *p_string);
FILE* abrir_arquivo (char *nome_arquivo, char modo_abertura);
void exportar_bow(FILE *p_tr, FILE *p_dic, FILE *p_bow, int *cont);
void selecionar_dicionario(char *arq_dic, int *qtde_dic, int **p_contA, int **p_contB);
void selecionar_tra(char *arq_dic, char *arq_tra, int *contA);
void selecionar_trb(char *arq_dic, char *arq_trb, int *contB);
void exibir_bow_tr(char *arq_dic,char *arq_tra,char *arq_trb);
void dist_euclid(int contA[], int contB[], int qtde_dic);
void flush_in();
void exclui_arquivo();
void exibir_tabela(char *arq_dic,int contA[], int contB[]);