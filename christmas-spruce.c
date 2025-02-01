#include<stdio.h>
#include<string.h>


int main(){
    int n;
    scanf("%d", &n);

    int adjacency[n][n];
    for(int i = 0; i < n; i++) {
        memset(adjacency[i], -1, sizeof(adjacency[i]));
    }

    for(int i=1; i<n; i++){
        int temp;
        scanf("%d", &temp);
        
        int index = 0;
        while(adjacency[temp-1][index] != -1) index++;
        adjacency[temp-1][index] = i;
        
    }

    int leafs[n];
    memset(leafs, 0, sizeof(leafs));

    for(int i=0; i<n; i++){
        if(adjacency[i][0] == -1){
            leafs[i] = 1;
        }
    }

    for(int i=0; i<n; i++){
        int count = 0;
        int index = 0;
        while(adjacency[i][index] != -1){
            if(leafs[adjacency[i][index]] == 1){
                count++;
            }
            index++;
        }
        if(leafs[i] == 0 && count < 3){
            printf("No");
            return 0;
        }
    }

    printf("Yes");
    return 0;

}