//Bubble Sort


#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,n,j,ch,temp;
    int *arr;

    do
    {
        printf("\n1.Bubble Sort\n2.Exit\n");

        printf("Enter Your Choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:

                printf("Enter the size of array:");
                scanf("%d",&n);

                arr = (int*)malloc(n * sizeof(int));

                if (arr == NULL) 
            {
                printf("Memory allocation failed!\n");
                return 1;
            }

                for(i=0;i<n;i++)
                {	
                	printf("Enter %d Element in Array:",i+1);
                	scanf("\t%d",&arr[i]);
                }
                
                printf("Elements in Array Before Bubble Sort are:");
                
                for(i=0;i<n;i++)
                {
                	printf("\t%d",arr[i]);
				}
				
				printf("\n");
				printf("\n");
				
				
                for(i=0;i<n-1;i++)
                {
                    for(j=0;j<n-i-1;j++)
                    {
                        if(arr[j]>arr[j+1])
                    {
                        temp=arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                    }
                    }   
                }



				
				printf("Elements in array After Bubble Sort are:");
				
				for(i=0;i<n;i++)
				{
					printf("\t%d",arr[i]);
				}
                        break;



            case 2:  break;

            default: printf("Invalid Choice");
        }

    } while (ch!=2);
    return 0;
}
