#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int x;
    struct Node* next;
}Node;

void readFile(Node** root, char *name);
void show(Node* root);
void dealloc(Node** root);
void append(Node** root, int val);

int main(){
    Node* root = NULL;
    readFile(&root, "vals.txt");
    append(&root, 4);
    append(&root, 4);
    del(&root, 0, 5);
    show(root);
    dealloc(&root);

    return 0;
}

void readFile(Node** root, char *name){
    FILE* fptr = fopen(name, "r");

    if (fptr == NULL){
        printf("There is no such file .\n");
        exit(0);
    }

    int num;
    Node* curr = *root;
    while(fscanf(fptr, "%d", &num) != EOF){
        Node* tmp = malloc(sizeof(Node));

        if (tmp == NULL){
            exit(0);
        }

        tmp -> x = num;
        tmp -> next = NULL;

        if (*root == NULL){
            *root = tmp;
        }
        else{
            curr -> next = tmp;
        }
        curr = tmp;
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

void dealloc(Node** root){
    Node* curr = *root;
    while (curr != NULL){
        Node* aux = curr;
        curr = curr -> next;
        free(aux);
    }
    *root = NULL;
}

void append(Node** root, int val){
    Node* new_node = malloc(sizeof(Node));

    if (new_node == NULL){
        exit(0);
    }

    new_node -> x = val;
    new_node -> next = NULL;

    if (*root == NULL){
        *root = new_node;
        return;
    }

    Node* curr = *root;
    while (curr -> next != NULL){
        curr = curr -> next;
    }
    curr -> next = new_node;
}

void del(Node** root, int a, int b){
    Node* curr = *root;
    Node* prev = NULL;
    while (curr != NULL){
        if (curr -> x >= a && curr -> x <= b){
            prev -> next = curr -> next;
        }
        else{
            prev = curr;
        }

        curr = curr -> next;
    }
}
