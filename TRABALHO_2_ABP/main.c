#include <stdio.h>
#include <stdlib.h>

#define MAX 15
#define max(a,b) \
({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b; })


struct node
{
    int data; //node will store an integer
    struct node *right_child; // right child
    struct node *left_child; // left child
    int FatBal;
};

struct node* search(struct node *root, int x)
{
    if(root==NULL || root->data==x) //if root->data is x then the element is found
        return root;
    else if(x>root->data) // x is greater, so we will search the right subtree
        return search(root->right_child, x);
    else //x is smaller than the data, so we will search the left subtree
        return search(root->left_child,x);
}

//function to find the minimum value in a node
struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left_child != NULL) // node with minimum value will have no left child
        return find_minimum(root->left_child); // left most element will be minimum
    return root;
}

//function to create a node
struct node* new_node(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;
    p->FatBal = NULL;

    return p;
}

struct node* insert(struct node *root, int x)
{
    //searching for the place to insert
    if(root==NULL) {
        return new_node(x);
    }
    else if(x>root->data) {// x is greater. Should be inserted to right
        root->right_child = insert(root->right_child, x);
    }
    else if(x<root->data)// x is smaller should be inserted to left
        root->left_child = insert(root->left_child,x);
    else
        return root;
}

// funnction to delete a node
struct node* delete(struct node *root, int x)
{
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right_child = delete(root->right_child, x);
    else if(x<root->data)
        root->left_child = delete(root->left_child, x);
    else
    {
        //No Children
        if(root->left_child==NULL && root->right_child==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct node *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete(root->right_child, temp->data);
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {
        inorder(root->left_child); // visiting left child
        printf("Chave: %d; FB: %d\n", root->data, root->FatBal); // printing data at root
        inorder(root->right_child);// visiting right child
    }
}

int height(struct node *root) {
    if (root == NULL) return -1;
    else {
        int left_height, right_height;
        left_height = height(root->left_child);
        right_height = height(root->right_child);

        return max(left_height, right_height) + 1;
    }
}

void FB(struct node *root) {
    if(root == NULL) return;

    int fb, left_height, right_height;

    left_height = height(root->left_child);
    right_height = height(root->right_child);
    fb = left_height - right_height;
    root->FatBal = fb;

    FB(root->left_child);
    FB(root->right_child);
}

void main()
{

int i = 0, cont = 0;

    struct node *root;
    
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
                root = new_node(vector[0]);
                i++;
                continue;
            }
            // printf (" %d ", vector[i]);
            insert(root,vector[i]);
            i++;
        }

    fclose(p_file);

    FB(root);
    inorder(root);

 
}