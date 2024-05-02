#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* fptr = fopen("vals.txt", "r");

    if (fptr == NULL){
        printf("No such file .\n");
        exit(0);
    }

    char str[100];
    int len = 0;
    while (fscanf(fptr, "%s", str) != EOF){
        len += 1;
    }
    fseek(fptr, 0, SEEK_SET);

    char elements[len][100];
    int k = 0;
    while (fscanf(fptr, "%s", str) != EOF){
        strcpy(elements[k], str);
        k += 1;
    }

    for (int i = 0; i < len; i++){
        char tmp[100];
        for (int j = i + 1; j < len; j++){
            if (strlen(elements[i]) < strlen(elements[j])){
                strcpy(tmp, elements[i]);
                strcpy(elements[i], elements[j]);
                strcpy(elements[j], tmp);
            }
        }
    }

    for (int i = 0; i < len; i++){
        if (elements[i][0] > '0' && elements[i][0] < '9'){
            for (int j = 0; j < strlen(elements[i]); j++){
                printf("%c", elements[i][j]);
            }
            break;
        }
    }
    fclose(fptr);
    return 0;
}
