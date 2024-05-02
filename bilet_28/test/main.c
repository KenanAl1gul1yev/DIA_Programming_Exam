#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int x;
    struct Node* next;
}Node;

void readFile(Node** root, char* name);
void show(Node* root);
void dealloc(Node** root);
int find_min(Node* root);
int find_max(Node* root);
void pop(Node** root, int value);

int main(){
    Node* root = NULL;

    readFile(&root, "vals.txt");
    pop(&root, find_min(root));
    pop(&root, find_max(root));
    show(root);
    dealloc(&root);

    return 0;
}

void readFile(Node** root, char* name){
    FILE* fptr = fopen(name, "r");

    if (fptr == NULL){
        printf("No such file .\n");
        exit(0);
    }

    int num;
    Node* curr = *root;
    while (fscanf(fptr, "%d", &num) != EOF){
        Node* new_node = malloc(sizeof(Node));

        if (new_node == NULL){
            printf("Not enough space .\n");
            exit(0);
        }

        new_node -> x = num;
        new_node -> next = NULL;

        if (*root == NULL){
            *root = new_node;
        }
        else{
            curr -> next = new_node;
        }
        curr = new_node;
    }
    fclose(fptr);
}

void show(Node* root){
    Node* curr = root;
    while (curr != NULL){
        printf("%d ", curr -> x);
        curr = curr -> next;
    }
}

int find_min(Node* root){
    int minima = root -> x;
    Node* curr = root;
    while (curr != NULL){
        if (curr -> x < minima){
            minima = curr -> x;
        }
        curr = curr -> next;
    }

    return minima;
}

int find_max(Node* root){
    int maxima = root -> x;
    Node* curr = root;
    while (curr != NULL){
        if (curr -> x > maxima){
            maxima = curr -> x;
        }
        curr = curr -> next;
    }

    return maxima;
}

void pop(Node** root, int value){
    if (*root == NULL){
        return;
    }

    Node* curr = *root;
    Node* prev = NULL;
    while (curr != NULL){
        if (curr -> x == value){
            Node* tmp = curr;
            if (prev == NULL){
                *root = curr -> next;
            }
            else{
                prev -> next = curr -> next;
            }
            free(tmp);
            return;
        }
        prev = curr;
        curr = curr -> next;
    }
}

void dealloc(Node** root){
    Node* curr = *root;
    while (curr != NULL){
        Node* tmp = curr;
        curr = curr -> next;
        free(tmp);
    }
    *root = NULL;
}
