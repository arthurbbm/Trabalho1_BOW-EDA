# include <stdio.h>
# include "menu.h"
# include "functions.h"

#define MAX_WORD 30

// ===========================================  Main ===================================================
int main()//O(n^4)
{
	char opcao;//O(1)

	char arq_dic[MAX_WORD], arq_bowa[MAX_WORD], arq_bowb[MAX_WORD];//O(1)
	char arq_tra[MAX_WORD], arq_trb[MAX_WORD];//O(1)

	int qtde_dic = 0;//O(1)
	int *contA, *contB;//O(1)

	do//O(1)
	{
		menu();//O(n)
		opcao =  valida_op();//O(n^3)
		switch (opcao)//O(n)
		{

			case '1': selecionar_dicionario(arq_dic, &qtde_dic, &contA, &contB); 	break;//O(n^3)
			case '2': selecionar_tra(arq_dic, arq_tra, contA);   			        break;//O(n^4)
			case '3': selecionar_trb(arq_dic, arq_trb, contB);	     			    break;//O(n^4)
			case '4': exibir_tabela(arq_dic, contA, contB);					        break;//O(n^3)
            case '5': exibir_bow_tr(qtde_dic);					         			break;//O(n^3)
            case '6': dist_euclid(contA, contB, qtde_dic);							break;//O(n^3)
		}
	} while (opcao != '0');//O(n)
	printf ("\n\n\n\n---> Finalizando programa.........");//O(1)
	printf ("\n________________________________________________________________________________\n\n");//O(1)
	return 0;//O(1)
}
