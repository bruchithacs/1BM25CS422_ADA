#include <stdio.h>

#define INF 999

void prim(int n, int cost[10][10]) {
    int visited[10] = {0};
    int i, j, min, u, v;
    int ne = 0, mincost = 0;

    visited[1] = 1;

    while(ne < n-1) {
        min = INF;

        for(i = 1; i <= n; i++) {
            if(visited[i]) {
                for(j = 1; j <= n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("Edge %d: (%d -> %d) = %d\n", ne+1, u, v, min);
        mincost += min;
        visited[v] = 1;
        ne++;
    }

    printf("Minimum cost = %d\n", mincost);
}

int main() {
    int n, cost[10][10], i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    prim(n, cost);

    return 0;
}
