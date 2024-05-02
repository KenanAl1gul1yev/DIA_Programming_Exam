#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int x;
    struct Node* next;
}Node;

void readFile(Node** pos, Node** neg, char*name);
void show(Node* root);
void dealloc(Node** root);
void append(Node** root, int val);
int findLen(Node** root);

int main()
{
    Node* pos = NULL;
    Node* neg = NULL;

    readFile(&pos, &neg, "vals.txt");

    (findLen(&neg) > findLen(&pos)) ? show(neg) : show(pos);

    dealloc(&pos);
    dealloc(&neg);

    return 0;
}

void readFile(Node** pos, Node** neg, char *name){
    FILE* fptr = fopen(name, "r");

    if (fptr == NULL){
        printf("No such file .\n");
        exit(0);
    }

    int num;
    while (fscanf(fptr, "%d", &num) != EOF){
        if (num < 0){
            append(neg, num);
        }
        else{
            append(pos, num);
        }
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
        printf("Not enough space .\n");
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

int findLen(Node** root){
    Node* curr = *root;
    int len = 0;
    while (curr != NULL){
        len += 1;
        curr = curr -> next;
    }

    return len;
}
