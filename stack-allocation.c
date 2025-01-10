#include<stdio.h>
#include<stdlib.h>

int *pPilha = NULL;
int size = 0;

void add_pilha(int n){
    pPilha = realloc(pPilha, sizeof(int) * size + 1);
    if(pPilha == NULL){
        printf("Erro 2");
        exit(1);
    }
    pPilha[size] = n;
    size++;
}

void remove_pilha(){
    if(!size) return;
    pPilha = realloc(pPilha, sizeof(int) * size - 1);
    if(pPilha == NULL){
        printf("Erro 3");
        exit(1);
    }
    size--;
}

void print_pilha(){
    if(!size) {
        printf("| Empty Stack |\n");
        return;
    }
    for(int i=0; i<size; i++){
        printf("| %d ", pPilha[i]);
    }
    printf("|\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\033[H\033[J"); // Limpa toda a tela
        print_pilha();
        printf("\n1. Add to stack\n");
        printf("2. Remove from stack\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                add_pilha(value);
                break;
            case 2:
                remove_pilha();
                break;
            case 3:
                free(pPilha);
                printf("\033[H\033[J");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}