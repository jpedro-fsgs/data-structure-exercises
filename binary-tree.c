#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct{
    Node *root;
} Tree;

Tree* create_tree(){

    Tree *tree = (Tree*)malloc(sizeof(Tree));
    if(tree == NULL){
        printf("Error allocating tree.\n");
        return NULL;
    }
    tree->root = NULL;

    return tree;
}

void free_tree_nodes(Node *node) {
    if (node == NULL) return;
    free_tree_nodes(node->left);
    free_tree_nodes(node->right);
    free(node);
}

void free_tree(Tree *tree) {
    free_tree_nodes(tree->root);
    free(tree);
}

void add(Node *node, int n){
    if(n == node->val) return;
    if(n > node->val){
        if(node->right == NULL){
            Node *current = (Node*)malloc(sizeof(Node));
            if(current == NULL){
                printf("Error allocating node.\n");
                return;
            }
            current->val = n;
            current->left = NULL;
            current->right = NULL;
            node->right = current;
        } else {
            add(node->right, n);
        }
    } else {
        if(node->left == NULL){
            Node *current = (Node*)malloc(sizeof(Node));
            if(current == NULL){
                printf("Error allocating node.\n");
                return;
            }
            current->val = n;
            current->left = NULL;
            current->right = NULL;
            node->left = current;
        } else {
            add(node->left, n);
        }
    }

}

void add_tree(Tree *tree, int n){
    if(tree->root != NULL){
        add(tree->root, n);
    } else {
        Node *node = (Node*)malloc(sizeof(Node));
        if(node == NULL){
            printf("Error allocating node.\n");
            return;
        }
        node->val = n;
        node->left = NULL;
        node->right = NULL;

        tree->root = node;
    }
}

void print_tree(Tree *tree){
    if(tree->root == NULL){
        printf("Empty Tree.\n");
    } else {
        Node *queue[100];
        queue[0] = tree->root;
        int start=0, end=1;

        while(start < end){
            int j = end;
            for(int i=start; i<j; i++){
                start++;
                printf("%d ", queue[i]->val);
                if(queue[i]->left != NULL) queue[end++] = queue[i]->left;
                if(queue[i]->right != NULL) queue[end++] = queue[i]->right;
            }
            printf("\n");
        }

    }

    printf("_____________\n");
}

Node* remove_node(Node *current, int n) {
    if (current == NULL) return NULL;
    if (current->val == n) {
        if(current->left == NULL && current->right == NULL){
            free(current);
            return NULL;
        } else if(current->left == NULL || current->right == NULL){
            if(current->left != NULL){
                Node *temp = current->left;
                free(current);
                return temp;
            } else if(current->right != NULL){
                Node *temp = current->right;
                free(current);
                return temp;
            }
        } else {
            Node *temp = current->left;

            while(temp->right != NULL) temp = temp->right;

            current->val = temp->val;
            temp->val = n;

            current->left = remove_node(current->left, n);
            return current;
        }

    } else {
        if(n < current->val){
            current->left = remove_node(current->left, n);
        } else{
            current->right = remove_node(current->right, n);
        }
        return current;
    }
}

void remove_tree(Tree *tree, int n){
    if(tree == NULL) return;
    if(tree->root == NULL) return;
    if(tree->root->right == NULL && tree->root->left == NULL){
        free(tree->root);
        tree->root = NULL;
        return;
    }
    tree->root = remove_node(tree->root, n);
}

int get_height(Node *node){
    if(node == NULL) return 0;
    int left = get_height(node->left);
    int right = get_height(node->right);

    return (left > right ? left : right) + 1;

}

int main() {

    int value;
    Tree *tree = create_tree();

    while (1) {
        printf("\033[H\033[J");
        printf("Binary Tree: \n\n");
        print_tree(tree);
        printf("Height: %d\n", get_height(tree->root));
        printf("\nInsert a postive number to add it to the tree\n");
        printf("Insert a negative number to remove it from the tree\n\n::");

        scanf("%d", &value);

        if(value >= 0){
            add_tree(tree, value);
        } else {
            remove_tree(tree, value * -1);
        }
    }

    return 0;

}