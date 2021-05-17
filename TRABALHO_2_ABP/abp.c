#include <stdio.h> 
#include <stdlib.h>
#include "abp.h" 

//==============================================================================================
int create_tree()
{
    int i = 0, cont = 0;

    FILE* p_file;
    p_file = fopen ("Teste_A","r");
    printf ("abriu teste A");

    while(!feof(p_file))
    {   
        char buf[MAX];
        fgets(buf, MAX, p_file);
        cont++;
    }
    fclose(p_file);
    printf ("\n cont %d \n", cont);

    int vector[cont];

    p_file = fopen ("Teste_A","r");

        while( (fscanf (p_file, "%d", &vector[i]) ) != EOF) 
        {
            if (i == 0)
            {
                raiz = new_node(vector[0]);
                i++;
                continue;
            }
            insert(raiz, vector[i]);
            i++;
        }
        fatBal(raiz);
   
   return cont;
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
int height(NO *t) {
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
void fatBal(NO *t) {
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
