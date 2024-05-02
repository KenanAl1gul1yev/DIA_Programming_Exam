#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int x;
}Node;

int N = 0;

void readFile(Node** root, char* name);
void show(Node* root);
void add_elem(Node** root, int L, int M);
void dealloc(Node** root);

int main()
{
    Node* root = NULL;
    readFile(&root, "vals.txt");
    add_elem(&root, 15, 16);
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
    Node* curr = root;
    for (int i = 0; i < N; i++){
        printf("%d ", curr -> x);
        curr += 1;
    }
}

void add_elem(Node** root, int L, int M){
    *root = realloc(*root, sizeof(Node) * (N + 2));

    if (*root == NULL){
        printf("Not enough space .\n");
        exit(0);
    }

    int aux[N];
    for (int i = 0; i < N; i++){
        aux[i] = (*root)[i].x;
    }

    Node new_node1;
    Node new_node2;

    new_node1.x = L;
    new_node2.x = M;

    (*root)[0] = new_node1;
    (*root)[1] = new_node2;

    for (int i = 2, j = 0; i < N + 2; i++, j++){
        (*root)[i].x = aux[j];
    }
    N += 2;
}

void dealloc(Node** root){
    if (*root != NULL){
        free(*root);
        N = 0;
        *root = NULL;
    }
}
