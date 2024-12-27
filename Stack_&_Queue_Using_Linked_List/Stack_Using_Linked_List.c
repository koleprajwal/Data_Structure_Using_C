#include<stdio.h>
#include<stdlib.h>

struct stack {
    int data;
    struct stack * next;
};

typedef struct stack Stack;

Stack *top=NULL,*p,*q;

void PUSH();
void POP();
void TOS();
void Traverse();


int main()
{
    int ch;

    do
    {
        printf("1.PUSH\n2.POP\n3.TOS\n4.Traverse\n5.Exit\n");

        printf("Enter Your Choice:");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:  PUSH();
            break;

        case 2: POP();
        break;

        case 3:  TOS();
        break;

        case 4:   Traverse();
        break;

        default:
            break;
        }
          
    } while (ch!=5);
return 0;    
}


void PUSH()
{
    printf("Enter Data:");

    p=(Stack *)malloc(sizeof(Stack));
    scanf("%d",&p->data);

    if(top==NULL)
	{
		p->next=NULL;
		top=p;
	}	
	else
	{
		p->next=top;
		top=p;     
	}		
}


void POP()
{
    if(top==NULL)
	{
		printf("Stack is Empty\n");
	}
	else if(top->next==NULL)
	{
		p=top;
		printf("%d is deleted\n",p->data);
		top=NULL;
		free(p);
	}
	else
	{
		p=top;
		top=top->next;
		printf("%d is deletd\n",p->data);
		free(p);	
	}
}

void TOS()
{   
    q=top;
    printf("Top element of stack is  %d\n",q->data);

}


void Traverse()
{

    if(top==NULL)
    {
        printf("Stack is Empty\n");
    }

    else{
    	q=top;
        while(q!=NULL)
        {
            printf("%d",q->data);
            q=q->next;
        }
    }
    printf("\n");
}
