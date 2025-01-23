#include<stdio.h>
#include<stdlib.h>

#define CAPACITY 100

typedef struct{
    int val;
    char *key;
} Data;


typedef struct{
    Data *table;
    int size;
    int capacity;
} HashTable;

HashTable* create_table(){
    HashTable *hashTable = malloc(sizeof(HashTable));
    hashTable->table = malloc(sizeof(Data) * CAPACITY);
    hashTable->capacity = CAPACITY;
    hashTable->size = 0;

    return hashTable;
}

unsigned long hash(char *value){
    unsigned long i = 0;

    for(int j=0; value[j]; j++){
        i += value[j];
    }

    return i % CAPACITY;
}

void add(HashTable *hashTable, char *newKey, int value){
    if(value == 0) return;
    int pos = hash(newKey);
    while(hashTable->table[pos].key != NULL){
        if(hashTable->table[pos].key == newKey) return;
        if(pos > hashTable->capacity) exit(1);
        pos++;
    }
    Data data;
    data.key = newKey;
    data.val = value;

    hashTable->table[pos] = data;
}

int get(HashTable *hashTable, char *newkey){
    int pos = hash(newkey);
    while(hashTable->table[pos].key != newkey){
        if(hashTable->table[pos].key == NULL){
            return -1;
        }
    }

    return hashTable->table[pos].val;
}


int main() {
    HashTable *table = create_table();
    char key[100];
    int value;
    int choice;

    while (1) {
        // printf("\033[H\033[J");
        printf("_____________________\n");
        printf("Escolha uma opção:\n");
        printf("1. Adicionar elemento\n");
        printf("2. Obter elemento\n");
        printf("3. Sair\n");
        printf("Digite sua escolha: ");
        scanf("::%d", &choice);

        if (choice == 1) {
            printf("Digite a chave: ");
            scanf("%s", key);
            printf("Digite o valor: ");
            scanf("%d", &value);
            add(table, key, value);
            printf("Elemento adicionado com sucesso!\n");
        } else if (choice == 2) {
            printf("Digite a chave: ");
            scanf("%s", key);
            int result = get(table, key);
            if (result != -1) {
                printf("Valor: %d\n", result);
            } else {
                printf("Chave não encontrada.\n");
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("Escolha inválida. Tente novamente.\n");
        }
    }

    return 0;
}