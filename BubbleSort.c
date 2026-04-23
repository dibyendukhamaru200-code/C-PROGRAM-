#include <stdio.h>

int main() {
    int arr[100], n, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble Sort with Step Output
    for(i = 0; i < n - 1; i++) {

        printf("\nPass %d:\n", i + 1);

        for(j = 0; j < n - i - 1; j++) {

            printf("Comparing %d and %d\n", arr[j], arr[j + 1]);

            if(arr[j] > arr[j + 1]) {

                printf("Swapping %d and %d\n", arr[j], arr[j + 1]);

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        printf("Array after Pass %d: ", i + 1);
        for(int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    printf("\nFinal Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
