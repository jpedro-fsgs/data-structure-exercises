#include<stdio.h>

int maxDepth(int *employees, int index){
    int depth = 1;
    while(employees[index] != -1){
        depth++;
        index = employees[index] - 1;
    }
    return depth;
}

int main(){
    int n;
    scanf("%d", &n);

    int employees[n], max=0;


    for(int i=0; i<n; i++){
        scanf("%d", &employees[i]);
    }


    for(int i=0; i<n; i++){
        int depth = 1, index=i;
        while(employees[index] != -1){
            depth++;
            index = employees[index] - 1;
        }
        if(depth > max) max = depth;
    }

    printf("%d", max);
}
