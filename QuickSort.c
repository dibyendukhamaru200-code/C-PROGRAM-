#include <stdio.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition with Step Output
int partition(int arr[], int low, int high) {

    int pivot = arr[high];
    printf("\nPartitioning from index %d to %d\n", low, high);
    printf("Pivot = %d\n", pivot);

    int i = low - 1;

    for(int j = low; j < high; j++) {

        printf("Comparing %d with pivot %d\n", arr[j], pivot);

        if(arr[j] < pivot) {
            i++;
            printf("Swapping %d and %d\n", arr[i], arr[j]);
            swap(&arr[i], &arr[j]);
        }
    }

    printf("Placing pivot at correct position\n");
    swap(&arr[i + 1], &arr[high]);

    printf("Array after partition: ");
    for(int k = 0; k <= high; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");

    return (i + 1);
}

// Quick Sort with Step Output
void quickSort(int arr[], int low, int high) {

    if(low < high) {

        int pi = partition(arr, low, high);

        printf("Pivot positioned at index %d\n", pi);

        printf("Left side recursion (%d to %d)\n", low, pi - 1);
        quickSort(arr, low, pi - 1);

        printf("Right side recursion (%d to %d)\n", pi + 1, high);
        quickSort(arr, pi + 1, high);
    }
}

int main() {

    int arr[] = {34, 7, 23, 32, 5, 62};
    int n = 6;

    quickSort(arr, 0, n - 1);

    printf("\nFinal Sorted Array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
