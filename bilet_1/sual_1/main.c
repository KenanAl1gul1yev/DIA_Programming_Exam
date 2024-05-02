#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findMax(int arr[], int n){
    int temp = 0;
    for (int i = 0; i < n; i++ ){
        for (int j = i + 1; j < n; j++){
            if (arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                break;
            }
        }
    }
    return arr[n - 1];
}

void replaceNums(int arr[], int n, int maks){
    for (int i = 0; i < n; i++){
            if (abs(arr[i]) > maks){
                arr[i] = 0;
            }
    }
}

void show(int arr[], int n){
     for (int i = 0; i < n; i++){
        printf("%d\n", arr[i]);
     }
}

int main()
{
    int n, maks;
    printf("Len : \n");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++){
        printf("element %d\n", i + 1);
        scanf("%d", &arr[i]);
    }

    maks = findMax(arr, n);
    replaceNums(arr, n, maks);
    show(arr, n);

    return 0;
}
