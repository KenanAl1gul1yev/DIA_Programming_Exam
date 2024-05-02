#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int x;
    struct Node* next;
}Node;

void append(Node** root, int val);
void show(Node* root);
void dealloc(Node** root);
void readFile(Node** root, char *name);

int main()
{
    Node* root = NULL;
    readFile(&root, "vals.txt");
    append(&root, 15);
    append(&root, -20);
    append(&root, -15);
    bubbleSort(&root);
    show(root);
    dealloc(&root);

    return 0;
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

void readFile(Node** root, char *name){
    FILE* fptr = fopen(name, "r");

    if (fptr == NULL){
        printf("No such file .\n");
        exit(0);
    }

    int num;
    Node* curr = *root;
    while (fscanf(fptr, "%d", &num) != EOF){
        Node* tmp = malloc(sizeof(Node));

        if (tmp == NULL){
            exit(0);
        }

        tmp -> x = num;
        tmp -> next = NULL;

        if(*root == NULL){
            *root = tmp;
        }
        else{
            curr -> next = tmp;
        }
        curr = tmp;
    }

    fclose(fptr);
}

void bubbleSort(Node** root){
    int tmp;
    for (Node* i = *root; i -> next != NULL; i = i -> next){
        for (Node* j = i -> next; j != NULL; j = j -> next){
            if (i -> x > j -> x){
                tmp = i -> x;
                i -> x = j -> x;
                j -> x = tmp;
            }
        }
    }
}
