#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, tmp;
    printf("Num : ");
    scanf("%d", &num);

    int c = 0;
    tmp = num;
    while (tmp != 0){
        tmp /= 10;
        c++;
    }

    int arr[c];
    int i = c - 1;

    while (num != 0){
        arr[i] = num % 10;
        i--;
        num /= 10;
    }

    int sum = 0;
    for (int i = 0; i < c; i++){
        sum += arr[i] * (i+1);
    }

    printf("Sum : %d", sum);
    return 0;
}
