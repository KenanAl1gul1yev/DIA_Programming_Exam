#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int x;
}Node;

int N = 0;
void readFile(Node** root, char* name);
void show(Node* root);
void remove_elem(Node** root);
void dealloc(Node** root);

int main()
{
    Node* root = NULL;

    readFile(&root, "vals.txt");
    remove_elem(&root);
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

        Node new_node;
        while (fscanf(fptr, "%d", &new_node.x) != EOF){
            *root = realloc(*root, sizeof(Node) * (N + 1));

            if (*root == NULL){
                printf("Not enough space .\n");
                exit(0);
            }

            (*root)[N] = new_node;
            N += 1;
        }
    fclose(fptr);
}

void show(Node* root){
    if (root == NULL){
        printf("List is empty .\n");
        exit(0);
    }

    Node* curr = root;
    for (int i = 0; i < N; i++){
        printf("%d ", curr -> x);
        curr++;
    }
}

void remove_elem(Node** root){
    if (N == 0){
        printf("List is already empty .\n");
        exit(0);
    }

    for (int i = 0; i < N - 1; i++){
        (*root)[i] = (*root)[i + 1];
    }

    *root = realloc(*root, sizeof(Node) * (N - 2));

    if (*root == NULL){
        printf("not enough space .\n");
        exit(0);
    }

    N -= 2;
}

void dealloc(Node** root){
    if(*root != NULL){
        free(*root);
    }
    *root = NULL;
    N = 0;
}
