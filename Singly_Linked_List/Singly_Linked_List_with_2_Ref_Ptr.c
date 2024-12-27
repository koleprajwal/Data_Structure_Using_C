/*
Write a program to perform create at start, create at end, create at given location, delete at start, delete at end,
  delete at given location and traverse for a singly linked list with two external reference pointers start and last.
*/


#include<stdio.h>
#include<stdlib.h>

	struct node 
				{
					int data;
					struct node *next;
				};
 typedef struct node NODE;
 NODE *start =NULL,*last=NULL,*p,*q;
 
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
	
	if(start==NULL)
	{
		p->next=NULL;
		start=p;
		last=p;
	}	
	else
	{
		p->next=start;
		start=p;
	}		
}


void Createatend()
{
	p=(NODE *)malloc(sizeof(NODE));
	scanf("%d",&p->data);
	if(start==NULL)
	{
		p->next=NULL;
		start=p;
		last=p;
	}
	else
	{
		last->next=p;
		p->next=NULL;
		last=p;		
	}
}


void Createatgivenlocation()
{
	int loc,i;
	
	scanf("%d",&loc);
	p=(NODE *)malloc(sizeof(NODE));
	scanf("%d",&p->data);
	
	if(start==NULL)
	{
		if(loc==1)
		{
			p->next=NULL;
		start=p;
		last=p;	
		}
		else
		{
			printf("Invalid Location");
		}
	}
	
	else
	{
		if(loc==1)
		{
				p->next=start;
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
				q->next=p;	
				if(p->next==NULL)
				last=p;
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
		printf("LL is Empty");
	}
	else if(start->next==NULL)
	{
		p=start;
		printf("%d is deleted",p->data);
		start=NULL;
		last=NULL;
		free(p);
	}
	else
	{
		p=start;
		start=start->next;
		printf("%d is deletd",p->data);
		free(p);	
	}	
}



void Deleteatend()
{
	if(start==NULL)	
		printf("\n LL is Empty");
		
	else if (start->next==NULL)
	{
		p=start;
		start=NULL;
		last=NULL;
		printf("%d is Deleted",p->data);
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
		printf("%d is Deleted",p->data);
		last=q;
		q->next=NULL;
		free(p);
	}
}


void Deleteatgivenlocation()
{
	int i,loc;
	printf("Enter location :");
	scanf("%d",&loc);
	
	if(start==NULL)
	printf("\nLL is Empty");
	
	
	else if(start->next==NULL)
		{
			p=start;
			start=NULL;
			last=NULL;
			printf("%d is Deleted",p->data);
			free(p);
		}
	
	else
	{
		if (loc==1)
		{
			p=start;
			start=start->next;
			printf("%d is Deleted",p->data);
			free(p);
		}
		
		
		
		else 
		{
			i=1;
			p=start;
			while(i<loc && p!=NULL)
			{
				q=p;
				p=p->next;
				i++;
			}
			if(p!=NULL)
			{
				q->next=p->next;
				printf("%d is Deleted",p->data);
				free(p);
				
				if(q->next==NULL)
				last=q;
				
			}
			else 
			{
				printf("Invalid Location");
			}
		}		
	}
}



void Traverse()
{
	if(start==NULL)
	{
		printf("\n LL is empty");
	}
	else
	{
		q=start;
		while(q!=NULL)
		{
			printf("%d\t",q->data);
			q=q->next;
	    }
			
		
	}
	
}

