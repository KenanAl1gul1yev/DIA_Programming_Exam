#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int x;
    struct Node* next;
}Node;

int N = 0;

void readFile(Node** root, char* name);
void show(Node* root);
void dealloc(Node** root);
void bubbleSort(Node** root);
void pop(Node** root, int index);
void remove_elem(Node** root);

int main()
{
    Node* root = NULL;

    readFile(&root, "vals.txt");
    bubbleSort(&root);
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

    Node* curr = *root;
    int num;
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
        N += 1;
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

void pop(Node** root, int index){
    if (*root == NULL){
        exit(0);
    }

    Node* curr = *root;
    Node* prev = NULL;
    int n = 0;

    while (curr != NULL){
        if (n == index){
            if (prev == NULL){
                *root = curr -> next;
            }
            else{
                prev -> next = curr -> next;
            }
            N -= 1;
            free(curr);
            return;
        }
        n += 1;
        prev = curr;
        curr = curr -> next;
    }
}

void remove_elem(Node** root){
    for (int i = 1; i < N - 1; i++){
        pop(root, i);
        i -= 1;
    }
}
