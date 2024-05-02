#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int arr[11][4];

void readFile(char *name);
int min_children();

int main()
{
    readFile("vals.txt");
    printf("Min : %d", min_children());

    return 0;
}

void readFile(char *name){
    FILE* fptr = fopen(name, "r");

    if (fptr == NULL){
        printf("No such file .\n");
        exit(0);
    }

    int grade, a, b, c, d;
    int i = 0;
    while (fscanf(fptr, "%d %d %d %d %d", &grade, &a, &b, &c, &d) != EOF){
        arr[i][0] = a;
        arr[i][1] = b;
        arr[i][2] = c;
        arr[i][3] = d;
        i += 1;
    }
    fclose(fptr);
}

int min_children(){
    int minima = MAX;
    int grd;

    for(int i = 0; i < 11; i++){
        int tmp = 0;
        for (int j = 0; j < 4; j++){
            tmp+= arr[i][j];
        }
        if(tmp < minima) {
            minima = tmp;
            grd = i;
            }
    }

    return grd + 1;
}
