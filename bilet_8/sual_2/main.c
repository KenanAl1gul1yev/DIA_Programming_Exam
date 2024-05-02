#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE* fptr = fopen("vals.txt", "r");

    if (fptr == NULL){
        printf("No such file .\n");
        exit(0);
    }

    char str[20];
    while (fscanf(fptr, "%s", &str) != EOF){
        for (int i = strlen(str) - 1; i >= 0 ; i--){
            printf("%c", str[i]);
        }
        putchar(' ');
    }

    fclose(fptr);
    return 0;
}
