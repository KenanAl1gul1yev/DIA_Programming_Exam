#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("N : ");
    scanf("%d", &n);

    int count = 0;
    while (n != 0){
        if (n % 10 == 0){
            count += 1;
        }
        n /= 10;
    }

    printf("Count : %d", count);

    return 0;
}
