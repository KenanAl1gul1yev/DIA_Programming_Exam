#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char x;
    struct Node* next;
}Node;

int N = 0;

void readFile(Node** root, char* name);
void show(Node* root);
void dealloc(Node** root);
void pop(Node** root, int index);
void remove_elem(Node** root);

int main()
{
    Node* root = NULL;

    readFile(&root, "vals.txt");
    remove_elem(&root);
    show(root);
    printf("\nN : %d", N);
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
    char symbol;
    while (fscanf(fptr, "%c", &symbol) != EOF){
        if (symbol == ' '){
            continue;
        }
        Node* new_node = malloc(sizeof(Node));

        if (new_node == NULL){
            printf("Not enough space .\n");
            exit(0);
        }

        N += 1;
        new_node -> x = symbol;
        new_node -> next = NULL;

        if (*root == NULL){
            *root = new_node;
        }
        else{
            curr -> next = new_node;
        }
        curr = new_node;
    }

    fclose(fptr);
}

void show(Node* root){
    Node* curr = root;
    while (curr != NULL){
        printf("%c ", curr -> x);
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
    N = 0;
}

void pop(Node** root, int index){
    if (*root == NULL){
        return;
    }

    Node* curr = *root;
    Node* prev = NULL;
    int n = 0;
    while (curr -> next != NULL){
        if (n == index){
            if (prev == NULL){
                *root = curr -> next;
            }
            else{
                prev -> next = curr -> next;
            }
            N -= 1;
            return;
        }
        n += 1;
        prev = curr;
        curr = curr -> next;
    }
}

void remove_elem(Node** root){
    for (int i = 0; i < N; i++){
        if ((*root) -> x != '@'){
            pop(root, i);
        }
        else{
            return;
        }
        i -= 1;
    }
}
