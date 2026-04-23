#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char X[100], Y[100];

    printf("Enter first string: ");
    scanf("%s", X);

    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    int dp[m+1][n+1];

    // Step 1: Initialize
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    // Step 2: Fill DP table
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {

            if(X[i-1] == Y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Step 3: Print Table with Labels (Exam Style)
    printf("\nLCS Table:\n\n");

    // Print top header (Y string)
    printf("    ");
    for(int j = 0; j < n; j++) {
        printf("%c   ", Y[j]);
    }
    printf("\n");

    for(int i = 0; i <= m; i++) {

        // Print row label (X string)
        if(i == 0)
            printf("  ");
        else
            printf("%c ", X[i-1]);

        for(int j = 0; j <= n; j++) {
            printf("%d   ", dp[i][j]);
        }
        printf("\n");
    }

    // Final Answer
    printf("\nLength of LCS = %d\n", dp[m][n]);

    return 0;
}
