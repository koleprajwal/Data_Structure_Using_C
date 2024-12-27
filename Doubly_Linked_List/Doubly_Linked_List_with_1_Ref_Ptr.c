//Doubly Linked List with one Reference pointer.


#include<stdio.h>
#include<stdlib.h>

	struct node 
				{
					int data;
					struct node *next;
                    struct node *prev;
				};
 typedef struct node NODE;
 NODE *start =NULL,*p,*q;
 
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
    p=(NODE *)malloc(sizeof(NODE));
    scanf("%d",&p->data);

    if (start==NULL)
    {
        start=p;
        p->next=NULL;
        p->prev=NULL;
    }

    else
    {
        p->next=start;
        p->prev=NULL;
        start->prev=p;
        start=p;
    }
}

void Createatend()
{
    p=(NODE *)malloc(sizeof(NODE));
    scanf("%d",&p->data);

    if (start==NULL)
    {
        p->next=NULL;
        p->prev=NULL;
        start=p;
    }
    
    else
    {
    	q=start;
    	while(q->next!=NULL)
    	{
    		q=q->next;
		}
		q->next=p;
		p->prev=q;
		p->next=NULL;
	}
}


void Createatgivenlocation()
{	
	int i, loc;
	
	printf("Enter Location:");
    scanf("%d",&loc);
    
	printf("Enter Data:");
    p=(NODE *)malloc(sizeof(NODE));
    scanf("%d",&p->data);
       
    if (start==NULL)
    {
    	if(loc==1)
    	{
    		p->next=NULL;
    		p->prev=NULL;
    		start=p;
		}
		
		else
		{
			printf("Invalid Location");
			free(p);
		}
	}
	
	else
	{
		if (loc==1)
		{
			p->next=start;
			start->prev=p;
			p->prev=NULL;
			start=p;
		}
		
		else
		{
			i=1;
			q=start;
			
			while(i<loc-1 && q!=NULL)
			{
				q=q->next;
				i++;
			}
			
			if(q!=NULL)
			{
				p->next=q->next;
				if(q->next!=NULL)
				{
					q->next->prev=p;
				}
				p->prev=q;
				q->next=p;
			}
			
			else
			{
				printf("Invalid Location");
				free(p);
			}	
		}		
	}   
}









void Deleteatstart()
{
    if(start==NULL)
    {
        printf("Linked List is Empty Delete cannot be Performed...");
    }

    else
    {
        p=start;
        start=start->next;
        if(start->next!=NULL)
        {
            start->prev=NULL;
        }
        printf("%d is Deleted",p->data);
        free(p);
    }
}


void Deleteatend()
{
   if(start==NULL)
   {
   	 printf("LL is Empty Delete cannot be performed");
   }
   
   else if (start->next==NULL)
   {
     p=start;
     start=NULL;
     printf("%d is Deleted",p->data);     
     free(p);
   }
   
   else
   {
   	p=start;
   	while(p->next!=NULL)
   	{
	  q=p;
	  p=p->next;	
	}
	q->next=NULL;
	printf("%d is Deleted",p->data);
	free(p);
   }
}


void Deleteatgivenlocation()
{
	int i,loc;
	
	printf("Enter Location You Want to Delete:");
	scanf("%d",&loc);
	
	if (start==NULL)
	{
		printf("Your LL is Empty Delete Cannot be Performed...");
	}
	
	
	
	else
	{
		if(loc==1)
		{
			p=start;
			start=start->next;
			if(start->next==NULL)
			{
				start->prev=NULL;
			}
			printf("%d is Deleted",p->data);
			free(p);	
		}
		
		else
		{
			i=1;
			p=start;
			
			while(i<loc && p!=NULL)
			{
				p=p->next;
				i++;
			}
			
			if(p!=NULL)
			{
				p->prev->next=p->next;
				if(p->next!=NULL)
				{
					p->next->prev=p->prev;
				}
				
			printf("%d is Deleted",p->data);
			free(p);
			}
		else
		{
			printf("Invalid loc");
		}
		}		
	}
}



void Traverse()
{
    if (start==NULL)
    {
        printf("Linked List is Empty...");
    }

    else
    {
        q=start;
        while(q!=NULL)
        {
			printf("<-%d->",q->data);
			q=q->next;
	    }
    }
}

