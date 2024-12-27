#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, ch, i, key;
    int* arr;
    int flag = 0;


    do {

        printf("\n1.Search\n2.Exit\n");

        printf("Enter Your Choice:");
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


            for (i = 0; i < n; i++) 
            {
                if (key == arr[i]) 
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 1) 
            {
                printf("\nSearch is Successful Element is at location: %d",i + 1);
            } 
            
            else 
            {
                printf("\nUnsuccessful Search");
            }

            free(arr);

                        break;

        case 2: break;

        default: printf("\nInvalid Choice.");

        }

    }while(ch!=2);

    return 0;
}




