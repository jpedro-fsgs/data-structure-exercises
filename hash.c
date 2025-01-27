#include<stdio.h>
#include<stdlib.h>

#define CAPACITY 100

typedef struct{
    int val;
    char *key;
} Data;


typedef struct{
    Data **table;
    int size;
    int capacity;
} HashTable;

HashTable* create_table(){
    HashTable *hashTable = malloc(sizeof(HashTable));
    hashTable->table = malloc(sizeof(Data*) * CAPACITY);
    hashTable->capacity = CAPACITY;
    hashTable->size = 0;

    return hashTable;
}

unsigned long hash(char *value){
    unsigned long i = 0;

    for(int j=0; value[j]; j++){
        i = i * 31 + value[j];
    }

    return i % CAPACITY;
}

int add(HashTable *hashTable, char *newKey, int value){

    if(hashTable->size == hashTable->capacity){
        return -1;
    }
    int pos = hash(newKey);
    while(hashTable->table[pos]!= NULL){
        pos++;
    }
    Data *data = malloc(sizeof(Data));
    if(data == NULL) return -1;
    data->key = newKey;
    data->val = value;

    hashTable->table[pos] = data;
    hashTable->size++;
    return 1;

}

int get(HashTable *hashTable, char *newkey){
    int pos = hash(newkey);
    while(hashTable->table[pos]->key != newkey){
        pos++;
    }

    return hashTable->table[pos]->val;
}

void free_hash_table(HashTable *table){
    for(int i=0; i<CAPACITY; i++){
        if(table->table[i] != NULL){
            free(table->table[i]);
        }
    }
    free(table);
}


int main() {
    HashTable *table = create_table();
    add(table, "teste", 45);
    add(table, "teset", 46);
    printf("teste: %d\n", get(table, "teste"));
    printf("teset: %d\n", get(table, "teset"));

    printf("___________\n");
    for(int i=0; i<CAPACITY; i++){
        if(table->table[i] != NULL){
            printf("%p %s: %d\n",table->table[i], table->table[i]->key, table->table[i]->val);
        }
    }

    free_hash_table(table);
    return 0;
}