#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(char *name);

char str_little[100] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
char str_big[100];

int main()
{
    readFile("vals.txt");
    return 0;
}

void readFile(char *name){
    FILE* fptr = fopen(name, "r");

    char str_tmp[100];

    while (fscanf(fptr, "%s", str_tmp) != EOF){
            if (strlen(str_little) > strlen(str_tmp)){
                strcpy(str_little, str_tmp);
            }
            if(strlen(str_big) < strlen(str_tmp)) {
                strcpy(str_big, str_tmp);
            }
    }

    printf("Big : %s\nLittle : %s\n", str_big, str_little);

    fclose(fptr);
}
