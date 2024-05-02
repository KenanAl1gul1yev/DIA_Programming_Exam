#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    FILE* fptr = fopen("vals.txt", "r");

    if (fptr == NULL){
        printf("No such file .\n");
        exit(0);
    }

    char str[40];
    bool moterize_icinde = false;
    while (fscanf(fptr, "%s", str) != EOF){
        for (int i = 0; i < strlen(str); i++){
            if (str[i] == '('){
                moterize_icinde = true;
            }
            if (str[i] == ')'){
                moterize_icinde = false;
                continue;
            }
            if (moterize_icinde == false){
                printf("%c", str[i]);
            }
        }
        if (moterize_icinde == false){
            putchar(' ');
        }
    }

    fclose(fptr);
    return 0;
}
