#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char bow_word[40];
	int bow_ocurr;
}bow_t;

int main(){
    FILE *fp, *fp_dic;
    FILE *fp_bow;
    // char dic[2][10] = {"primeira", "segunda"};
    char *word = (char*)malloc(40);
    char *dic_word = (char*)malloc(40);
    int count = 0, ocurr = 0;
    int i=0;
    int word_count =0;
    char* Words[30]; //max 30

    bow_t *bow = (bow_t *) malloc (sizeof(bow_t));


    fp_dic = fopen("dic.txt","r"); //read only
    fp_bow = fopen("bow.txt","w"); //write only

    while(1)
	{
        if(fscanf(fp_dic, "%s", dic_word) == EOF)
        	break;
        // printf("DIC_WORD: %s\n",dic_word);
	    fp = fopen("file1.txt","r"); //read only					
	    while(1)
	    {
	        if(fscanf(fp, "%s", word) == EOF)
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
	    memcpy(bow->bow_word, dic_word, sizeof(bow));
	    bow->bow_ocurr = ocurr;




	 //    if (fwrite (bow, sizeof(*bow), 1, fp_bow ) == 1);
 	// 		printf("\n\n\t\t\t\t****** Candidato cadastrado com sucesso! ******\n");

		// while(fread(bow, sizeof(bow_t), 1, fp_bow) == 1)
	    fprintf(fp_bow,"%s : %d\n", bow->bow_word , bow->bow_ocurr); 

	    printf("WORD :%s \n", bow->bow_word);
	    printf("OCCUR:%d  \n", bow->bow_ocurr);


	    ocurr = 0;
	    word_count++;
	    fclose(fp);
    }
	    fclose(fp_dic);
	    
	    return 0;
}