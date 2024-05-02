#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int x;
}Node;

int n_pos = 0;
int n_neg = 0;

void readFile(Node** positives, Node** negatives, char* name);
int append(Node** root, int val, int n);
void show(Node* root, int n);
int dealloc(Node** root, int n);
int pop(Node** root, int val, int n);
void remove_elems(Node** positives, Node** negatives);

int main(){
    Node* positives = NULL;
    Node* negatives = NULL;

    readFile(&positives, &negatives, "vals.txt");

    remove_elems(&positives, &negatives);

    show(positives, n_pos);
    //show(negatives, n_neg);

    n_pos = dealloc(&positives, n_pos);
    n_neg = dealloc(&negatives, n_neg);
    return 0;
}

void readFile(Node** positives, Node** negatives, char* name){
    FILE* fptr = fopen(name, "r");

    if (fptr == NULL){
        printf("No such file .\n");
        exit(0);
    }

    int num;
    while (fscanf(fptr, "%d", &num) != EOF){
        if (num < 0){
            n_neg = append(negatives, num, n_neg);
        }
        else{
            n_pos = append(positives, num, n_pos);
        }
    }
    fclose(fptr);
}

int append(Node** root, int val, int n){
    *root = realloc(*root, sizeof(Node) * (n + 1));

    if (*root == NULL){
        printf("Not enough space .\n");
        exit(0);
    }

    Node new_node;
    new_node.x = val;
    (*root)[n] = new_node;

    n += 1;
    return n;
}

void show(Node* root, int n){
    if (root == NULL){
        printf("List is empty");
        exit(0);
    }

    Node* curr = root;
    for (int i = 0; i < n; i++){
        printf("%d ", curr -> x);
        curr += 1;
    }
}

int dealloc(Node** root, int n){
    if (*root != NULL){
        free(*root);
        *root = NULL;
        n = 0;
    }
    return n;
}

int pop(Node** root, int val, int n){
    if (*root == NULL){
        exit(0);
    }

    for (int i = 0; i < n; i++){
        if ((*root)[i].x == val){
            for (int j = i; j < n; j++){
                (*root)[j].x = (*root)[j + 1].x;
            }
            n -= 1;
            *root = realloc(*root, sizeof(Node) * n);
        }
    }
    return n;
}

void remove_elems(Node** positives, Node** negatives){
    for (int i = 0; i < n_neg; i++){
        n_pos = pop(positives, abs((*negatives)[i].x), n_pos);
    }
}
