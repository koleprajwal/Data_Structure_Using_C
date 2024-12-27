#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int low, int mid, int high)
{
    int i = low, k = low, j = mid + 1;
    int b[high];

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        for (int z = j; z <= high; z++)
        {
            b[k] = a[z];
            k++;
        }
    }
    else
    {
        for (int z = i; z <= mid; z++)
        {
            b[k] = a[z];
            k++;
        }
    }

    for (int z = low; z <= high; z++)
    {
        a[z] = b[z];
    }
}

void MergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(a, low, mid);       // Sort left half
        MergeSort(a, mid + 1, high);  // Sort right half
        merge(a, low, mid, high);     // Merge the sorted halves
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int low = 0, high = n - 1;
    MergeSort(a, low, high);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}







