#include<stdio.h>

void search(int *routers, int n){
    if(routers[n] != 1){
        search(routers, routers[n]-1);
    }
    printf("%d ", routers[n]);
}

int main(){
    int n;
    scanf("%d", &n);
    int routers[n];
    for(int i=1; i<n; i++){
        scanf("%d", &routers[i]);
    }

    search(routers, n-1);
    printf("%d ", n);

} 