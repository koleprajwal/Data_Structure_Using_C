#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,ch,key;
    int *arr;
    int flag = 0;
    int low,high,mid;


    do
    {
        printf("\n1.Binary Search\n2.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:

                    printf("Enter the size of Array: ");
                    scanf("%d", &n);
                    printf("\n");

                    arr = (int*)malloc(n * sizeof(int));

                    if (arr == NULL) 
                    {
                        printf("Memory allocation failed!\n");
                        return 1;
                    }

                    for (i = 0; i < n; i++) 
                    {
                        printf("Enter %d element in Array: ", i + 1);
                        scanf("%d", &arr[i]);
                    }

                    printf("Enter the Key element which You want to Search: ");
                    scanf("%d", &key);

                    low = 0;
                    high = n - 1;

                    while(low <= high)
                    {
                        mid = (low + high) / 2;

                        if(key == arr[mid])
                        {
                            flag = 1;
                            break;
                        }

                        else if(key < arr[mid])
                        {
                            high = mid - 1; 
                        }
                        else
                        {
                            low = mid + 1;
                        }
                    }

                    if (flag == 1) 
                    {
                        printf("\nSearch is Successful Element is at location: %d", mid + 1); 
                    } 
                    else 
                    {
                        printf("\nUnsuccessful Search");
                    }

                    free(arr);


                      break;


            case 2:   break;

            default: printf("Invalid Choice");
        }

    } while (ch!=2);

    return 0;
}
