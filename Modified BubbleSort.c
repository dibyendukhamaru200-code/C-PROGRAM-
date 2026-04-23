#include <stdio.h>

int main() {
    int arr[100], n, i, j, temp;
    int flag;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Modified Bubble Sort
    for(i = 0; i < n - 1; i++) {

        flag = 0;  // reset flag
        printf("\nPass %d:\n", i + 1);

        for(j = 0; j < n - i - 1; j++) {

            printf("Comparing %d and %d\n", arr[j], arr[j + 1]);

            if(arr[j] > arr[j + 1]) {

                printf("Swapping %d and %d\n", arr[j], arr[j + 1]);

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                flag = 1;  // swap happened
            }
        }

        printf("Array after Pass %d: ", i + 1);
        for(int k = 0; k < n; k++)
            printf("%d ", arr[k]);
        printf("\n");

        // If no swap happened, array is sorted
        if(flag == 0) {
            printf("No swapping in this pass → Array already sorted\n");
            break;
        }
    }

    printf("\nFinal Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
