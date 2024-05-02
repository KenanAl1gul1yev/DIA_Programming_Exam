#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num;
    printf("Num :");
    scanf("%d", &num);

    int sum = 0;
    int i = 0;
    while (num != 0){
        sum += (num % 10) * pow(2, i);
        num /= 10;
        i += 1;
    }

    printf("%d(10)\n", sum);

    return 0;
}
