#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int x;
}Node;

int N = 0;

void readFile(Node** root, char* name);
void show(Node* root);
void dealloc(Node** root);
void insert_elem(Node** root, int L, int M);

int main()
{
    Node* arr = NULL;

    readFile(&arr, "vals.txt");
    insert_elem(&arr, 10, 11);
    show(arr);
    dealloc(&arr);

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
    for (int i = 0; i < N; i ++){
        printf("%d ", curr -> x);
        curr ++;
    }
}

void dealloc(Node** root){
    if (*root != NULL){
        free(*root);
        N = 0;
        *root = NULL;
    }
}

void insert_elem(Node** root, int L, int M){
    *root = realloc(*root, sizeof(Node) * (N + 2));

    if (*root == NULL){
        printf("Not enough space .\n");
        exit(0);
    }

    int aux[N / 2];
    for (int i = N / 2, j = 0; i < N; i++, j++){
        aux[j] = (*root)[i].x;
    }

    (*root)[N / 2].x = L;
    (*root)[(N / 2) + 1].x = M;
    for (int i = N / 2 + 2, j = 0; i < N + 2; i++, j++){
        (*root)[i].x = aux[j];
    }

    N += 2;
}
