#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, column;
    printf("Row :");
    scanf("%d", &row);
    printf("Column : ");
    scanf("%d", &column);
    int arr[row][column];

    for (int i = 0; i < row; i ++){
        for (int j = 0; j < column; j++){
            printf("Element %d %d : ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < column; i++){
        for (int j = 0 ; j < row; j++){
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }

    return 0;
}
