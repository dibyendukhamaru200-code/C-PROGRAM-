#include <stdio.h>

// Selection Sort with Step Output
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for(i = 0; i < n - 1; i++) {

        minIndex = i;
        printf("\nPass %d:\n", i + 1);
        printf("Assume %d is minimum\n", arr[minIndex]);

        // Find minimum element
        for(j = i + 1; j < n; j++) {
            printf("Comparing %d and %d\n", arr[j], arr[minIndex]);

            if(arr[j] < arr[minIndex]) {
                minIndex = j;
                printf("New minimum found: %d\n", arr[minIndex]);
            }
        }

        // Swap
        if(minIndex != i) {
            printf("Swapping %d and %d\n", arr[i], arr[minIndex]);
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        else {
            printf("No swapping needed\n");
        }

        // Print array after each pass
        printf("Array after Pass %d: ", i + 1);
        for(int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = 5;

    selectionSort(arr, n);

    printf("\nFinal Sorted Array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
