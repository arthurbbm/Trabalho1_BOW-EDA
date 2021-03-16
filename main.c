#include <stdio.h>


//Menu
    //D
        //Ler arquivo Dicionário
    //TRA
        //Criação do bowA.txt
            //
    //TRB
    //Exibir BOW
    //Mostrar similaridade entre os dois textos
    //Sair

FILE *Arquivo_AbreLeitura(char *PNomeArquivo){
    return fopen(PNomeArquivo,"r");
}

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
        printf("\nA - Selecionar Arquivo de Referência A");
        printf("\nB - Selecionar Arquivo de Referência B");
        printf("\nD - Selecionar Arquivo de Especificação de Dicionário");
        printf("\ne - Exibir Arquivo de BOWs");
        printf("\nt - Exibir similaridades entre TRA e TRB");
        printf("\nS - Sair");
        printf("\nOpção: ");
        scanf("\n%c", &popc);
        switch (popc) {
            case 'D':
                printf("Arquivo de Especificação de Dicionário: ");
                scanf("%s",NomeArq);
                if(Dicionario != NULL)
                    fclose(Dicionario);
                Dicionario = Arquivo_AbreLeitura(NomeArq);
                if(Dicionario == NULL){
                    printf("Erro 2: Arquivo de Especificação de Dicionario não pode ser aberto\n");
                    break;
                }

                // Conta o número de palavras no Dicionário
                while(1) {
                    c = fgetc(Dicionario);
                    if(c == EOF) break;
                    if(c == '\n') sizeCont++;
                }
                ContA = (int*) malloc(sizeof(int) * sizeCont);
                ContB = (int*) malloc(sizeof(int) * sizeCont);
                printf("%d", sizeCont);

                break;

            case 'A':
                printf("Arquivo de Referência: ");
                scanf("%s",NomeArq);
                if(TRA != NULL)
                    fclose(TRA);
                TRA = Arquivo_AbreLeitura(NomeArq);
                if(TRA == NULL){
                    printf("Erro 1: Arquivo de Referência não pode ser aberto\n");
                }
                printf("%s aberto!!!\n", NomeArq);
                break;

            case 'B':
                printf("Arquivo de Referência: ");
                scanf("%s",NomeArq);
                if(TRB != NULL)
                    fclose(TRB);
                TRB = Arquivo_AbreLeitura(NomeArq);
                if(TRB == NULL){
                    printf("Erro 1: Arquivo de Referência não pode ser aberto\n");
                }
                printf("%s aberto!!!\n", NomeArq);
                break;

            /*
            case 'r':
                if(!Arquivo_MostraConteudo(AR)){
                    printf("Arquivo de Referência não está carregado\n");
                }
                break;
            case 't':
                if(!Arquivo_MostraConteudo(Token)){
                    printf("Arquivo de Especificação de Token não está carregado\n");
                }
                break;
            case 'A':
                printf("Arquivo de Saída: ");
                scanf("%s",NomeArq);
                if(Saida != NULL)
                    fclose(Saida);
                Saida = Arquivo_Novo(NomeArq);
                if(Saida == NULL){
                    printf("Erro 3: Arquivo de Saída não pode ser criado\n");
                }
                //Faça a chamada às funções que vc criou para aplicar a Tokenização aqui.
                //Ao final: Feche o arquivo de saída. Abra-o em modo de leitura e mostre seu
                //conteúdo.


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
