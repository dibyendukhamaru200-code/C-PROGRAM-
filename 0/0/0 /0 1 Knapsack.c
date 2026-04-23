#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n = 4;
    int W = 8;   // max weight (from your class table style)

    int wt[] = {0, 1, 3, 5, 7};
    int val[] = {0, 2, 4, 7, 10};

    int dp[5][9];

    // Initialize
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
        }
    }

    // Fill table
    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= W; w++) {

            if(wt[i] <= w) {
                dp[i][w] = max(dp[i-1][w],
                               dp[i-1][w - wt[i]] + val[i]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    // Print DP Table
    printf("\nKnapsack Table:\n\n");

    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            printf("%d\t", dp[i][w]);
        }
        printf("\n");
    }

    printf("\nMaximum Profit = %d\n", dp[n][W]);

    return 0;
}
