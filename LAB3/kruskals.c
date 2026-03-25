#include <stdio.h>

#define INF 999

int parent[10];

int find(int i) {
    while(parent[i])
        i = parent[i];
    return i;
}

int unionSet(int i, int j) {
    if(i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

void kruskal(int n, int cost[10][10]) {
    int i, j, min, u, v, a, b;
    int ne = 0, mincost = 0;

    while(ne < n-1) {
        min = INF;

        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(unionSet(u, v)) {
            printf("Edge %d: (%d -> %d) = %d\n", ne+1, a, b, min);
            mincost += min;
            ne++;
        }

        cost[a][b] = cost[b][a] = INF;
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

    kruskal(n, cost);

    return 0;
}

