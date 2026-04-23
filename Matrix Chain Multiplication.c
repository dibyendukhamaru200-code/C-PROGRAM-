#include <stdio.h>
#include <limits.h>

int main() {
    int n = 4;

    int p[] = {5, 7, 9, 12, 15};

    int m[5][5];

    // Initialize
    for(int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    // Fill DP table
    for(int L = 2; L <= n; L++) {
        for(int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for(int k = i; k < j; k++) {
                int cost = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if(cost < m[i][j]) {
                    m[i][j] = cost;
                }
            }
        }
    }

    // Print ONLY upper triangle
    printf("\nDP Table:\n\n");

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {

            if(j < i)
                printf("\t");   // nothing below diagonal
            else
                printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\nMinimum cost = %d\n", m[1][n]);

    return 0;
}
