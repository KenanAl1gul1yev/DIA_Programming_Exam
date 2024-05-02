#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int x;
    struct Node* next;
}Node;


void readFile(Node** root, char *name);
void add_after(Node** root1, Node** root2, char *name);
void show(Node* root);

int main()
{
    Node* L = NULL;
    Node* M = NULL;

    readFile(&L, "L.txt");
    add_after(&L, &M, "M.txt");
    show(L);

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
    while (fscanf(fptr, "%d", &num) != EOF){
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

void add_after(Node** root1, Node** root2, char *name){
    readFile(root2, name);
    Node* curr = *root1;
    while (curr -> next != NULL){
        curr = curr -> next;
    }

    curr -> next = *root2;
}
