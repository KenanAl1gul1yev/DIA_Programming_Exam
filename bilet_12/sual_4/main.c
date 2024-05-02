#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int x;
}Node;


int n_neg = 0;
int n_pos = 0;

void readFile(Node** negatives, Node** positives, char* name);
int append(Node** root, int val, int n);
void show(Node* root, int n);
int dealloc(Node** root, int n);

int main()
{
    Node* negatives = NULL;
    Node* positives = NULL;

    readFile(&negatives, &positives, "vals.txt");
    printf("positives : ");
    show(positives, n_pos);
    printf("\nnegatives : ");
    show(negatives, n_neg);

    n_pos = dealloc(&positives, n_pos);
    n_neg = dealloc(&negatives, n_neg);

    return 0;
}

void readFile(Node** negatives, Node** positives, char* name){
    FILE* fptr = fopen(name, "r");

    if (fptr == NULL){
        printf("No such file .\n");
        exit(0);
    }

    int num;
    while (fscanf(fptr, "%d", &num) != EOF){
            if (num < 0) n_neg = append(negatives, num, n_neg);
            else n_pos = append(positives, num, n_pos);
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
    if (root != NULL){
        Node* curr = root;
        for (int i = 0; i < n; i ++){
            printf("%d ", curr -> x);
            curr++;
        }
    }
    else{
        printf("List is empty .\n");
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
