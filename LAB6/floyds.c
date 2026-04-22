#include<stdio.h>
#define INF 99999

#define MAX 10

int main(){
    int n,k,i,j;

    int graph[MAX][MAX],dist[MAX][MAX];

    printf("enter the number of vertices:\n");
    scanf("%d",&n);

    printf("enter %d for infinity in the adjacency matrix\n",INF);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
            dist[i][j]=graph[i][j];
        }
    }

    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if (dist[i][k]+dist[k][j] < dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }


    printf("shortest distance matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(dist[i][j]==INF){
                printf("INF\t");
            }else{
                printf("%d\t",dist[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
