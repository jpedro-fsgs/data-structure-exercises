#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define INITIAL_CAPACITY 4

typedef struct {
    int *data;
    int head;
    int size;
    int capacity;
} Queue;

Queue* create_queue(){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = INITIAL_CAPACITY;
    queue->data = (int *)malloc(sizeof(int) * INITIAL_CAPACITY);
    queue->head = 0;
    queue->size = 0;
    return queue;
}

bool resize_queue(Queue *queue){
    int new_capacity = queue->capacity * 2;
    int *temp = realloc(queue->data, sizeof(int) * new_capacity);
    if(temp == NULL){
        printf("Reallocation Failed.\n");
        return false;
    }
    queue->capacity = new_capacity;
    queue->data = temp;
    return true;
}

void add_fila(Queue *queue, int n){
    if(queue->size == queue->capacity){
        if(!resize_queue(queue)) return;
    }
    queue->data[queue->size] = n;
    queue->size++;
}

void remove_fila(Queue *queue){
    if(queue->size - queue->head > 0){
        queue->head++;
    }
}

void print_fila(Queue *queue){
    if(queue->size - queue->head == 0){
        printf("| Empty Queue |\n");
        return;
    }
    for(int i=queue->head; i<queue->size; i++){
        printf("| %d ", queue->data[i]);
    }
    printf("|\n");
}

int main() {
    int choice, value;
    Queue *queue = create_queue();

    while (1) {
        printf("\033[H\033[J"); // Limpa toda a tela
        print_fila(queue);
        printf("\n1. Add to queue\n");
        printf("2. Remove from queue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                add_fila(queue, value);
                break;
            case 2:
                remove_fila(queue);
                break;
            case 3:
                free(queue->data);
                free(queue);
                printf("\033[H\033[J");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}