#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int arr[] = {1, 4, 9, 15, 26, 81, 101};
    int len = sizeof(arr) / sizeof(int);

    for (int i = 0; i < len; i++){
        for (int j = 1; j <= sqrt(arr[i]); j++){
            if (j * j == arr[i]){
                printf("%d ", i);
            }
        }
    }

    return 0;
}
