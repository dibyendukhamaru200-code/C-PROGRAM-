#include <stdio.h>

// Recursive Binary Search with Step Output
int binarySearch(int arr[], int left, int right, int key) {

    if (left <= right) {

        int mid = (left + right) / 2;

        printf("Searching in range index %d to %d\n", left, right);
        printf("Middle index = %d, Element = %d\n", mid, arr[mid]);

        if (arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            return mid;
        }

        else if (key < arr[mid]) {
            printf("Going to LEFT half\n\n");
            return binarySearch(arr, left, mid - 1, key);
        }

        else {
            printf("Going to RIGHT half\n\n");
            return binarySearch(arr, mid + 1, right, key);
        }
    }

    return -1;
}

int main() {

    int arr[] = {5, 10, 15, 20, 25, 30};
    int n = 6;
    int key = 20;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        printf("Final Result: Element %d found at position %d\n", key, result + 1);
    else
        printf("Final Result: Element %d not found\n", key);

    return 0;
}
