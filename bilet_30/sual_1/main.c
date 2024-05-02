#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("n : ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++){
        printf("%d element of arr : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf(" \n");

    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            printf("%d ", arr[j]);
            if (j != i){
                printf("* ");
            }
        }
        printf(", ");
    }

    return 0;
}
