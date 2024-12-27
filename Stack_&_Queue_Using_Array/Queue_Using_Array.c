#include<stdio.h>


void main()
{
    int n,i,ch;
    int a[5];
    int front=-1,rear=-1;

    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: 
                    if(rear==4)
                    printf("QUEUE OVERFLOW\n");

                    else{
                    if(front==-1)
                    {
                        front=0;
                        rear=0;
                    }

                    else
                        rear=rear+1;
                        scanf("%d",&a[rear]);
                    }

                        break;


            case 2:
                    if(front==-1) 
                    printf("QUEUE UNDERFLOW\n");

                    else{

                        printf("%d dequed\n",a[front]);                        
                        front=front+1;
                        
                    if(front>rear)
                    {
                        front=-1;
                        rear=-1;
                    }
                                     
                    }

                        break;

            
            case 3: 
                    if(front==-1)
                    printf("Queue is Empty");

                    else
                    {
                    	
                    printf("Elements in Queue are:");
                    for(i=front; i<=rear; i++)
                        printf("%d\t",a[i]);
                    }

                        break;

            case 4:  break;


            default: printf("Invalid Choice");
        }

    }while (ch!=4);
    
}
