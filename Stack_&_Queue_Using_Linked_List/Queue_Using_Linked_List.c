#include<stdio.h>
#include<stdlib.h>

struct queue {
    int data;
    struct queue * next;
};

typedef struct queue Queue;

Queue *front=NULL,*rear=NULL,*p,*q;

void Enqueue();
void Dequeue();
void Traverse();


int main()
{
    int ch;

    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Traverse\n4.Exit\n");

        printf("Enter Your Choice:");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:  Enqueue();
            break;

        case 2: Dequeue();
        break;

        case 3:  Traverse();
        break;

        default:
            break;
        }
          
    } while (ch!=4);
return 0;    
}


void Enqueue()
{
    printf("Enter Data Element:");
    p=(Queue *)malloc(sizeof(Queue));
    scanf("%d",&p->data);

    if(front==NULL)
    {
        front=rear=p;
        p->next=NULL;
    }

    else
    {
        rear->next=p;
        p->next=NULL;
        rear=p;
    }
}


void Dequeue()
{   
    if(front==NULL)
    {
        printf("Queue is Empty\n");
    }

    else if(front->next==NULL)
	{
		p=front;
		printf("%d is Removed from Queue\n",p->data);
		front=NULL;
		rear=NULL;
		free(p);
	}

    else
    {   
        p=front;
        front=front->next;
        printf("%d is Removed from Queue\n",p->data);
        free(p);
    }
    
}

void Traverse()
{
    if(front==NULL)
    {
        printf("Stack is Empty\n");
    }

    else{
    	q=front;
        while(q!=NULL)
        {
            printf("%d",q->data);
            q=q->next;
        }
    }
    printf("\n");
}
