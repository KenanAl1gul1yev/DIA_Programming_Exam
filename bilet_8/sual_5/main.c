#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n;
    printf("N : ");
    scanf("%d", &n);

    int count = 0;
    int tmp = n;
    while (tmp != 0){
        count += 1;
        tmp /= 10;
    }

    int arr[count];
    int a = count - 1;
    while (n != 0){
        arr[a] = n % 10;
        a -= 1;
        n /= 10;
    }

    bool same = true;
    for (int i =0; i < count; i++){
        for (int j = 0; j < count; j++){
            if (arr[i] == arr[j] && i != j){
                same = false;
            }
        }
    }

    (same == true) ? printf("All are different .\n") : printf("Some numbers are same .\n");

    return 0;
}
