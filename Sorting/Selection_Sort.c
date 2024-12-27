//Selection Sort


#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,n,j,ch,temp,min;
    int *arr;

    do
    {
        printf("\n1.Selection Sort\n2.Exit\n");

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
                	scanf("%d",&arr[i]);
                }
                
                 printf("Elements in Array Before Selection Sort:");
                
                for(i=0;i<n;i++)
                {
                	printf("\t%d",arr[i]);
				}
				
				printf("\n");
				printf("\n");


                for(i=0;i<n-1;i++)
                {
                    min=i;

                    for(j=i+1;j<n;j++)
                    {
                        if(arr[j]<arr[min])
                        min=j;
                    } 
					if(i!=min)
                        {
                            temp=arr[min];
                            arr[min]=arr[i];
                            arr[i]=temp;
                        }  
                }


				printf("Elements in array after Selection Sort are:");
				
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
