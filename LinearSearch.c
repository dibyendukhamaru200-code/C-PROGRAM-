//Linear Search using c programming 
#include <stdio.h>

// Linear Search Function with Step Output
int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {

        printf("Step %d: Checking element %d\n", i + 1, arr[i]);

        if(arr[i] == key) {
            printf("Element found at index %d\n", i);
            return i;      
        }
    }

    return -1;             
}

int main() {

    int arr[] = {12, 45, 7, 23, 9};   
    int n = 5;
    int key = 23;

    int result = linearSearch(arr, n, key);

    if(result != -1)
        printf("Final Result: Element %d found at position %d\n", key, result + 1);
    else
        printf("Final Result: Element %d not found\n", key);

    return 0;
}
