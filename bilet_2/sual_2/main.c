#include <stdio.h>
#include <stdlib.h>



int main()
{
    int arr[15];

    FILE* fptr = fopen("vals.txt", "r");

    int line_num, p1, p2, p3, i = 0;

    while (fscanf(fptr, "%d %d %d %d", &line_num, &p1, &p2, &p3) != EOF){
        arr[i] = (p1 + p2 + p3) / 3;
        i += 1;
    }

    fclose(fptr);

    for (int i = 0; i < 15; i++){
        printf("player_%d : %d\n", i + 1, arr[i]);
    }

    return 0;
}
