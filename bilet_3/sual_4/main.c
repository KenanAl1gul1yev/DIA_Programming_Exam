#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    double x;
    struct Node* next;
}Node;

void readFile(Node** root);
void show(Node* root);
//void addValue(Node** root);
void append(Node** root, double val);
void dealloc(Node** root);

int main()
{
    Node* root = NULL;
    readFile(&root);
    //addValue(&root);
    show(root);

    return 0;
}

//void readFile(Node** root){
//    FILE* fptr = fopen("vals.txt", "r");
//
//    if (fptr == NULL){
//        printf("No such file .\n");
//       exit(0);
//    }
//
//    double num;
//    Node* curr = *root;
//    while (fscanf(fptr, "%lf", &num) != EOF){
//        Node* tmp = malloc(sizeof(Node));
//
//        if (tmp == NULL){
//            exit(0);
//        }
//
//        tmp -> x = num;
//        tmp -> next = NULL;
//
//        if (*root == NULL){
//            *root = tmp;
//       }
//        else{
//            curr -> next = tmp;
//        }
//        curr = tmp;
//    }
//
//    fclose(fptr);
//}

void readFile(Node** root){
    FILE* fptr = fopen("vals.txt", "r");

    if (fptr == NULL){
        printf("No such file . \n");
        exit(0);
    }

    double val;
    while (fscanf(fptr, "%lf", &val) != EOF){
        if(val < 0){
            append(root, 3.14);
        }
        append(root, val);
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

//void addValue(Node** root){
//    if (*root == NULL){
//        exit(0);
//    }
//
//    Node* curr = *root;
//    while (curr -> next != NULL){
//        Node* new_node = malloc(sizeof(Node));
//
//        if (new_node == NULL){
//            exit(0);
//        }
//
//        new_node -> x = 3.14;
//        new_node -> next = NULL;
//
//        if(curr -> next && curr -> next -> x < 0){
//            new_node -> next = curr -> next;
//            curr -> next = new_node;
//            curr = new_node;
//       }
//       curr = curr -> next;
//
//        free(new_node);
//    }
//}

void append(Node** root, double val){
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

void dealloc(Node** root){
    Node* curr = *root;
    while (curr != NULL){
        Node* aux = curr;
        curr = curr -> next;
        free(aux);
    }
    *root = NULL;
}
