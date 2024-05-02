#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char telNo[11];
    char surName[20];
}Node;

int main()
{
    FILE* fptr = fopen("vals.txt", "r");

    if (fptr == NULL){
        printf("No such file .\n");
        exit(0);
    }

    char tel[11], lastName[20];
    int len = 0;
    while (fscanf(fptr, "%s %s", lastName, tel) != EOF){
        len += 1;
    }

    fseek(fptr, 0, SEEK_SET);

    Node persons[len];
    int k = 0;
    while (fscanf(fptr, "%s %s", lastName, tel) != EOF){
        strcpy(persons[k].surName, lastName);
        strcpy(persons[k].telNo, tel);
        k += 1;
    }

    printf("Type surname : ");
    scanf("%s", lastName);

    for (int i = 0; i < len; i ++){
        if (strcmp(persons[i].surName, lastName) == 0){
            printf("%s ", persons[i].telNo);
        }
    }

    fclose(fptr);
    return 0;
}
