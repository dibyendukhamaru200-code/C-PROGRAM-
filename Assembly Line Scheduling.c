#include <stdio.h>

// Function to find minimum
int min(int a, int b){
    return (a < b) ? a : b;
}

int main(){
    int n = 6;

    // Processing time
    int a1[] = {10, 12, 6, 7, 11, 2};
    int a2[] = {11, 8, 9, 7, 8, 1};

    // Transfer time
    int t1[] = {2, 3, 1, 3, 4};
    int t2[] = {2, 1, 2, 2, 1};

    // Entry time
    int e1 = 3, e2 = 5;

    // DP arrays
    int f1[6], f2[6];

    // Initialization
    f1[0] = e1 + a1[0];
    f2[0] = e2 + a2[0];

    // DP calculation
    for(int i = 1; i < n; i++){
        f1[i] = min(f1[i-1] + a1[i],
                    f2[i-1] + t2[i-1] + a1[i]);

        f2[i] = min(f2[i-1] + a2[i],
                    f1[i-1] + t1[i-1] + a2[i]);
    }

    // Final result
    int result = min(f1[n-1], f2[n-1]);

    printf("Min cost = %d\n", result);

    return 0;
}
