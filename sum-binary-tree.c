#include<stdio.h>


int main(){

    int n;
    scanf("%d", &n);

    unsigned long long p[n];
    for (int i=0; i<n; i++) {
        scanf("%lu", &p[i]);
    }

    for(int i=0; i<n; i++){
        unsigned long long sum=0;
        for(unsigned long long j=p[i]; j>=1; j/=2){
            sum += j;
        }
        printf("%lu\n", sum);
    }

}


