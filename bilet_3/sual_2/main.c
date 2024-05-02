#include <stdio.h>
#include <stdlib.h>

int main()
{
    readFile("vals.txt");
    return 0;
}

void readFile(char *name){
    FILE* fptr = fopen(name, "r");

    int row_num, p1, p2, p3;
    while ()

    fclose(fptr);
}
