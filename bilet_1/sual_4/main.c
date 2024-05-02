#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    double x;
    struct Node* next;
}Node;

void readFile(Node** root);
void show(Node* root);
void del(Node** root);

int main()
{
    Node* root = NULL;
    readFile(&root);
    del(&root);
    dealloc(&root);
    show(root);
    return 0;
}

void readFile(Node** root){
    FILE* fptr = fopen("vals.txt", "r");

    if (fptr == NULL){
        printf("There is no such file .\n");
    }

    Node* curr = *root;

    double num;

    while(fscanf(fptr, "%lf", &num) != EOF){
        Node* tmp = malloc(sizeof(Node));

        if(malloc == NULL){
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

void show(Node* root){
    Node* curr = root;

    while (curr != NULL){
        printf("%lf ", curr -> x);
        curr = curr -> next;
    }
}

void del(Node** root){
    Node* prev = NULL;

    Node* curr = *root;
    while (curr -> next != NULL){
        if ((curr -> next) && curr -> next -> x == 3.14){
            if (prev == NULL){
                *root = curr -> next;
            }
            else{
                prev -> next = curr -> next;
            }
        }
        prev = curr;
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
