#include<stdio.h>
#include<stdlib.h>

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while(i <= j) {
        while(i <= high && a[i] < pivot) {
            i++;
        }
        
        while(a[j] > pivot) {
            j--;
        }
        
        if(i < j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }
    swap(&a[j], &a[low]);
    return j;
}

void quicksort(int a[], int low, int high) {
    if(low < high) {
        int j = partition(a, low, high);
        quicksort(a, low, j - 1);  // Recursively sort the left subarray
        quicksort(a, j + 1, high); // Recursively sort the right subarray
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int low = 0, high = n - 1;
    quicksort(a, low, high);

    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

