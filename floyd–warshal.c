#include<stdio.h>

#define INF 99999


int main() {

    int v = 5;

    int graph[5][5] = {
        {0, -5, INF, 14, INF},
        {INF, 0, 3, INF, INF},
        {INF, INF, 0, INF, -4},
        {INF, INF, -1, 0, INF},
        {2, INF, 12, INF, 0}
    };

    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(graph[i][k] != INF && graph[k][j] != INF){
                    if(graph[i][j] > graph[i][k] + graph[k][j]){
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (graph[i][j] == INF)
                printf("  INF");
            else
                printf("%4d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}