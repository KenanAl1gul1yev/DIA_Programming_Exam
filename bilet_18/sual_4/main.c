#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char str[50];
}Node;

int N = 0;

void readFile(Node** root, char* name);
void show(Node* root);
void dealloc(Node** root);
void remove_elem(Node** root);

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
    while (fscanf(fptr, "%s", new_node.str) != EOF){
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
        printf("%s ", curr -> str);
        curr += 1;
    }
}

void dealloc(Node** root){
    if (*root != NULL){
        free(*root);
        N = 0;
        *root = NULL;
    }
}

void remove_elem(Node** root){
    for (int i = 0; i < N; i++){
        if ((*root)[i].str[strlen((*root)[i].str) - 1] >= '0' && (*root)[i].str[strlen((*root)[i].str) - 1] <= '9'){
            for (int j = i; j < N; j++){
                strcpy((*root)[j].str, (*root)[j + 1].str);
            }

            *root = realloc(*root, sizeof(Node) * (N - 1));

            if (*root == NULL){
                printf("Not enough space .\n");
                exit(0);
            }
            i -= 1;

            N -=1;
        }
    }
}
