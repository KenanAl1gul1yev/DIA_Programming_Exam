#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("N : ");
    scanf("%d", &n);

    int len = 0;
    int aux = n; //auxiliary - komekci
    while (aux != 0){
        len += 1;
        aux /= 10;
    }

    int arr[len];

    int a = len -1;
    while (n != 0){
        arr[a] = n % 10;
        a -= 1;
        n /= 10;
    }

    for (int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
