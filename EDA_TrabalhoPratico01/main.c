#include "includes.h"



// ===========================================  Main =================================================== 
int main()
{
	char opcao;
	
	char arq_dic[MAX_WORD], arq_bowa[MAX_WORD], arq_bowb[MAX_WORD];
	char arq_tra[MAX_WORD], arq_trb[MAX_WORD]; 

	int qtde_dic = 0;
	int *contA, *contB;

	do
	{
		menu ();
		opcao =  valida_op();

		switch (opcao)
		{

			case '1': selecionar_dicionario(arq_dic, &qtde_dic, &contA, &contB); 	break;				
			case '2': selecionar_tra(arq_dic, arq_tra, contA);   			        break;
			case '3': selecionar_trb(arq_dic, arq_trb, contB);	     			    break;				
            case '4': exibir_bow_tr(arq_dic, arq_tra ,arq_trb);		       			break;				
            case '5': dist_euclid(contA, contB, qtde_dic);							break;
            case '6': exibir_tabela(arq_dic, contA, contB);							break;	
		}
	} while (opcao != '0');
	printf ("\n\n\n\n---> Finalizando programa.........")	;
	printf ("\n________________________________________________________________________________\n\n");
	free(contA);free(contB);
	return 0;

} // Fim da Main