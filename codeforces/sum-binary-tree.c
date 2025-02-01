#include<stdio.h>


int main(){

    int n;
    scanf("%d", &n);

    long long int p[n];
    for (int i=0; i<n; i++) {
        scanf("%lld", &p[i]);
    }

    for(int i=0; i<n; i++){
        long long int sum=0;
        for(long long int j=p[i]; j>=1; j/=2){
            sum += j;
        }
        printf("%lld\n", sum);
    }

}


