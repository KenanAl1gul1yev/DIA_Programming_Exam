#include <stdio.h>
#include <stdlib.h>

void readFile(char *name);

int arr[12][3];

int main()
{
    readFile("vals.txt");
    show();
    return 0;
}

void readFile(char *name){
    FILE* fptr = fopen(name, "r");

    if (fptr == NULL){
        printf("No such file .\n");
        exit(0);
    }

    int row_num, m1, m2, m3;
    int i = 0;
    while (fscanf(fptr, "%d %d %d %d", &row_num, &m1, &m2, &m3) != EOF){
        arr[i][0] = m1;
        arr[i][1] = m2;
        arr[i][2] = m3;
        i ++;
    }

    fclose(fptr);
}

void show(){

    for (int i = 0; i < 12; i++){
        int sum = 0;
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++){
            printf("%d ",arr[i][j]);
            sum += arr[i][j];
        }
        printf("    Sum : %d\n", sum);
    }
}
