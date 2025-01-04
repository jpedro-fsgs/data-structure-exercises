#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *prt;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    prt = (int *)malloc(n * sizeof(int));

    if (prt == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Memory allocation successful\n");

    for (int i = 0; i < n; i++){
        int input;
        printf("Enter the value for element %d: ", i);
        scanf("%d", &input);
        prt[i] = input;
    }

    printf("Elements: ");

    int i;
    for (i = 0; i < n - 1; i++){
        printf("%d, ", prt[i]);
    }
    printf("%d.\n", prt[i]);

    free(prt);

    return 0;
}