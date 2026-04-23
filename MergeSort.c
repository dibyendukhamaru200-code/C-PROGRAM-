#include <stdio.h>

// Merge function with step output
void merge(int arr[], int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    printf("\nMerging from index %d to %d\n", left, right);

    printf("Left Array: ");
    for(int i = 0; i < n1; i++)
        printf("%d ", L[i]);

    printf("\nRight Array: ");
    for(int j = 0; j < n2; j++)
        printf("%d ", R[j]);
    printf("\n");

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2) {

        printf("Comparing %d and %d\n", L[i], R[j]);

        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    printf("Array after merge: ");
    for(int x = left; x <= right; x++)
        printf("%d ", arr[x]);
    printf("\n");
}

// Merge Sort with divide output
void mergeSort(int arr[], int left, int right) {

    if(left < right) {

        int mid = (left + right) / 2;

        printf("\nDividing from index %d to %d\n", left, right);

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {

    int arr[] = {15, 5, 24, 8, 1, 3, 16, 10};
    int n = 8;

    mergeSort(arr, 0, n - 1);

    printf("\nFinal Sorted Array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
