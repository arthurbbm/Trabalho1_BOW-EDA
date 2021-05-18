#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "abp.h" 

//==============================================================================================
int create_tree()
{
    int tmp, n = 0;
    char linha[1000];

    FILE *pFile = fopen("testA.csv", "r");

    if(pFile == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }
    
    fgets(linha, sizeof(linha),pFile);

    char *token;
    token = strtok(linha, ",");

    while (token != NULL) 
    {
        tmp = atoi(token);
        if(raiz == NULL)
            raiz = new_node(tmp);
        
        else 
            insert(raiz, tmp);

        token = strtok(NULL,",");
        n++;
    }
    fclose(pFile);
    fatBal(raiz);
   
   return n;
}

//==============================================================================================
NO *new_node(int x)
{
    NO *p;
    p = malloc(sizeof(NO));
    p->chave = x;
    p->pEsq = NULL;
    p->pDir = NULL;
    p->fb = 0;

    printf("p->chave = %d\n", p->chave);

    return p;
}
//==============================================================================================
NO *insert(NO *t, int x)
{
    
    if(t == NULL) 
        return new_node(x);
    else if(x > t->chave)
        t->pDir = insert(t->pDir, x);
    else if(x < t->chave)
        t->pEsq = insert(t->pEsq,x);
    else
        return t;
}
//==============================================================================================
void print_inorder(NO *p)
{
    if(p != NULL)
    {
        print_inorder(p->pEsq);
        printf("Chave: %d; FB: %d\n", p->chave, p->fb);
        print_inorder(p->pDir);
    }
}
//==============================================================================================
int height(NO *t)
{
    if (t == NULL) return -1;
    else 
    {
        int lh, rh;
        lh = height(t->pEsq);
        rh = height(t->pDir);

        return max(lh, rh) + 1;
        // return lh>rh ? lh+1 : rh+1;
    }
}
//==============================================================================================
void fatBal(NO *t) 
{
    if(t == NULL) return;

    int fb, lh, rh;

    lh = height(t->pEsq);
    rh = height(t->pDir);
    fb = lh - rh;
    t->fb = fb;

    fatBal(t->pEsq);
    fatBal(t->pDir);
}
//==============================================================================================
void clear_tree(NO *d)
{
    if(d != NULL)
    {
        clear_tree(d->pEsq);
        clear_tree(d->pDir);
        printf("desalocar %d\n", d->chave);
        
        free(d);
    }
}
//==============================================================================================

    
    
