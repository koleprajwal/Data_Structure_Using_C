#include<stdio.h>

int main()
{	
	int n;
	int a[5];
	int top=-1;
	int i,ch;
	
	do 
	{
		printf("\n1.PUSH\n2.POP\n3.Top of Stack\n4.Traverse\n5.Exit\n");
		printf("Enter Choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: if(top==4)
					printf("Stack Overflow");
	
					else
					{
						top=top+1;
						printf("Enter Data:");
						scanf("%d",&a[top]);
					}
					
					break;
			
			case 2: if(top==-1)
					printf("Stack Underflow");
					
					else
					{
						printf("%d is Popped",a[top]);
						top=top-1;
					}
					
					break;
			
			case 3: if(top==-1)
					printf("Stack is Empty");
					
					else
					printf("%d is Top of Stack",a[top]);
					break;
			
			case 4: if(top==-1)
					printf("Stack Underflow");
					
					else
					{
						for(i=0;i<=top;i++)
						printf("%d\n",a[i]);
					}
					break;
					
			case 5: 
					break;
					
			default : printf("Invalid Choice\n");
					break;
		}			
	}while(ch!=5);
		
return 0;	
}
