#ifndef functions_h_
#define functions_h_

#include <stdio.h>

void valida_string(char *p_string);
FILE* abrir_arquivo (char *nome_arquivo, char modo_abertura);
void exportar_bow(FILE *p_tr, FILE *p_dic, FILE *p_bow, int *cont);
void selecionar_dicionario(char *arq_dic, int *qtde_dic, int **p_contA, int **p_contB);
void selecionar_tra(char *arq_dic, char *arq_tra, int *contA);
void selecionar_trb(char *arq_dic, char *arq_trb, int *contB);
void exibir_bow_tr(int qtde_dic);
void dist_euclid(int contA[], int contB[], int qtde_dic);
void flush_in();

#endif //functions_h_
