#include <stdio.h>
#include "bow.c"


//Menu
    //D
        //Ler arquivo Dicion�rio
    //TRA
        //Cria��o do bowA.txt
            //
    //TRB
    //Exibir BOW
    //Mostrar similaridade entre os dois textos
    //Sair


int main(int argc, const char * argv[]) {
    char NomeArq[30] = "";
    int *ContA, *ContB;
    FILE *TRA = NULL;
    FILE *TRB = NULL;
    FILE *Dicionario= NULL;
    //FILE *bowA= NULL;
    //FILE *bowA= NULL;
    char popc = '0';
    char c;
    int sizeCont = 0;

    while(popc != 'S'){
        printf("\n################## ENTIDADES NOMEADAS ##################");
        printf("\n");
        printf("\nA - Selecionar Arquivo de Refer�ncia A");
        printf("\nB - Selecionar Arquivo de Refer�ncia B");
        printf("\nD - Selecionar Arquivo de Especifica��o de Dicion�rio");
        printf("\ne - Exibir Arquivo de BOWs");
        printf("\nt - Exibir similaridades entre TRA e TRB");
        printf("\nS - Sair");
        printf("\nOp��o: ");
        scanf("\n%c", &popc);
        switch (popc) {
            case 'D':
                printf("Arquivo de Especifica��o de Dicion�rio: ");
                scanf("%s",NomeArq);
                if(Dicionario != NULL)
                    fclose(Dicionario);
                Dicionario = fopen(NomeArq,"r");
                if(Dicionario == NULL){
                    printf("Erro 2: Arquivo de Especifica��o de Dicionario n�o pode ser aberto\n");
                    break;
                }

                // Conta o n�mero de palavras no Dicion�rio
                while(1) {
                    c = fgetc(Dicionario);
                    if(c == EOF) break;
                    if(c == '\n') sizeCont++;
                }
                ContA = malloc(sizeof(int) * sizeCont);
                ContB = malloc(sizeof(int) * sizeCont);

                break;

            case 'A':
                printf("Arquivo de Refer�ncia: ");
                scanf("%s",NomeArq);
                bow(NomeArq, Dicionario, "bowA.txt", ContA);

                break;

            case 'B':
                printf("Arquivo de Refer�ncia: ");
                scanf("%s",NomeArq);
                bow(NomeArq, Dicionario, "bowB.txt", ContB);

                break;

            /*
            case 'r':
                if(!Arquivo_MostraConteudo(AR)){
                    printf("Arquivo de Refer�ncia n�o est� carregado\n");
                }
                break;
            case 't':
                if(!Arquivo_MostraConteudo(Token)){
                    printf("Arquivo de Especifica��o de Token n�o est� carregado\n");
                }
                break;
            case 'A':
                printf("Arquivo de Sa�da: ");
                scanf("%s",NomeArq);
                if(Saida != NULL)
                    fclose(Saida);
                Saida = Arquivo_Novo(NomeArq);
                if(Saida == NULL){
                    printf("Erro 3: Arquivo de Sa�da n�o pode ser criado\n");
                }
                //Fa�a a chamada �s fun��es que vc criou para aplicar a Tokeniza��o aqui.
                //Ao final: Feche o arquivo de sa�da. Abra-o em modo de leitura e mostre seu
                //conte�do.


                printf("%s gerado!!!\n", NomeArq);
                break;
            */

            case 'S':
                break;
        }
        if(popc == 'S')
            break;
    }

    fclose(TRA);
    fclose(TRB);
    fclose(Dicionario);
    //fclose(Saida);
    printf("\n\n ----- Sistema Encerrado ----- \n\n");

    return 0;
}
