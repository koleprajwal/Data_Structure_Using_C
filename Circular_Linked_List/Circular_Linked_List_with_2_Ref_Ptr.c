#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
NODE *start=NULL,*last=NULL,*p,*q;

void Createatstart();
void Createatend();
void Createatgivenlocation();
void Deleteatstart();
void Deleteatend();
void Deleteatgivenlocation();
void Traverse();

int main()
{
  int ch;				
	
	do{	
	printf("\n1.Create at Start\n2.Create at End\n3.Create at Given Location\n4.Delete at Start\n5.Delete at End\n6.Delete at Given Location\n7.Traverse\n8.Exit\n");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1: Createatstart();
					break;
							
		case 2: Createatend();
					break;
							
		case 3: Createatgivenlocation();
					break;
							
		case 4: Deleteatstart();
					break;
		
		case 5: Deleteatend();
					break;
		
		case 6: Deleteatgivenlocation();
					break;
							
		case 7: Traverse();
					break;
					
		case 8:
					break;
	
		default: printf("Incorrect choice");
	}
	
      }while(ch!=8);
      
      return 0;
}

void Createatstart()
{
    p = (NODE *)malloc(sizeof(NODE));
    scanf("%d",&p -> data);

    if(start == NULL){
        p -> next = p;
        start = p;
        last = p;
    }
    else{
        p -> next = start;
        start = p;
        last -> next = start;
    }

}

void Createatend()
{
	p=(NODE *)malloc(sizeof(NODE));
	scanf("%d",&p->data);
	
	if (start==NULL)
	{
		p->next=p;
		start=p;
		last=p;
	}
	
	else
	{
		last->next=p;
		p->next=start;
		last=p;
	}	
}


void Createatgivenlocation(){
    int i,loc;
    
    printf("Enter the location you want to add data:");
    scanf("%d",&loc);

    p =(NODE*)malloc(sizeof(NODE));
    scanf("%d",&p -> data);
    
    if(start == NULL){
        if(loc == 1){
            p -> next = p;
            start = p;
            last = p;
        }
        else{
            printf("\nLinked List is empty\n");
            free(p);
        }
    }
    else{
        if(loc == 1){
            p -> next = start;
            start = p;
            last -> next = p;
        }
        else{
            q = start;
            for(i = 1;i < loc - 1 && q -> next != start; i++){
                q = q -> next;
            }
            if(i == loc -1){
                p -> next = q -> next;
                q -> next =p;
                if(q == last){
                    last = p;
                }
            }
            else{
                printf("\nYou entered the invalid location\n");
                free(p);
            }            
        }
    }
}




void Deleteatstart()
{
    if(start == NULL)
	{
        printf("Linked List is empty\n");
    }
    else if(start -> next == start)
	{
        p = start;
        start = NULL;
        last = NULL;
        printf("%d is deleted\n",p -> data);
        free(p);
    }
    else
	{
        p = start;
        start = start -> next;
        last -> next = start;
        printf("%d is deleted\n",p -> data);
        free(p);
    }
}



void Deleteatend()
{
	if (start==NULL)
	{
		printf("LL is Empty Delete cannot Be Performed");
	}
	
	else if(start->next==start)
	{
		p=start;
		start=NULL;
		last=NULL;
		printf("%d is Deleted\n",p->data);
		free(p);
	}
	
	else
	{
		p=last;
		q=start;
		
		while(q->next!=p)
		{
			q=q->next;
		}
		last=q;
		q->next=start;
		printf("%d is Deleted\n",p->data);
		free(p);
	}	
}



void Deleteatgivenlocation()
{
	int i,loc;
	
	printf("Enter Location:");
	scanf("%d",&loc);
	
	 if(start == NULL)
	 {
        printf("\nLinked list is empty\n");
    }
    else{
        if(loc == 1){
            if(start -> next == start){
                p = start;
                start = NULL;
                last = NULL;
                printf("%d  is deleted\n",p -> data);
                free(p);
            }
            else{
                p = start;
                start = start -> next;
                last -> next = start;
                printf("%d is deleted\n",p -> data);
                free(p);
            }
        }
        else{
            p = start;
            for(i = 1;i < loc && p -> next != start; i++){
                q = p;
                p = p -> next;
            }
            if(i == loc){
                q -> next = p -> next;
                while(p == last){
                    last = q;
                }
                printf("%d is deleted\n",p -> data);
                free(p);
            }
            else{
                printf("Enter a valid Location\n");
            }           
        }    
    }
}




void Traverse()
{
    if(start == NULL)
	{
        printf("\nYour linkedlist is empty\n");
    }
    else{
        q = start;
        do{
            printf("<-%d->",q -> data);
            q = q -> next;
        }while(q != start);
    }
}
