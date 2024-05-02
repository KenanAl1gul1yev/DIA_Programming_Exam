#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

typedef struct Node{
    char author[40];
    int year;
    int publish_date;
    struct Node* next;
}Node;

Node* hash[SIZE];

void readFile(char *name);
void show();
void dealloc();

int main(){
    readFile("vals.txt");
    show();
    dealloc();
    return 0;
}

void readFile(char *name){
    FILE* fptr = fopen(name, "r");

    if (fptr == NULL){
        printf("No such file .\n");
        exit(0);
    }

    int year, date;
    char auth[40];
    while (fscanf(fptr, "%s %d %d", &auth, &year, &date) != EOF){
        Node* new_node = malloc(sizeof(Node));

        if (new_node == NULL){
            printf("Not enough space .\n");
            exit(0);
        }

        strcpy(new_node -> author, auth);
        new_node -> year = year;
        new_node -> publish_date = date;
        new_node -> next = NULL;

        int pos = date/100;

        if (hash[pos] == NULL){
            hash[pos] = new_node;
        }
        else{
            Node* curr = hash[pos];
            while (curr -> next != NULL){
                curr = curr -> next;
            }
            curr -> next = new_node;
        }
    }

    fclose(fptr);
}

void show(){
    int num;
    printf("Type publish century you want : ");
    scanf("%d", &num);
    Node* curr = hash[num/100];
    while (curr != NULL){
        if (curr -> publish_date == num){
            printf("%d %s %d %d\n", num/100 + 1, curr -> author, curr -> year, curr -> publish_date);
        }
        curr = curr -> next;
    }
}

void dealloc(){
    for (int i = 0; i < SIZE; i++){
        Node* curr = hash[i];
        while (curr != NULL){
            Node* aux = curr;
            curr = curr -> next;
            free(aux);
        }
        hash[i] = NULL;
    }
}
