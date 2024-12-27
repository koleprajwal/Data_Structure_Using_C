//Insertion Sort



#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,n,j,ch,temp;
    int *arr;

    do
    {
        printf("\n1.Insertion Sort\n2.Exit\n");

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
                    temp=arr[i];

                    j=i-1;

                    while(temp<arr[j] && j>=0)
                    {
                        arr[j+1]=arr[j];
                        j--;
                    }
                    arr[j+1]=temp;
                }
				
				printf("Soretd Elements in array are:");
				
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
