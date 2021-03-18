#include <stdio.h>

typedef struct
{
	char bow_word[40];
	int bow_ocurr;
}bow_t;

void bow(char * TR, FILE * Dicionario, char * bow_file_name, int * Cont) {

    FILE *bow_file, *tr;
    char *word = malloc(40);
    char *dic_word = malloc(40);
    int ocurr = 0, i = 0;
    bow_t *bow_struct = malloc(sizeof(bow_t));

    bow_file = fopen(bow_file_name,"w");

    rewind(Dicionario);
    while(1) {
        if(fscanf(Dicionario, "%s", dic_word) == EOF)
        	break;
        tr = fopen(TR,"r");
	    while(1) {
	        if(fscanf(tr, "%s", word) == EOF)
	        	break;
	        else {
		    	if ( !(strcmp(word, dic_word)) ) {
		    		ocurr++;
		    	}
	    	}
	    }
	    memcpy(bow_struct->bow_word, dic_word, sizeof(bow_struct));
	    bow_struct->bow_ocurr = ocurr;

	    fprintf(bow_file,"%s : %d\n", bow_struct->bow_word , bow_struct->bow_ocurr);

        Cont[i] = ocurr;
        i++;
	    ocurr = 0;
	    fclose(tr);
	}
	fclose(bow_file);
    return;
}
