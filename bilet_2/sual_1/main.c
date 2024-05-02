#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[],int n);

void show(int arr[],int n);

int main()
{
    int n;
    printf("Enter the length of array : \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter numbers: \n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    show(arr, n);

    return 0;
}

void bubbleSort(int arr[], int n){
    int temp;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void show(int arr[],int n){
    for (int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
}

