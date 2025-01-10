#include<stdio.h>
#include<stdlib.h>

int sum(int* numbers, int length){
    int sum = 0;
    for(int i=0; i<length; i++){
        sum += numbers[i];
    }
    return sum;
}

int main(){
    int* numbers;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    numbers = (int *)malloc(n * sizeof(int));

    if(numbers == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++){
        int input;
        printf("Enter the value for element %d: ", i);
        scanf("%d", &input);
        numbers[i] = input;
    }

    printf("The sum of the numbers is: %d\n", sum(numbers, n));

    free(numbers);

    return 0;
}