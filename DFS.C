#include <stdio.h>

int main() {
    int g[10][10], visited[10] = {0};
    int stack[10], top = -1;
    int n, i, j, start, node;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    printf("Enter starting node: ");
    scanf("%d", &start);

    // Step 1: Push start node
    stack[++top] = start;

    printf("DFS: ");

    while(top != -1) {
        node = stack[top--];   // Pop

        if(visited[node] == 0) {
            printf("%d ", node);
            visited[node] = 1;

            // Push neighbors
            for(i = 0; i < n; i++) {
                if(g[node][i] == 1 && visited[i] == 0) {
                    stack[++top] = i;
                }
            }
        }
    }

    return 0;
}
