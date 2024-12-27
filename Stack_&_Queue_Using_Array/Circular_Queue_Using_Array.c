#include<stdio.h>

void main()
{
    int n, i, ch;
    int a[5];
    int front = -1, rear = -1;

    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: 
                if((front == 0 && rear == 4) || (rear + 1) % 5 == front)
                    printf("Circular Queue Overflow");
                else
                {
                    if(front == -1)
                    {
                        front = 0;
                        rear = 0;
                    }
                    else
                        rear = (rear + 1) % 5;
                    printf("Enter the element to be inserted: ");
                    scanf("%d", &a[rear]);
                }
                break;

            case 2:
                if(front == -1)
                    printf("Circular QUEUE Underflow");
                else if(front == rear)
                {
                    printf("%d is Dequed", a[front]);
                    front = -1;
                    rear = -1;
                }
                else
                {
                    printf("%d is Dequed", a[front]);
                    front = (front + 1) % 5;
                }
                break;

            case 3: 
                if(front == -1)
                    printf("Circular Queue is Empty");
                else
                {
                    i = front;
                    while(i != rear)
                    {
                        printf("%d ", a[i]);
                        i = (i + 1) % 5;
                    }
                    printf("%d\n", a[rear]); // print the last element
                }
                break;

            case 4: 
                break;

            default: 
                printf("Invalid Choice");
        }

    } while (ch != 4);
}

