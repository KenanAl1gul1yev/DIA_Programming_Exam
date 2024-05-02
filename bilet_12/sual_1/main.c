#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m;
    printf("M : ");
    scanf("%d", &m);

    int arr[m];
    for (int i = 0 ;i < m; i++){
        printf("Element %d : ", i);
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < m; i++){
        if (arr[i] < i) sum += arr[i];
    }

    printf("Sum : %d", sum);

    return 0;
}
