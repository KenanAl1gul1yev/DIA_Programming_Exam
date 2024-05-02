#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int x;
}Node;

int N = 0;

void readFile(Node** root, char* name);
void show(Node* root);
void dealloc(Node** root);
void bubbleSort(Node** root);
void remove_exacts(Node** root);

int main()
{
    Node* root = NULL;

    readFile(&root, "vals.txt");
    bubbleSort(&root);
    remove_exacts(&root);
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
    if (root != NULL){
        Node* curr = root;
        for (int i = 0; i < N; i++){
            printf("%d ", curr -> x);
            curr += 1;
        }
    }
    else{
        printf("List is empty .\n");
    }
}

void dealloc(Node** root){
    if (*root != NULL){
        free(*root);
        *root = NULL;
        N = 0;
    }
}

void bubbleSort(Node** root){
    int tmp;
    for (int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if ((*root)[i].x > (*root)[j].x){
                tmp = (*root)[i].x;
                (*root)[i].x = (*root)[j].x;
                (*root)[j].x = tmp;
            }
        }
    }
}

void remove_exacts(Node** root){
    for (int i = 0; i < N; i++){
        if ((*root)[i].x == (*root)[i + 1].x){
            for (int j = i; j < N; j++){
                (*root)[j].x = (*root)[j + 1].x;
            }
            N -= 1;
            i -= 1;
        }
    }
}
