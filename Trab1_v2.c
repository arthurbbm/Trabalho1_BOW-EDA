#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	char bow_word[40];
	int bow_ocurr;
}bow_t;

void similaridade(int arrA[], int arrB[], int size) {

   int i;
   float gdistance=0;
   float sum = 0;
   double euc;

   	for (i = 0; i < size; ++i)
	{
      gdistance = (arrA[i] - arrB[i])*(arrA[i] - arrB[i]);
      sum += gdistance;
 	}
 	
 	euc = sqrt(sum);

	printf("Similaridade: %.4lf", euc);
}

int cont_Dic_lines()
{
int size = 0;
FILE* fp_dic_countlines;

	fp_dic_countlines = fopen("dic.txt","r"); //read only

	while(1) 
	{
		char c = fgetc(fp_dic_countlines);
		if(c == EOF) break;
		if(c == '\n') size++;
	}	
	fclose(fp_dic_countlines);

	return size;
}

void bow()
{
    FILE *fpA;
    FILE *fp_dic;
    FILE *fp_bowA;

    FILE *fpB;
    FILE *fp_bowB;

    // char dic[2][10] = {"primeira", "segunda"};
    char *word = (char*)malloc(40);
    char *dic_word = (char*)malloc(40);
    int count = 0, ocurr = 0;
    int i=0;
    int word_count =0;
    char* Words[30]; //max 30
    int size_dic_Cont = 0;

    size_dic_Cont = cont_Dic_lines();

	// printf ("size dic cont = %d\n", size_dic_Cont);
	printf ("\n------ARQUIVO A\n--------\n");

    int contA[size_dic_Cont];
    int contB[size_dic_Cont];
    int contAB[2][size_dic_Cont];

    bow_t *bowA = (bow_t *) malloc (sizeof(bow_t));



    fp_dic = fopen("dic.txt","r"); //read only
    fp_bowA = fopen("bowA.txt","w"); //write only

    while(1)
	{
        if(fscanf(fp_dic, "%s", dic_word) == EOF)
        	break;
        // printf("DIC_WORD: %s\n",dic_word);
	    fpA = fopen("fileA.txt","r"); //read only					
	    while(1)
	    {
	        if(fscanf(fpA, "%s", word) == EOF)
	        	break;
	        else
	        {
		        // printf("word    : %s\n",word);
		        // printf("dic_word: %s\n",dic_word);

		    	if ( !(strcmp(word, dic_word)) )
		    	{
		    		// printf("achou: %s\n",word);
		    		ocurr++;
		    	}
	    	}
	    }
	    memcpy(bowA->bow_word, dic_word, sizeof(bowA));
	    bowA->bow_ocurr = ocurr;




	 //    if (fwrite (bow, sizeof(*bow), 1, fp_bow ) == 1);
 	// 		printf("\n\n\t\t\t\t****** Candidato cadastrado com sucesso! ******\n");

		// while(fread(bow, sizeof(bow_t), 1, fp_bow) == 1)

	    contA[word_count]=bowA->bow_ocurr;
	    contAB[0][word_count]=bowA->bow_ocurr;

	    if (bowA->bow_ocurr)
	    {
		    fprintf(fp_bowA,"%s : %d\n", bowA->bow_word , bowA->bow_ocurr); 

		    printf("WORD :%s \n", bowA->bow_word);
		    printf("OCCUR:%d  \n", bowA->bow_ocurr);


		    printf("ContA[%d] = %d \n------\n",word_count, contA[word_count]);
		}    
	    printf("CONT_AB[%d] = %d \n------\n",word_count, contAB[0][word_count]);
	    ocurr = 0;
	    word_count++;
	    fclose(fpA);
    }
	    fclose(fp_dic);


	// printf ("size dic cont = %d\n", size_dic_Cont);
	printf ("\n------ARQUIVO B\n--------\n");

	word_count =0;

    bow_t *bowB = (bow_t *) malloc (sizeof(bow_t));


    fp_dic = fopen("dic.txt","r"); //read only
    fp_bowB = fopen("bowB.txt","w"); //write only

    while(1)
	{
        if(fscanf(fp_dic, "%s", dic_word) == EOF)
        	break;
        // printf("DIC_WORD: %s\n",dic_word);
	    fpB = fopen("fileB.txt","r"); //read only					
	    while(1)
	    {
	        if(fscanf(fpB, "%s", word) == EOF)
	        	break;
	        else
	        {
		        // printf("word    : %s\n",word);
		        // printf("dic_word: %s\n",dic_word);

		    	if ( !(strcmp(word, dic_word)) )
		    	{
		    		// printf("achou: %s\n",word);
		    		ocurr++;
		    	}
	    	}
	    }
	    memcpy(bowB->bow_word, dic_word, sizeof(bowB));
	    bowB->bow_ocurr = ocurr;


	 //    if (fwrite (bow, sizeof(*bow), 1, fp_bow ) == 1);
 	// 		printf("\n\n\t\t\t\t****** Candidato cadastrado com sucesso! ******\n");

		// while(fread(bow, sizeof(bow_t), 1, fp_bow) == 1)
	    contB[word_count]=bowB->bow_ocurr;	
	    contAB[1][word_count]=bowB->bow_ocurr;

	    if (bowB->bow_ocurr)
	    {
		    fprintf(fp_bowB,"%s : %d\n", bowB->bow_word , bowB->bow_ocurr); 

		    printf("WORD :%s \n", bowB->bow_word);
		    printf("OCCUR:%d  \n", bowB->bow_ocurr);


		    printf("ContB[%d] = %d \n------\n",word_count, contB[word_count]);

		}
	    // printf("CONT_AB[%d] = %d \n------\n",word_count, contAB[word_count]);		

	    ocurr = 0;
	    word_count++;
	    fclose(fpB);
    }
	    fclose(fp_dic);

	    similaridade(contA, contB, size_dic_Cont);
	    // printf("SOMA:%d  \n", sim);

}

void main()
{
	bow();

}