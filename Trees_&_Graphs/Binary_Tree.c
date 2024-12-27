

#include<stdio.h>
#include<stdlib.h>


struct Node
{
    char data;
    struct Node *lchild;
    struct Node *rchild;
};

typedef struct Node NODE;
NODE *root=NULL, *p=NULL;


NODE* create(NODE *p ,char data);
void search(NODE *p,char key);
void inorder(NODE *p);
void preorder(NODE *p);
void postorder(NODE *p);


int main()
{
    int ch;
    char data,key;

    do 
    {
        printf("\n1.Create\n2.Search\n3.Inorder\n4.Preorder\n5.Postorder\n6.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("\nEnter the Data to insert in TREE: ");
            		scanf(" %c",&data);

                    root=create(root,data);
                    break;

            case 2: printf("Enter Data to Be searched: ");
                    scanf(" %c",&key);
                    search(root,key);
                    break;

            case 3: inorder(root);
                    printf("\n");
                    break;

            case 4: preorder(root);
                    printf("\n");
                    break;

            case 5: postorder(root);
                    printf("\n");
                    break;

            case 6: 
                    break;

            default: printf("Invalid Choice");
        }


    }while(ch!=6);

return 0;
}

NODE* create(NODE *p ,char data)
{
    if (p == NULL) 
    {
        p = (NODE *)malloc(sizeof(NODE));
        if (p == NULL) 
        {
            printf("Memory allocation failed\n");
            return NULL; 
        }
        p->data = data;
        p->lchild = NULL;
        p->rchild = NULL;
    } 
    
    else if (data < p->data) 
    {
        p->lchild = create(p->lchild, data);
    } 
    
    else 
    {
        p->rchild = create(p->rchild, data);
    }
    
    return p;
}


void search(NODE *p,char key)
{
    if (p == NULL) 
    {
        printf("Search Unsuccessful\n");
        return;
    }

    else
    {
        if(key==p->data)
        printf("Search Successful");

        else if(key<p->data)
        search(p->lchild,key);

        else
        search(p->rchild,key);
    }
}

void inorder(NODE *p)
{
    if(p!=NULL)
    {
        inorder(p->lchild);
        printf("%c",p->data);
        inorder(p->rchild);
    }
}



void preorder(NODE *p)
{
    if(p!=NULL)
    {
        printf("%c",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}



void postorder(NODE *p)
{
    if(p!=NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%c",p->data);
    }
}


