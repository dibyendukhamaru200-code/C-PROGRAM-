#include <stdio.h>

// Function for Insertion Sort with Step Output
void insertionSort(int arr[], int n) {
    int i, j, key;

    for(i = 1; i < n; i++) {

        key = arr[i];
        j = i - 1;

        printf("\nPass %d:\n", i);
        printf("Key = %d\n", key);

        // Move elements greater than key
        while(j >= 0 && arr[j] > key) {
            printf("Shifting %d to position %d\n", arr[j], j + 1);
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        // Print array after each pass
        printf("Array after Pass %d: ", i);
        for(int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

int main() {
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("\nFinal Sorted array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
